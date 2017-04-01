#include "Header.h"
void myfunc(Mat &image1, Mat &image2, ofstream &out)
{
	int myarray[11][11];
	vector<Point2f>features;
	vector<Point2f>features2;
	vector<uchar> status;
	vector<float> err;
	int maxCount = 1700; //max读取点数
	double minDis = 10; //最小特征点的距离
	double qLevel = 0.01; 
	//读取灰度图像
	goodFeaturesToTrack(image1, features, maxCount, qLevel, minDis);
	//第一幅图的特征点
	calcOpticalFlowPyrLK(image1, image2, features, features2, status, err);
	//计算出第二帧的特点
	int k = 0;
	for (int i = 0; i < features2.size(); i++)
	{
		if (status[i] && ((abs(features[i].x - features2[i].x) + abs(features[i].y - features2[i].y))>2)) //循环每个点如果点在运动而且x，y轴和大于2 
		{
			features2[k++] = features2[i]; //重新赋值features2

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