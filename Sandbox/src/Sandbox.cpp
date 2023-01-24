#include "AutoFocus.h"

int main()
{
    Autofocus::ImageAcquisition img;
    //img.CaptureAndSaveDummyImage();

    cv::Mat* frame = new cv::Mat;
    img.CaptureImage(frame);
    cv::imwrite("img.png", *frame);
    delete(frame);
    return 0;
}