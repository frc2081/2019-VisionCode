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
		Mat* mask;
		vector<KeyPoint>* blobs;

		*_cam >> _rawImage;
		_pipeline->Process(_rawImage);
		blobs = _pipeline->GetFindBlobsOutput();
		mask = _pipeline->GetMaskOutput();

		data->SetImageData(mask);
		data->SetBlobData(blobs);
	}

	CameraSource::CameraSource(double scale, int cameraIndex)
	{
		_scale = scale;
		_cameraIndex = cameraIndex;
	}
}
