#ifdef USE_PANGOLIN_VIEWER
#include "pangolin_viewer/viewer.h"
#elif USE_SOCKET_PUBLISHER
#include "socket_publisher/publisher.h"
#endif

#include "openvslam/system.h"
#include "openvslam/config.h"
#include "openvslam/util/stereo_rectifier.h"
#include "openvslam/util/yaml.h"

#include <iostream>
#include <chrono>
#include <numeric>

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <spdlog/spdlog.h>
#include <popl.hpp>

#ifdef USE_STACK_TRACE_LOGGER
#include <glog/logging.h>
#endif

/* GIMME2 includes and defs */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
   
#define PORT    18004

#define WIDTH   480
#define HEIGHT  270
#define BPP     3
#define PPF     (WIDTH * BPP)
#define IMAGE_SIZE (WIDTH * HEIGHT * BPP)

// GIMME2 data package structure
typedef struct 
{
    uint32_t CamNo;
    uint32_t SeqNo;
    uint8_t Data[PPF];
} UDPFrame;

void mono_tracking(const std::shared_ptr<openvslam::config>& cfg,
                   const std::string& vocab_file_path, const std::string& map_db_path) {
    int sockfd;
    struct sockaddr_in servaddr;
    
    UDPFrame frameBuffer;

    // Pre-allocate area for image 
    // CV_8UC3 represents an 8-bit Uint with 3 channels

    cv::Mat* next_image = &image;
    cv::Mat* working_image = &image_temp;

    // Creating the socket file descriptor
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) 
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
   
    memset(&servaddr, 0, sizeof(servaddr));
       
    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket with the server address
    if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 )
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    socklen_t len;

    // build a SLAM system
    openvslam::system SLAM(cfg, vocab_file_path);
    // startup the SLAM process
    SLAM.startup();

    // create a viewer object
    // and pass the frame_publisher and the map_publisher
#ifdef USE_PANGOLIN_VIEWER
    pangolin_viewer::viewer viewer(
        openvslam::util::yaml_optional_ref(cfg->yaml_node_, "PangolinViewer"), &SLAM, SLAM.get_frame_publisher(), SLAM.get_map_publisher());
#elif USE_SOCKET_PUBLISHER
    socket_publisher::publisher publisher(
        openvslam::util::yaml_optional_ref(cfg->yaml_node_, "SocketPublisher"), &SLAM, SLAM.get_frame_publisher(), SLAM.get_map_publisher());
#endif

    cv::Mat frame;
    double timestamp = 0.0;
    std::vector<double> track_times;

    unsigned int num_frame = 0;

    // run the frame capture in another thread
    std::thread thread1([&]() {
        while(true)       
        {
            // Recieve a dataframe from the GIMME2
            recvfrom(sockfd, (UDPFrame *)&frameBuffer, sizeof(UDPFrame), MSG_WAITALL, (struct sockaddr *) &servaddr, &len);

            // Save frame data to the image
            // Each data package contains one row of the image
            memcpy((*working_image).ptr(frameBuffer.SeqNo), frameBuffer.Data, PPF);
            if (frameBuffer.SeqNo != num_frame)
            {
                num_frame = 0;
                continue;
            }

            num_frame++;

            // Last sequence number recieved (not guaranteed the entire image)
            if(frameBuffer.SeqNo == HEIGHT-1)
            {
                num_frame = 0;
                cv::Mat* tempPtr = working_image;
                working_image = next_image;
                next_image = tempPtr;
            }
        }
    });

    // run the SLAM in another thread
    std::thread thread2([&]() {
        while (true) {
            // check if the termination of SLAM system is requested or not
            if (SLAM.terminate_is_requested()) {
                break;
            }

            const auto tp_1 = std::chrono::steady_clock::now();


            // input the current frame and estimate the camera pose
            SLAM.feed_monocular_frame(*next_image, timestamp, frame);

            const auto tp_2 = std::chrono::steady_clock::now();

            const auto track_time = std::chrono::duration_cast<std::chrono::duration<double>>(tp_2 - tp_1).count();
            track_times.push_back(track_time);

            timestamp += 1.0 / cfg->camera_->fps_;
            ++num_frame;
        }

        // wait until the loop BA is finished
        while (SLAM.loop_BA_is_running()) {
            std::this_thread::sleep_for(std::chrono::microseconds(5000));
        }
    });

    // run the viewer in the current thread
#ifdef USE_PANGOLIN_VIEWER
    viewer.run();
#elif USE_SOCKET_PUBLISHER
    publisher.run();
#endif

    thread1.join();
    thread2.join();

    // shutdown the SLAM process
    SLAM.shutdown();

    if (!map_db_path.empty()) {
        // output the map database
        SLAM.save_map_database(map_db_path);
    }

    std::sort(track_times.begin(), track_times.end());
    const auto total_track_time = std::accumulate(track_times.begin(), track_times.end(), 0.0);
    std::cout << "median tracking time: " << track_times.at(track_times.size() / 2) << "[s]" << std::endl;
    std::cout << "mean tracking time: " << total_track_time / track_times.size() << "[s]" << std::endl;
}

int main(int argc, char* argv[]) {
#ifdef USE_STACK_TRACE_LOGGER
    google::InitGoogleLogging(argv[0]);
    google::InstallFailureSignalHandler();
#endif

    // create options
    popl::OptionParser op("Allowed options");
    auto help = op.add<popl::Switch>("h", "help", "produce help message");
    auto vocab_file_path = op.add<popl::Value<std::string>>("v", "vocab", "vocabulary file path");
    //auto cam_num = op.add<popl::Value<unsigned int>>("n", "number", "camera number");
    auto config_file_path = op.add<popl::Value<std::string>>("c", "config", "config file path");
    //auto mask_img_path = op.add<popl::Value<std::string>>("", "mask", "mask image path", "");
    //auto scale = op.add<popl::Value<float>>("s", "scale", "scaling ratio of images", 1.0);
    auto map_db_path = op.add<popl::Value<std::string>>("p", "map-db", "store a map database at this path after SLAM", "");
    auto debug_mode = op.add<popl::Switch>("", "debug", "debug mode");
    try {
        op.parse(argc, argv);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        std::cerr << std::endl;
        std::cerr << op << std::endl;
        return EXIT_FAILURE;
    }

    // check validness of options
    if (help->is_set()) {
        std::cerr << op << std::endl;
        return EXIT_FAILURE;
    }
    if (!vocab_file_path->is_set()/* || !cam_num->is_set()*/
        || !config_file_path->is_set()) {
        std::cerr << "invalid arguments" << std::endl;
        std::cerr << std::endl;
        std::cerr << op << std::endl;
        return EXIT_FAILURE;
    }

    // setup logger
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] %^[%L] %v%$");
    if (debug_mode->is_set()) {
        spdlog::set_level(spdlog::level::debug);
    }
    else {
        spdlog::set_level(spdlog::level::info);
    }

    // load configuration
    std::shared_ptr<openvslam::config> cfg;
    try {
        cfg = std::make_shared<openvslam::config>(config_file_path->value());
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    // run tracking
    mono_tracking(cfg, vocab_file_path->value(), map_db_path->value());

    return EXIT_SUCCESS;
}
