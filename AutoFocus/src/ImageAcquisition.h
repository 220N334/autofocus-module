#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <fstream>
//#include <raspicam/raspicam_cv.h>
//#include <raspicam/raspicam.h>
#include <raspicam/raspicam_still_cv.h>
#include <iostream>
#include <unistd.h>
#include <ctime>

namespace Autofocus
{
    class ImageAcquisition
    {
    public:
        ImageAcquisition();
        void CaptureAndSaveDummyImage();
        void CaptureImage(cv::Mat* frame);
    private:
        raspicam::RaspiCam_Still_Cv m_camera;
    };
}
