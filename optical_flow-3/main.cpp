#include "Header.h"
int main()
{
	clock_t old_clock;
	int time;
	old_clock = clock();
	int delay = 10;
	//---------------------------------------------
	ofstream out("data.txt");
	VideoCapture capture(0);
	Mat frame_current;
	Mat frame_old;
	capture >> frame_old; //read in the old frame
	waitKey(20); 
	capture >> frame_current; //read in the next frame
	while (!frame_current.empty()) 
	{
		
		cvtColor(frame_current,frame_current,CV_RGB2GRAY); //change to gray
		cvtColor(frame_old, frame_old, CV_RGB2GRAY); //change to gray
		myfunc(frame_current, frame_old, out); //call the compute function
		capture >> frame_old; //read in old
		waitKey(10); //wait to show
		capture >> frame_current; //read in current flow
		waitKey(10); 
		time = (clock() - old_clock) / (double)CLOCKS_PER_SEC;
		if (time >= delay)
		{
			out.close();
			//call calculation
			system("./a.out");
			waitKey(100);
			out.open("data.txt");
			old_clock = clock();
			
		}
	}
	return 0;
}
