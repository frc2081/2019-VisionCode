#include "stdafx.h"
#include "CameraSource.h"
#include "GripPipeline.h"

using namespace std;
using namespace grip;
using namespace cv;

namespace Icarus
{
	void CameraSource::Init()
	{
		_pipeline = new GripPipeline();
		_cam = new VideoCapture(_cameraIndex);
	}

	void CameraSource::Clean()
	{
		_cam->release();

		delete _pipeline;
		delete _cam;
	}

	void CameraSource::Source(ImageData * data)
	{
		Mat* mask;
		SimpleBlobDetector detector;

		*_cam >> _rawImage;
		_pipeline->Process(_rawImage);
		mask = _pipeline->GetHslThresholdOutput();

		_contours = _pipeline->GetFilterContoursOutput();

		data->SetImageData(mask);
		data->SetContours(_contours);
	}

	CameraSource::CameraSource(double scale, int cameraIndex)
	{
		_scale = scale;
		_cameraIndex = cameraIndex;
	}
}
