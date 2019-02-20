#include "ContourDrawingFilter.h"

using namespace std;
using namespace cv;

namespace Icarus
{
  ContourDrawingFilter::ContourDrawingFilter()
  {
  }

  ContourDrawingFilter::~ContourDrawingFilter()
  {
  }

  void ContourDrawingFilter::Filter(ImageData* data)
  {
		Scalar contourColor(2, 8, 164);
		drawContours(*data->GetImageData(), *data->GetContours(), -1, contourColor, FILLED, 8);
  }
}
