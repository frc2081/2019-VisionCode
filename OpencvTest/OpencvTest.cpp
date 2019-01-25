// OpencvTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GripPipeline.h"

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

#include <iostream>
#include <string>

#define w 400

using namespace cv;
using namespace std;
using namespace grip;

int main(int argc, char** argv)
{
	Mat* mask;
	GripPipeline* pipeline;
	Mat img = Mat::zeros(w, w, CV_8UC3);
	
	VideoCapture cam(0);
	namedWindow("camera");
	pipeline = new GripPipeline(1.0);

	while (1) {
		cam >> img;
		pipeline->Process(img);
		mask = pipeline->GetMaskOutput();
		imshow("camera", *mask);

		//test for esc key
		if (waitKey(1) == 27) {
			break;
		}
	}

	cam.release();
	delete pipeline;

    return 0;
}

