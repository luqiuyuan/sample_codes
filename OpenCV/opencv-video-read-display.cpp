#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap("./test.avi");
	if(!cap.isOpened()){
		cout<<"cannot open file."<<endl;
		return -1;
	}else
		cout<<"open file successfully."<<endl;

	// This does not actually resize the frames. Not necessary. It seems they only effect the get method of VideoCapture?
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 360);

	double fps = cap.get(CV_CAP_PROP_FPS);
	cout<<"fps: "<<fps<<endl;

	namedWindow("video", CV_WINDOW_AUTOSIZE);

	while(1){
		Mat frame;

		bool bSuccess = cap.read(frame);

		if(!bSuccess){
			cout<<"cannot read frame."<<endl;
			break;
		}

		resize(frame, frame, Size(640,360));	// Here we actually resize the frame
												// For the interpolation options, see http://docs.opencv.org/modules/imgproc/doc/geometric_transformations.html#resize

		imshow("video", frame);

		if(waitKey(1000/(int)fps) == 27){
			cout<<"close"<<endl;
			break;
		}
	}
	return 0;
}