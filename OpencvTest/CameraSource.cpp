#include "stdafx.h"
#include "CameraSource.h"

using namespace std;
using namespace grip;
using namespace cv;

namespace Icarus
{
	void CameraSource::Init()
	{
		_pipeline = new GripPipeline(_scale);
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
		vector<KeyPoint>* _blobs;

		*_cam >> _rawImage;
		_pipeline->Process(_rawImage);
		_blobs = _pipeline->GetFindBlobsOutput();

		data->SetImageData(_pipeline->GetMaskOutput());
		data->SetBlobData(_pipeline->GetFindBlobsOutput());
	}

	CameraSource::CameraSource(double scale, int cameraIndex)
	{
		_scale = scale;
		_cameraIndex = cameraIndex;
	}
}
