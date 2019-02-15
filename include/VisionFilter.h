#pragma once

#include "IoEntity.h"
#include "ImageData.h"

namespace Icarus
{
  class VisionFilter
  {
    protected:
      virtual bool IsMatch(Contour contour) = 0;

    public:
      VisionFilter();
      virtual ~VisionFilter();
      void Filter(ImageData* data);
  };
}
