#include <iostream>
#include<opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

Mat matrix;
Mat coeff;
Mat new_matrix;
double fx = 682.421509, fy = 682.421509, cx = 633.947449, cy = 404.559906;
double k1k2Distortion[2] = {-0.15656,-0.00404};
double p1p2p3Distortion[3] = {-0.00078,-0.00048,0.00000};
using namespace cv;
using namespace std;
void paramtersInit();//将参数转换为系数阵
int main()
{
	cv::Mat srcMat, dstMat;
	paramtersInit();
	srcMat = imread("L1.jpg");
	undistort(srcMat, dstMat, matrix, coeff, new_matrix);
	imwrite("undistortImg.png", dstMat);
	imshow("front", srcMat);
	imshow("after",dstMat);
	waitKey(0);
	system("pause");
	return 0;
}
void paramtersInit()
{
	matrix = Mat(3, 3, CV_64F);
	matrix.at<double>(0, 0) = fx;
	matrix.at<double>(0, 1) = 0;
	matrix.at<double>(0, 2) = cx;
	matrix.at<double>(1, 0) = 0;
	matrix.at<double>(1, 1) = fy;
	matrix.at<double>(1, 2) = cy;
	matrix.at<double>(2, 0) = 0;
	matrix.at<double>(2, 1) = 0;
	matrix.at<double>(2, 2) = 1;

	coeff = Mat(1, 4, CV_64F);
	coeff.at<double>(0, 0) = k1k2Distortion[0];
	coeff.at<double>(0, 1) = k1k2Distortion[1];
	coeff.at<double>(0, 2) = p1p2p3Distortion[0];
	coeff.at<double>(0, 3) = p1p2p3Distortion[1];
}