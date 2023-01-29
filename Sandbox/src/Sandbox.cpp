#include "AutoFocus.h"
#include <thread>

int main(int argc, char* argv[])
{
    Autofocus::ImageAcquisition img;
    //img.CaptureAndSaveDummyImage();

    // std::cout << "ARG:" << argv[1] << " " << argc << std::endl;

    Autofocus::StepperPins motor1Pins;
    motor1Pins.step = 2;
    motor1Pins.en = 1;
    motor1Pins.dir = 0;

    Autofocus::StepperMotor motor1(motor1Pins);
    std::cout << "Running Motors" << std::endl;
    // For now 1 rotation = 1600 step
    std::thread worker(&Autofocus::StepperMotor::RunMotor, std::ref(motor1), 1, 32000, 100);
    worker.join();

    cv::Mat* frame = new cv::Mat;
    img.CaptureImage(frame);
    cv::imwrite("img.png", *frame);
    delete(frame);
    
    // motor1.RunMotor(1, 8000, 100);

    return 0;
}