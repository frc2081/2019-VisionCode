#include "stdafx.h"
#include "SingleVisionFilter.h"

using namespace std;
using namespace cv;

namespace Icarus
{
  SingleVisionFilter::SingleVisionFilter()
  {
  }

  SingleVisionFilter::~SingleVisionFilter()
  {
  }

  void SingleVisionFilter::Filter(ImageData* data)
  {
    vector<Contour>* contours;
    contours = data->GetContours();

    auto i = contours->begin();
    while (i != contours->end())
      if (!IsMatch(*i))
        i = contours->erase(i);
      else
        ++i;
  }
}
