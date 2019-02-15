#pragma once

#include "IoEntity.h"
#include "ImageData.h"

namespace Icarus
{
	class VisionSink : public IoEntity
	{
	protected:
		virtual void Sink(ImageData* source) = 0;

	public:
		void Consume(ImageData* source);
    virtual bool OpensWindow() = 0;
	};
}
