#include "stdafx.h"
#include "TargetFilter.h"

using namespace std;
using namespace cv;

namespace Icarus
{
  TargetFilter::TargetFilter()
  {
  }

  TargetFilter::~TargetFilter()
  {
  }

  bool TargetFilter::IsMatch(Contour contour)
  {
    Rect rect = boundingRect(contour);
    double ratio = (double)rect.height / (double)rect.width;
    int area = rect.height * rect.width; 
    Contour hull;
    convexHull(Mat(contour, true), hull);
    double solidity = 100 * area  / contourArea(hull);

    


    int vertexcount = contour.size();
    int MinHeight = 7;
    int MaxHeight = 200;
    int MinWidth = 15;
    int MaxWidth = 155;
    double MinRatio = 0.2;
    double MaxRatio = 4;
    int MinVertex = 60;
    int MaxVertex = 350;
    int MinSolidarity = 100;
    int MaxSolidarity = 270;
    return MinHeight < rect.height && rect.height < MaxHeight 
          &&  MinWidth < rect.width && rect.width < MaxWidth
          && MinRatio < ratio && ratio < MaxRatio 
          && MinVertex < vertexcount && vertexcount < MaxVertex 
          && MinSolidarity < solidity && solidity < MaxSolidarity;
    
  }
}
