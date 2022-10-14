#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <libcamera/libcamera.h>
#include <lccv.hpp>

class ImageAcquisition
{
public:
    ImageAcquisition();
    void ShowDummyImage();
};
