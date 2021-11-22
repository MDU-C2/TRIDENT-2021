
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

// GIMME2 data package structure
typedef struct 
{
    uint32_t CamNo;
    uint32_t SeqNo;
    uint8_t Data[PPF];
} UDPFrame;

using namespace cv;

int main() 
{
    int sockfd;
    struct sockaddr_in servaddr;
    
    UDPFrame frameBuffer;

    // Pre-allocate area for image 
    // CV_8UC3 represents an 8-bit Uint with 3 channels
    Mat image = Mat(HEIGHT, WIDTH, CV_8UC3);

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

    // Read the stream until the program closes
    while(true)       
    {
        // Recieve a dataframe from the GIMME2
        recvfrom(sockfd, (UDPFrame *)&frameBuffer, sizeof(UDPFrame), MSG_WAITALL, (struct sockaddr *) &servaddr, &len);
        
        // Save frame data to the image
        // Each data package contains one row of the image
        memcpy(image.ptr(frameBuffer.SeqNo), frameBuffer.Data, PPF);

        // Last sequence number recieved (not guaranteed the entire image)
        if(frameBuffer.SeqNo == HEIGHT-1)
        {
            // Display the received image
            imshow("UDPStream", image);
            waitKey(1);
        }
    }

    return 0;
}