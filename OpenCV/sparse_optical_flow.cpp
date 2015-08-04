#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

int main() {
	Mat img1 = imread("img1.jpg");
	Mat img2 = imread("img2.jpg");

	vector<Point2f> from;
	vector<Point2f> to;

	int XInterval = 15;
	int YInterval = 15;
	size_t NX = img1.size().width / XInterval;
	size_t NY = img1.size().height / YInterval;
	for(size_t nx = 0; nx < NX; nx++) {
		for(size_t ny = 0; ny < NY; ny++) {
			from.push_back(Point2f((nx+1) * XInterval - 1, (ny+1) * YInterval -1));
		}
	}

	vector<uchar> status;
	vector<float> err;
	calcOpticalFlowPyrLK(img1, img2, from, to, status, err);

	for(size_t i = 0; i < from.size(); i++)
		line(img1, from[i], to[i], Scalar(0,255,0));

	imshow("test", img1);

	waitKey(0);

	return 0;
}
