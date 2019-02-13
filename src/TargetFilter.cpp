
#include "TargetFilter.h"

using namespace std;
using namespace cv;

namespace Icarus
{
  TargetFilter::TargetFilter()
  {
  }

  TargetFilter::~TargetFilter()
  {
  }

  bool TargetFilter::IsMatch(Contour contour)
  {
    Rect rect = boundingRect(contour);

    return rect.x % 2 == 0 && rect.y % 2 == 0;
  }
}
