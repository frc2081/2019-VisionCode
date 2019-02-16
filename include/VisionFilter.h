#pragma once

#include "IoEntity.h"
#include "ImageData.h"

namespace Icarus
{
  class VisionFilter
  {

    public:
      VisionFilter();
      virtual ~VisionFilter();
      virtual void Filter(ImageData* data) = 0;
  };
}
