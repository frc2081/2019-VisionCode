#include "VisionFilter.h"

namespace Icarus
{
  class TargetPairFilter : public VisionFilter
  {
    public:
      TargetPairFilter();
      virtual ~TargetPairFilter();
      void Filter(ImageData* data);
  };
}
