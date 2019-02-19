#include "VisionFilter.h"

namespace Icarus
{
  class TargetPairFilter : public VisionFilter
  {
    protected:
      static bool IsLeftOf(Contour a, Contour b);
      void SortContours(std::vector<Contour>* contours);
      bool IsRightLeaning(Contour contour);

    public:
      TargetPairFilter();
      virtual ~TargetPairFilter();
      void Filter(ImageData* data);
  };
}
