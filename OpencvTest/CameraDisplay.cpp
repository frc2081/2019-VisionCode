#include "stdafx.h"
#include "CameraDisplay.h"
#include <opencv2\opencv.hpp>
#include <opencv2\imgcodecs.hpp>
#include <string.h>

static void SetInfo(char* info, Icarus::ImageData* data);

using namespace cv;
using namespace std;

namespace Icarus
{
	void CameraDisplay::Decorate(ImageData * source)
	{
		Mat* contents;
		contents = source->GetImageData();

		char info[255];
		int rows, cols, boxHeight, boxPadding;

		rows = contents->rows;
		cols = contents->cols;

		boxHeight = 75;
		boxPadding = 10;

		Scalar boxColor(229, 243, 245);
		Scalar textColor(0, 0, 0);
		Point topLeft(boxPadding, rows - (boxHeight + boxPadding)),
			bottomRight(cols - boxPadding, rows - boxPadding);

		Point textOrigin(topLeft.x + boxPadding, topLeft.y + 2* boxPadding);
		SetInfo(info, source);

		rectangle(*contents, topLeft, bottomRight, boxColor, FILLED, LINE_8);
		putText(*contents, info, textOrigin, FONT_HERSHEY_SIMPLEX, 0.5, textColor);
	}

	void CameraDisplay::Init()
	{
		namedWindow(_windowName);
	}

	void CameraDisplay::Clean()
	{
		destroyWindow(_windowName);
	}

	CameraDisplay::CameraDisplay(const char * windowName)
	{
		_windowName = windowName;
	}

	void CameraDisplay::Sink(ImageData * source)
	{
		Mat* contents;
		
		Decorate(source);
		contents = source->GetImageData();
		imshow(_windowName, *contents);
	}
}

static void SetInfo(char* info, Icarus::ImageData* data)
{
	vector<vector<Point>>* contours;

	int contourCount;
	contours = data->GetContours();
	contourCount = contours->size();

	sprintf(info, "Contours (%02d)", contourCount);
}
