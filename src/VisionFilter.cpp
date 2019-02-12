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

    for(vector<Contour>::iterator i = contours->begin(); i != contours->end(); ++i)
      if(!IsMatch(*i))
        contours->erase(i);
  }
}
