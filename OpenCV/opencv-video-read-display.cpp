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

		imshow("video", frame);

		if(waitKey(1000/(int)fps) == 27){
			cout<<"close"<<endl;
			break;
		}
	}
	return 0;
}