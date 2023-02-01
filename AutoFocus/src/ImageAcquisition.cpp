#include "ImageAcquisition.h"

namespace Autofocus
{
	ImageAcquisition::ImageAcquisition()
	{

	}

	// Captures dummy image and measures FPS
	void ImageAcquisition::CaptureAndSaveDummyImage()
	{
		time_t timer_begin,timer_end;
		raspicam::RaspiCam_Cv Camera;
		cv::Mat image;
		int nCount=100;

		//Camera.set( CV_CAP_PROP_FORMAT, CV_8UC1 );
		std::cout << "Opening Camera..." << std::endl;
		if (Camera.open()) 
		{
			//Start capture
			std::cout << "Capturing " << nCount << " frames ...." << std::endl;
			time ( &timer_begin );
			for ( int i=0; i<nCount; i++ ) {
				Camera.grab();
				Camera.retrieve(image);
				if ( i%5==0 )  std::cout<< "\r captured " << i << " images" <<std::flush;
			}
			std::cout << "Stop camera..." << std::endl;
			Camera.release();
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

	// Captures image on frame
	void ImageAcquisition::CaptureImage(cv::Mat* frame)
	{
		raspicam::RaspiCam_Cv Camera;
		std::cout << "Opening Camera..." << std::endl;

		if (Camera.open()) 
		{
			//Start capture
			Camera.grab();
			Camera.retrieve(*frame);
			Camera.release();
			cv::imwrite("img.jpg", *frame);
		}
	}
}
