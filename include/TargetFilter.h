#include "VisionFilter.h"

namespace Icarus
{
  class TargetFilter : public VisionFilter
  {
    protected:
      bool IsMatch(Contour contour);

    public:
      TargetFilter();
      virtual ~TargetFilter();
  };
}
