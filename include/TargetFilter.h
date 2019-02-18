#include "SingleVisionFilter.h"

namespace Icarus
{
  class TargetFilter : public SingleVisionFilter
  {
    protected:
      bool IsMatch(Contour contour);

    public:
      TargetFilter();
      virtual ~TargetFilter();
  };
}
