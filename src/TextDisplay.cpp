#include "stdafx.h"
#include "TextDisplay.h"
#include <stdio.h>
#include <thread>
#include <chrono>

using namespace cv;
using namespace std;

namespace Icarus
{
	void TextDisplay::Init()
	{
	}

	void TextDisplay::Clean()
	{
	}

	TextDisplay::TextDisplay()
	{
	}

	void TextDisplay::Sink(ImageData * source)
	{
    const int waitInMilliseconds = 500;
    this_thread::sleep_for(chrono::milliseconds(waitInMilliseconds));

    vector<Contour>* contours = source->GetContours();
    if (contours->size() < 1)
    {
      printf("No data.\n");
      return;
    }

    for (auto i = contours->begin(); i != contours->end(); i++)
      PrintContour(*i);
  Mat *img = source->GetImageData();
  imwrite("out.jpg", *img);

    printf("\n");

	}

  void TextDisplay::PrintContour(Contour contour)
  {
    Rect rect;
    rect = boundingRect(contour);
    double ratio = (double)rect.height / (double)rect.width;
    int area = rect.height * rect.width; 
    Contour hull;
    convexHull(Mat(contour, true), hull);
    double solidity = 100 * area  / contourArea(hull);
    int vertexcount = contour.size();
     printf("[h: %d, w: %d, x: %d, y: %d, r: %0.2f, v: %d, a: %d, s: %0.2f] ", 
     rect.height, rect.width, rect.x, rect.y, ratio, vertexcount, area, solidity);

  }

  bool TextDisplay::OpensWindow()
  {
    return false;
  }
}
