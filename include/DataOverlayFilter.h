#include "VisionFilter.h"

namespace Icarus
{
  class DataOverlayFilter : public VisionFilter
  {
    public:
      DataOverlayFilter();
      virtual ~DataOverlayFilter();
      void Filter(ImageData* data);
  };
}
