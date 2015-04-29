#include <string.h>	// memset is in string.h
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
	int width = 1920;
	int height =  1080;
	uchar intensity = 128;

	// single channel
	Mat img(Size(width,height), CV_8U);
	if(img.isContinuous())    // if the matrix is in a single row in memory
        memset(img.data, intensity, width*height*sizeof(uchar));
    else    // if there are gaps between rows
        for(int row = 0; row < height; row++) {
            memset(img.ptr<uchar>(row), intensity, width*sizeof(uchar));
        }

    namedWindow("demo");

    imshow("demo", img);

    // multi channel
    // B, G and R components for a single pixel is stored continuously in the memory
    Mat img2(Size(width,height), CV_8UC3);
	if(img2.isContinuous())    // if the matrix is in a single row in memory
        memset(img2.data, intensity, width*height*3*sizeof(uchar));
    else    // if there are gaps between rows
        for(int row = 0; row < height; row++) {
            memset(img2.ptr<uchar>(row), intensity, width*3*sizeof(uchar));
        }

    namedWindow("demo2");

    imshow("demo2", img2);

    waitKey(0);

	return 0;
}
