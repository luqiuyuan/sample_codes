#include <opencv2/opencv.hpp>

using namespace cv;

int main() {

	Mat img = imread("cloud.jpg");
	cvtColor(img, img, CV_BGR2GRAY);

	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;

	Sobel(img, grad_x, CV_16S, 1, 0, 3, 1, 0);
	// Scharr(img, grad_x, CV_16S, 1, 0, 3, 1, 0);	// Scharr is more accurate than Sobel when kernel size is 3
	convertScaleAbs( grad_x, abs_grad_x );

	Sobel(img, grad_y, CV_16S, 1, 0, 3, 1, 0);
	// Scharr(img, grad_y, CV_16S, 1, 0, 3, 1, 0);	// Scharr is more accurate than Sobel when kernel size is 3
	convertScaleAbs( grad_y, abs_grad_y );

	Mat grad;
	addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );

	imshow("cloud", img);
	imshow("gra", grad);

	waitKey(0);

	return 0;
}
