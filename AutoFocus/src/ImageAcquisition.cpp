#include "ImageAcquisition.h"

// using namespace cv;  

ImageAcquisition::ImageAcquisition()
{

}

void ImageAcquisition::ShowDummyImage()
{
    // Mat img = imread("/home/cezeri/Desktop/unknown.png", IMREAD_COLOR);
    // imshow("window", img);
    // waitKey(0);

    cv::Mat image;
    lccv::PiCamera cam;
    //cam.options->width=4056;
    //cam.options->height=3040;
    cam.options->photo_width=2028;
    cam.options->photo_height=1520;
    cam.options->verbose=true;
    cv::namedWindow("Image",cv::WINDOW_NORMAL);
    for(int i=0;i<10;i++){
        std::cout<<i<<std::endl;
        if(!cam.capturePhoto(image)){
            std::cout<<"Camera error"<<std::endl;
        }
        cv::imshow("Image",image);
        cv::waitKey(30);
    }
    cv::waitKey();
    cv::destroyWindow("Image");
}
