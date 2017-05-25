#include "Header.h"
int main()
{
	//init everything
	system("rm state.txt");
	system("sudo modprobe bcm2835-v4l2");
	time_t t= time(0);
	//---------------------------------------------
	ofstream out("data.txt");
	VideoCapture capture(0);
	capture.set(CV_CAP_PROP_FPS,30);
	Mat frame_current;
	Mat frame_old;
	capture >> frame_old; //read in the old frame
	capture >> frame_current; //read in the next frame
	while (!frame_current.empty()) 
	{
		
		cvtColor(frame_current,frame_current,CV_RGB2GRAY); //change to gray
		cvtColor(frame_old, frame_old, CV_RGB2GRAY); //change to gray
		myfunc(frame_current, frame_old, out); //call the compute function
		waitKey(10); //wait to show
		capture >> frame_old; //read in old
		capture >> frame_current; //read in current flow
		if ((time(0)-t) >= 180)
		{
			out.close();
			//call calculation
			cal();
			out.open("data.txt");
			t = time(0);
		}
		clean(); //clean up state.txt after one day of running
	}
	return 0;
}
