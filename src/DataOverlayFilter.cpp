#include "DataOverlayFilter.h"

static void SetInfo(char* info, Icarus::ImageData* data);

using namespace std;
using namespace cv;

namespace Icarus
{
  DataOverlayFilter::DataOverlayFilter()
  {
  }

  DataOverlayFilter::~DataOverlayFilter()
  {
  }

  void DataOverlayFilter::Filter(ImageData* data)
  {
    // TODO: Completely overhaul this.
		Mat* contents;
		contents = data->GetImageData();

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
		SetInfo(info, data);

		rectangle(*contents, topLeft, bottomRight, boxColor, FILLED, LINE_8);
		putText(*contents, info, textOrigin, FONT_HERSHEY_SIMPLEX, 0.5, textColor);
  }
}

static void SetInfo(char* info, Icarus::ImageData* data)
{
	vector<Icarus::Contour>* contours;

	int contourCount;
	contours = data->GetContours();
	contourCount = contours->size();

	sprintf(info, "Contours (%02d)", contourCount);
}
