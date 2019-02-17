#include "TargetPairFilter.h"

using namespace std;
using namespace cv;

namespace Icarus
{
  TargetPairFilter::TargetPairFilter()
  {
  }

  TargetPairFilter::~TargetPairFilter()
  {
  }

  bool TargetPairFilter::IsLeftOf(Contour a, Contour b)
  {
    return a.at(0).x < b.at(0).x;
  }

  void TargetPairFilter::SortContours(vector<Contour>* contours)
  {
    sort(contours->begin(), contours->end(), TargetPairFilter::IsLeftOf);
  }

  bool TargetPairFilter::IsRightLeaning(Contour contour)
  {
    // TODO: Implement this.
      int pointRx = 0;
      int HighestXVal = 0;
      int pointLx = 0;
      int LowestXVal = 0;
    for(int i = 0; i == contour.size(); i++){

      if(contour.at(i).x > HighestXVal){
        pointRx = i;
        HighestXVal = contour.at(i).x;
      }
      if(contour.at(i).x < LowestXVal){
        pointLx = i;
        LowestXVal = contour.at(i).x;
      }
    }
    // Correct Algorithm:
    // If the rightmost point is above the leftmost point, it is right-leaning.

    return contour.at(pointLx).y < contour.at(pointRx).y;
  }

  void TargetPairFilter::Filter(ImageData* data)
  {
    vector<Contour>* contours = data->GetContours();
    SortContours(contours);

    // Find the left-most right-leaning contour.
    // Removes all before it.
    auto i = contours->begin();
    while(i != contours->end())
      if(IsRightLeaning(*i))
        break;
      else
        i = contours->erase(i);
    
    // If fewer than left, right, and extra exist.
    // Just return.
    if (contours->size() < 3)
      return;

    // Increment twice to preserve left and right.
    ++i; i++;

    // Remove all after.
    while(i != contours->end())
      i = contours->erase(i);
  }
}
