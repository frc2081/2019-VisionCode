#include "stdafx.h"
#include "CameraSource.h"

using namespace std;
using namespace grip;
using namespace cv;

namespace Icarus
{
	void CameraSource::Init()
	{
		_pipeline = new GripPipeline(_config);
		_cam = new VideoCapture(_config->GetCameraIndex());
		_cam->set(CV_CAP_PROP_EXPOSURE, _config->GetExposure());
	}

	void CameraSource::Clean()
	{
		_cam->release();

		delete _pipeline;
		delete _cam;
	}

	void CameraSource::ReadFromCamera()
	{
		*_cam >> _rawImage;
		_pipeline->Process(_rawImage);
		_mask = _pipeline->GetHslThresholdOutput();

		_contours = _pipeline->GetFilterContoursOutput();
	}

	void CameraSource::Source(ImageData * data)
	{	
		ReadFromCamera();
		data->SetImageData(GetMask());
		data->SetContours(GetContours());
	}

	Mat * CameraSource::GetRawImage()
	{
		return &_rawImage;
	}

	Mat * CameraSource::GetMask()
	{
		return _mask;
	}

	vector<Contour>* CameraSource::GetContours()
	{
		return _contours;
	}

	CameraSource::CameraSource(VisionConfiguration * config)
	{
		_config = config;
	}
}
