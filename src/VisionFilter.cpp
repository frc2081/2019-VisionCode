#include "VisionFilter.h"

using namespace std;
using namespace cv;

namespace Icarus
{
  VisionFilter::VisionFilter()
  {
  }

  VisionFilter::~VisionFilter()
  {
  }

  void VisionFilter::Filter(ImageData* data)
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
