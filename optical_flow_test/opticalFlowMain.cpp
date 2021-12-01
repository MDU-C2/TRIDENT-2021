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

// #define WITHOUT_NUMPY
// #include "matplotlib-cpp/matplotlibcpp.h"
// #include "/usr/include/python3.6m/object.h"

#define LK_DENSE 0
#define FARNEBACK 1
#define RLOF 2

using namespace cv;
using namespace std;
// namespace plt = matplotlibcpp;


Mat getCurl(Mat fx, Mat fy)
{
    int nRows = fx.rows;
    int nCols = fx.cols;

    Mat dfydx = fy(cv::Range(0, nRows-1), cv::Range(1, nCols)) - fy(cv::Range(0, nRows-1), cv::Range(0, nCols-1));
    Mat dfxdy = fx(cv::Range(1, nRows), cv::Range(0, nCols-1)) - fx(cv::Range(0, nRows-1), cv::Range(0, nCols-1));
    return dfydx - dfydx.mul(dfxdy) - dfxdy;   // = curl
}

void fullLine(Mat *img, Point a, float angle, Scalar colour)
{
    float n = 1000;
    double slope = tan(angle);

    Point p(a.x + n, a.y+n*slope), q(a.x - n, a.y-n*slope);

    line(*img, p, q, colour);
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
            // optflow::calcOpticalFlowSparseToDense(prvs, next, flow);
            break;
        case FARNEBACK:
            calcOpticalFlowFarneback(prvs, next, flow, 0.5, 3, 15, 3, 5, 1.2, 0);
            break;
        case RLOF:
            // optflow::calcOpticalFlowDenseRLOF(prvs, next, flow);
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


        // Calculate rotation center
        int n = 2;      // number of rows and cols angle image will be averaged into
        Mat normals = Mat::zeros(angle.size(), CV_32FC1);
        for (int r = 0; r < n; r++)     // rows
            for (int c = 0; c < n; c++) // cols
            {
                Scalar tempAvgAng = mean(angle(Range(r*nRows/n, (r+1)*nRows/n), Range(c*nCols/n, (c+1)*nCols/n)));
                fullLine(&normals, Point((c+0.5)*nCols/n, (r+0.5)*nRows/n), tempAvgAng[0]+90, Scalar(130,100,100));
                circle(normals, Point((c+0.5)*nCols/n, (r+0.5)*nRows/n), 6, Scalar(100,100,100));
                imshow("normals", normals);
            }
        

        // build hsv image
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
        // double maxA, maxM, max1, max2;
        // minMaxLoc(angle, 0, &maxA, 0, 0 );
        // minMaxLoc(magnitude, 0, &maxM, 0, 0 );
        // minMaxLoc(flow_parts[0], 0, &max1, 0, 0 );
        // minMaxLoc(flow_parts[1], 0, &max2, 0, 0 );

        // create curl image
        Mat curl = getCurl(flow_parts[0], flow_parts[1]);

        // show video and optical flow result
        imshow("frame", frame2);
        imshow("flow", bgr);
        imshow("magnitude", magnitude/20);
        imshow("angle", angle);
        imshow("flow_parts[0]", flow_parts[0]/20);
        imshow("flow_parts[1]", flow_parts[1]/20);
        imshow("curl", curl);
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
    // --------------- TEST ----------------------------------------------------------------------------
    // Mat im = imread("/home/Documents/TRIDENT-2021/seafloor.bmp");
    // namedWindow("window");
    // imshow("window", im);
    // waitKey(0);

    // ---------------- MATPLOTLIB STUFF ------------------------------------------------------------------
    // u and v are respectively the x and y components of the arrows we're plotting
    // std::vector<int> x, y, u, v;
    // for (int i = -5; i <= 5; i++) {
    //     for (int j = -5; j <= 5; j++) {
    //         x.push_back(i);
    //         u.push_back(-i);
    //         y.push_back(j);
    //         v.push_back(-j);
    //     }
    // }

    // plt::quiver(x, y, u, v);
    // plt::show();qq
    // waitKey(0);

    // ---------------- OPTICAL FLOW ---------------------------------------------------------------------------
    string filename = "../Naiad_in_trondheim_firstTrial_pt1_2.mp4";
    bool save = true;
    bool to_gray = true;        // FARNEBACK-true, RLOF-false
    // lucas_kanade(filename, save);
    dense_optical_flow(filename, save, to_gray, FARNEBACK);        // For last argument, select from LK_DENSE, FARNEBACK, RLOF

    return 0;
}