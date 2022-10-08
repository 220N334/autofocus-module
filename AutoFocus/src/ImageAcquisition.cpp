#include "ImageAcquisition.h"

using namespace cv;

ImageAcquisition::ImageAcquisition()
{

}

ImageAcquisition::ShowDummyImage()
{
    Mat img = Mat::zeros(Size(400, 400), CV_8UC1);
    imshow("window", img);
    waitKey(0);
}