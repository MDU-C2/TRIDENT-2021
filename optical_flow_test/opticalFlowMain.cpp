#include <iostream>
#include <math.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>
#include <opencv2/optflow.hpp>
#include <sys/stat.h>

#include <opencv2/ml.hpp>
#include <opencv2/core/utility.hpp>

#define LK_DENSE 0
#define FARNEBACK 1
#define RLOF 2

using namespace cv;
using namespace std;


int lucas_kanade(const string& filename, bool save)
{
    VideoCapture capture(filename);
    if (!capture.isOpened()){
        //error in opening the video input
        cerr << "Unable to open file!" << endl;
        return 0;
    }
    // Create some random colors
    vector<Scalar> colors;
    RNG rng;
    for(int i = 0; i < 100; i++)
    {
        int r = rng.uniform(0, 256);
        int g = rng.uniform(0, 256);
        int b = rng.uniform(0, 256);
        colors.push_back(Scalar(r,g,b));
    }
    Mat old_frame, old_gray;
    vector<Point2f> p0, p1;
    // Take first frame and find corners in it
    capture >> old_frame;
    cvtColor(old_frame, old_gray, COLOR_BGR2GRAY);
    goodFeaturesToTrack(old_gray, p0, 100, 0.3, 7, Mat(), 7, false, 0.04);
    // Create a mask image for drawing purposes
    Mat mask = Mat::zeros(old_frame.size(), old_frame.type());
    int counter = 0;
    while(true){
        Mat frame, frame_gray;
        capture >> frame;
        if (frame.empty())
            break;
        cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
        // calculate optical flow
        vector<uchar> status;
        vector<float> err;
        TermCriteria criteria = TermCriteria((TermCriteria::COUNT) + (TermCriteria::EPS), 10, 0.03);
        calcOpticalFlowPyrLK(old_gray, frame_gray, p0, p1, status, err, Size(15,15), 2, criteria);
        vector<Point2f> good_new;
        for(uint i = 0; i < p0.size(); i++)
        {
            // Select good points
            if(status[i] == 1) {
                good_new.push_back(p1[i]);
                // draw the tracks
                line(mask,p1[i], p0[i], colors[i], 2);
                circle(frame, p1[i], 5, colors[i], -1);
            }
        }
        Mat img;
        add(frame, mask, img);
        if (save) {
            string save_path = "./optical_flow_frames/frame_" + to_string(counter) + ".jpg";
            imwrite(save_path, img);
        }
        imshow("flow", img);
        int keyboard = waitKey(25);
        if (keyboard == 'q' || keyboard == 27)
            break;
        // Now update the previous frame and previous points
        old_gray = frame_gray.clone();
        p0 = good_new;
        counter++;
    }
}


void dense_optical_flow(string filename, bool save, bool to_gray, int method)
{
    // VideoCapture 
    // capture(samples::findFile(filename));
    VideoCapture capture(filename);
    if (!capture.isOpened()) {
        //error in opening the video input
        cerr << "Unable to open file!" << endl;
    }
    Mat frame1, prvs;
    capture >> frame1;
    if (to_gray)
        cvtColor(frame1, prvs, COLOR_BGR2GRAY);
    else
        prvs = frame1;

    int nRows = frame1.rows;
    int nCols = frame1.cols;
    Point2i pt1, pt2;
    pt1 = Point2i(nCols/2, nRows/2);

    int counter = 0;
    while (true) {
        Mat frame2, next;
        capture >> frame2;
        if (frame2.empty())
            break;
            
        if (to_gray)
            cvtColor(frame2, next, COLOR_BGR2GRAY);
        else
            next = frame2;
        Mat flow(prvs.size(), CV_32FC2);

        switch (method)
        {
        case LK_DENSE:
            // Dense Lucas-Kanade algorithm
            optflow::calcOpticalFlowSparseToDense(prvs, next, flow);
            break;
        case FARNEBACK:
            calcOpticalFlowFarneback(prvs, next, flow, 0.5, 3, 15, 3, 5, 1.2, 0);
            break;
        case RLOF:
            optflow::calcOpticalFlowDenseRLOF(prvs, next, flow);
            break;
        default:
            cout << "ERROR NO OPTICAL FLOW ALGORITHM \n";
            break;
        }

        // visualization
        Mat flow_parts[2];
        split(flow, flow_parts);
        Mat magnitude, angle, magn_norm;
        cartToPolar(flow_parts[0], flow_parts[1], magnitude, angle, true);
        Scalar avgAngle = mean(angle);
        normalize(magnitude, magn_norm, 0.0f, 1.0f, NORM_MINMAX);
        angle *= ((1.f / 360.f) * (180.f / 255.f));

        // Scalar avgAngle = angle.at<uchar>(Point2i(pt1));
        Scalar avgMagn = mean(magn_norm);
        int scale = 90;
        pt2 = pt1 + Point2i(scale * avgMagn[0] * cos(avgAngle[0] * CV_PI / 180), scale * avgMagn[0] * sin(avgAngle[0] * CV_PI / 180));
        cout << "pt1 = " << pt1 << ", pt2 = " << pt2 << ", angle = " << avgAngle[0] << ", magnitude = " << avgMagn[0] << endl;


        //build hsv image
        Mat _hsv[3], hsv, hsv8, bgr;
        _hsv[0] = angle;
        _hsv[1] = Mat::ones(angle.size(), CV_32F);
        _hsv[2] = magn_norm;
        merge(_hsv, 3, hsv);
        hsv.convertTo(hsv8, CV_8U, 255.0);
        cvtColor(hsv8, bgr, COLOR_HSV2BGR);
        // draw arrow on video image
        arrowedLine(frame2, pt1, pt2, Scalar(130,100,100), 5);
        // finding max values
        double maxA, maxM, max1, max2;
        minMaxLoc(angle, 0, &maxA, 0, 0 );
        minMaxLoc(magnitude, 0, &maxM, 0, 0 );
        minMaxLoc(flow_parts[0], 0, &max1, 0, 0 );
        minMaxLoc(flow_parts[1], 0, &max2, 0, 0 );
        // show video and optical flow result
        imshow("frame", frame2);
        imshow("flow", bgr);
        imshow("magnitude", magnitude/20);
        imshow("angle", angle);
        imshow("flow_parts[0]", flow_parts[0]/20);
        imshow("flow_parts[1]", flow_parts[1]/20);
        // cout << "image types:" << endl << "   magnitude: " << maxM << endl << "   angle: " << maxA << endl << "   flow_parts[0]: " << max1 << endl << "   flow_parts[1]: " << max2 << endl;
        int keyboard = waitKey(30);
        // quit 
        if (keyboard == 'q' || keyboard == 27)
            break;
        prvs = next;
        counter++;
        waitKey(0);
    }
}


int main(int argc, char** argv)
{
    // Mat im = imread("/home/Documents/TRIDENT-2021/seafloor.bmp");
    // namedWindow("window");
    // imshow("window", im);
    // waitKey(0);


    string filename = "../Naiad_in_trondheim_firstTrial_pt1_2.mp4";
    bool save = true;
    bool to_gray = true;        // FARNEBACK-true, RLOF-false
    // lucas_kanade(filename, save);
    dense_optical_flow(filename, save, to_gray, FARNEBACK);        // For last argument, select from LK_DENSE, FARNEBACK, RLOF

    return 0;
}