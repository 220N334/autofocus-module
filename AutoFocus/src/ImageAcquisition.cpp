#include "ImageAcquisition.h"
#include "ctime"

namespace Autofocus
{
	ImageAcquisition::ImageAcquisition()
	{

	}

	ImageAcquisition::~ImageAcquisition()
	{
		m_running = false;
	}

	void ImageAcquisition::CaptureAndSaveDummyImage()
	{
		time_t timer_begin,timer_end;
		// raspicam::RaspiCam_Still_Cv Camera;
		cv::Mat image;
		int nCount=100;

		//Camera.set( CV_CAP_PROP_FORMAT, CV_8UC1 );
		std::cout << "Opening Camera..." << std::endl;
		if (m_camera.open()) 
		{
			//Start capture
			std::cout << "Capturing " << nCount << " frames ...." << std::endl;
			time ( &timer_begin );
			for ( int i=0; i<nCount; i++ ) {
				m_camera.grab();
				m_camera.retrieve(image);
				if ( i%5==0 )  std::cout<< "\r captured " << i << " images" <<std::flush;
			}
			std::cout << "Stop camera..." << std::endl;
			m_camera.release();
			time(&timer_end);
			double secondsElapsed = difftime(timer_end, timer_begin);
			std::cout << secondsElapsed <<" seconds for "<< nCount << "  frames : FPS = " <<  ( float ) ( ( float ) ( nCount ) /secondsElapsed ) << std::endl;
			cv::imwrite("raspicam_cv_image.jpg",image);
			std::cout << "Image saved at raspicam_cv_image.jpg" << std::endl;
		}
		else
		{
			std::cerr << "Error opening the camera" << std::endl;
		}
	}

	void ImageAcquisition::OpenCaptureRelease(cv::Mat* frame)
	{
		std::cout << "Opening Camera..." << std::endl;

		for(int i = 0; i < 1; i++)
		{
			if (m_camera.open()) 
			{
				sleep(3);
				m_camera.grab();
				m_camera.retrieve(*frame);
				m_camera.release();
				break;
			}
		}
	}

	bool ImageAcquisition::OpenCamera()
	{
		m_camera.set ( cv::CAP_PROP_FRAME_WIDTH, 400 );
    	m_camera.set ( cv::CAP_PROP_FRAME_HEIGHT, 300 );
		if(m_camera.open())
		{
			std::cout << "Camera Opened..." << std::endl;
			sleep(3);
			return true;
		}
		return false;
	}
	
	void ImageAcquisition::StreamThread(cv::Mat* frame)
	{
		if (streamThread != nullptr)
		{
			streamThread->join();
			delete(streamThread);
		}
		streamThread = new std::thread(&ImageAcquisition::StreamLoop, this, frame);
	}

	void ImageAcquisition::CaptureImage(cv::Mat* frame)
	{
		m_camera.grab();
		m_camera.retrieve(*frame);
	}

	void ImageAcquisition::StreamLoop(cv::Mat* frame)
	{
		while(m_running)
		{
			CaptureImage(frame);
		}
	}

	void ImageAcquisition::ResizeImage(cv::Mat* frameIn, cv::Mat* frameOut, int resizeWidth, int resizeHeigth)
	{
		cv::resize(*frameIn, *frameOut, cv::Size(resizeWidth, resizeHeigth), cv::INTER_LINEAR);
	}
}
