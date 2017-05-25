#include "Header.h"
void myfunc(Mat &image1, Mat &image2, ofstream &out)
{
	int myarray[11][11];
	vector<Point2f>features;
	vector<Point2f>features2;
	vector<uchar> status;
	vector<float> err;
	int maxCount = 1700; //max point
	double minDis = 10; //min distance between points
	double qLevel = 0.02;  //quality level
	//find good feature on image1
	goodFeaturesToTrack(image1, features, maxCount, qLevel, minDis);
	//calculate the difference of these two points
	calcOpticalFlowPyrLK(image1, image2, features, features2, status, err);
	int k = 0;
	for (int i = 0; i < features2.size(); i++)
	{
		if (status[i] && ((abs(features[i].x - features2[i].x) + abs(features[i].y - features2[i].y))>2)) //differents between feature 1 and 2 are larger than 2
		{
			k++;
			//-----------------find x and y of moving points-------------------
			int calx = features2[i].x;
			int caly = features2[i].y;
			//-----------------------------------------------------------------
			int moving_x = calx / 64;
			int moving_y = caly / 48;
			myarray[moving_x][moving_y] = 1;
		}
	}
	int moving_square = cout_matrix(myarray);
	//out put to file
	output_data(moving_square, out);
	//circle out everything
	display(features2,k, image1);
}

void output_data(int squares, ofstream &out)
{
	out << squares << endl;
	cout << squares << endl;
}

int cout_matrix(int myarray[11][11])
{
	int moving_square = 0;
	for (int l = 0; l < 11; l++)
	{
		for (int m = 0; m < 11; m++)
		{
			if (myarray[l][m] == 1)
			{
				moving_square++;
			}

		}
	}
	return moving_square;
}

void display(vector<Point2f> &features2, int k, Mat &image1)
{
	features2.resize(k);
	for (int i = 0; i < features2.size(); i++)
	{
		circle(image1, features2[i], 3, Scalar(255), 2);
	}
	imshow("features", image1);
}