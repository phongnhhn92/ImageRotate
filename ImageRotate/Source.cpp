#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <conio.h>
#include <iostream>
#include <Windows.h>
using namespace cv;
using namespace std;
int iAngle = 180;
int iScale = 50;
int iBorderMode = 0;
Mat imgOriginal;
int iImageCenterY = 0;
int iImageCenterX = 0;
const char* pzRotatedImage = "Rotated Image";

void CallbackForTrackBar(int, void*)
{
	Mat matRotation = getRotationMatrix2D(Point(iImageCenterX, iImageCenterY), (iAngle - 180), iScale / 50.0);

	// Rotate the image
	Mat imgRotated;
	warpAffine(imgOriginal, imgRotated, matRotation, imgOriginal.size(), INTER_LINEAR, iBorderMode, Scalar());

	imshow(pzRotatedImage, imgRotated);

}
int main(int argc, char** argv)
{
	
	// Simple rotation
	// Load the image
	Mat imgOriginal = imread("template_200.bmp", 1);
	Mat matRotation,rotatedIMG;
	
	int iImageHieght = imgOriginal.rows / 2;
	int iImageWidth = imgOriginal.cols / 2;
	/*
	while (true)
	{
		Mat matRotation = getRotationMatrix2D(Point(iImageWidth, iImageHieght), (iAngle - 180), 1);

		// Rotate the image
		Mat imgRotated;
		warpAffine(imgOriginal, imgRotated, matRotation, imgOriginal.size());

		imshow(pzRotatedImage, imgRotated);

		int iRet = waitKey(30);
		if (iRet == 27)
		{
			break;
		}
	}
	*/
	int degree;
	//rotate from 90 to -90 degree clockwise
	for (int i = 9; i > -10; i--)
	{
		degree = 10 * i;
		matRotation = getRotationMatrix2D(Point(iImageWidth, iImageHieght), degree, 1);
		warpAffine(imgOriginal, rotatedIMG, matRotation, imgOriginal.size());
		imwrite("template_200_rotated" + to_string(degree*(-1)) + ".bmp", rotatedIMG);
		//cout<<"Done " + to_string(degree) + "\n";
		//Sleep(500);
	}
	//_getch()
	return 0;
	
	
	/*
	//Rotate image with scale and border
	// Load the image
	imgOriginal = imread("template_200.bmp", 1);

	iImageCenterY = imgOriginal.rows / 2;
	iImageCenterX = imgOriginal.cols / 2;

	//show the original image
	const char* pzOriginalImage = "Original Image";
	namedWindow(pzOriginalImage, CV_WINDOW_AUTOSIZE);
	imshow(pzOriginalImage, imgOriginal);

	//create the "Rotated Image" window and 3 trackbars in it
	namedWindow(pzRotatedImage, CV_WINDOW_AUTOSIZE);
	createTrackbar("Angle", pzRotatedImage, &iAngle, 360, CallbackForTrackBar);
	createTrackbar("Scale", pzRotatedImage, &iScale, 100, CallbackForTrackBar);
	createTrackbar("Border Mode", pzRotatedImage, &iBorderMode, 5, CallbackForTrackBar);

	int iDummy = 0;

	CallbackForTrackBar(iDummy, &iDummy);

	waitKey(0);

	return 0;
	*/
}