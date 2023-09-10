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
#include <thread>

namespace Autofocus
{
    class ImageAcquisition
    {
    public:
        ImageAcquisition();
        void CaptureAndSaveDummyImage();
        void OpenCaptureRelease(cv::Mat* frame);
        void ResizeImage(cv::Mat* frameIn, cv::Mat* frameOut, int resizeWidth, int resizeHeigth);
        
        bool OpenCamera();
        void StreamThread(cv::Mat* frame);
        void CaptureImage(cv::Mat* frame);
        void StreamLoop(cv::Mat* frame);
        inline void ReleaseCamera() {m_camera.release();}
        
    private:
        raspicam::RaspiCam_Still_Cv m_camera;
        std::thread* streamThread = nullptr;
    };
}
