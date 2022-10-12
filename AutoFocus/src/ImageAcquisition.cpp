#include "ImageAcquisition.h"

using namespace cv;

ImageAcquisition::ImageAcquisition()
{

}

void ImageAcquisition::ShowDummyImage()
{
    Mat img = imread("/home/cezeri/Desktop/PixelEngine.png", IMREAD_COLOR);
    imshow("window", img);
    waitKey(0);
}
