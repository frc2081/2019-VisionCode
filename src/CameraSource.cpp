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
		_cam->set(CAP_PROP_EXPOSURE, _config->GetExposure());
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

	cv::Mat * CameraSource::GetRawImage()
	{
		return &_rawImage;
	}

	cv::Mat * CameraSource::GetMask()
	{
		return _mask;
	}

	std::vector<std::vector<cv::Point>>* CameraSource::GetContours()
	{
		return _contours;
	}

	CameraSource::CameraSource(VisionConfiguration * config)
	{
		_config = config;
	}
}
