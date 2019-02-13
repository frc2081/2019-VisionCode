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

    printf("\n");
	}

  void TextDisplay::PrintContour(Contour contour)
  {
    Rect rect;
    rect = boundingRect(contour);
    printf("[h: %d, w: %d, x: %d, y: %d] ", rect.height, rect.width, rect.x, rect.y);
  }
}
