#ifndef OPTFLOW
#define OPTFLOW

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/types_c.h>
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
using namespace cv;

void myfunc(Mat &image1, Mat &image2, ofstream &out);
void output_data(int squares, ofstream &out);
void display(vector<Point2f> &features2, int k, Mat &image1);
int cout_matrix(int myarray[11][11]);
#endif // !OPTFLOW