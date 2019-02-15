#pragma once

#include "IoEntity.h"
#include "ImageData.h"

namespace Icarus
{
	class VisionSource : public IoEntity
	{
	protected:
		virtual void Source(ImageData* data) = 0;

	public:
		void GetImageData(ImageData* data);
	};
}