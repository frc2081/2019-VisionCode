
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
    return false;
  }
}
