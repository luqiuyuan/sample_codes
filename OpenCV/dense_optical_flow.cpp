#include <opencv2/opencv.hpp>

using namespace cv;

static void drawOptFlowMap(const Mat& flow, Mat& cflowmap, int step, const Scalar& color)
{
    for(int y = 0; y < cflowmap.rows; y += step)
        for(int x = 0; x < cflowmap.cols; x += step)
        {
            const Point2f& fxy = flow.at<Point2f>(y, x);
            line(cflowmap, Point(x,y), Point(cvRound(x+fxy.x), cvRound(y+fxy.y)),
                 color);
            circle(cflowmap, Point(x,y), 2, color, -1);
        }
}

int main() {
	Mat imgPre = imread("1.jpg");
	Mat imgNext = imread("2.jpg");

	Mat imgPreGray, imgNextGray;
	cvtColor(imgPre, imgPreGray, CV_BGR2GRAY);
	cvtColor(imgNext, imgNextGray, CV_BGR2GRAY);

	Mat flow;
	calcOpticalFlowFarneback(imgPreGray, imgNextGray, flow, 0.5, 3, 5, 3, 5, 1.2, 0);

	Mat flowDraw;
	cvtColor(imgPreGray, flowDraw, CV_GRAY2BGR);
	drawOptFlowMap(flow, flowDraw, 10, Scalar(0,0,255));
	imshow("flow", flowDraw);

	waitKey(0);

	return 0;
}
