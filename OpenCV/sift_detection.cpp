#include <opencv2/opencv.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <vector>

// need libs core, highgui, features2d and nonfree

using namespace cv;
using namespace std;

int main()
{
    Mat input = cv::imread("lena.jpg"); //Load as grayscale

    SIFT sift;

    vector<KeyPoint> keypoints;
    sift(input, noArray(), keypoints, noArray());

    Mat output;
    drawKeypoints(input, keypoints, output);
    imshow("sift", output);

    waitKey(0);

    return 0;
}
