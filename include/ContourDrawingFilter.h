#include "VisionFilter.h"

namespace Icarus
{
  class ContourDrawingFilter : public VisionFilter
  {
    public:
      ContourDrawingFilter();
      virtual ~ContourDrawingFilter();
      void Filter(ImageData* data);
  };
}
