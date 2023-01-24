#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <fstream>
#include <raspicam_cv.h>
#include <raspicam.h>
#include <iostream>
#include <unistd.h>
#include <ctime>

class ImageAcquisition
{
public:
    ImageAcquisition();
    void ShowDummyImage();
};
