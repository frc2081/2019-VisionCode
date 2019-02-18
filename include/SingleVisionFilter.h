#pragma once

#include "IoEntity.h"
#include "ImageData.h"
#include "VisionFilter.h"

namespace Icarus
{
  class SingleVisionFilter : public VisionFilter
  {
    protected:
      virtual bool IsMatch(Contour contour) = 0;

    public:
      SingleVisionFilter();
      virtual ~SingleVisionFilter();
      void Filter(ImageData* data);
  };
}
