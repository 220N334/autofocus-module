#include "AutoFocus.h"

#include <thread>
#include <typeinfo>

int main(int argc, char* argv[])
{
    Autofocus::ImageAcquisition img;
    //img.CaptureAndSaveDummyImage();

    // std::cout << "ARG:" << argv[1] << " " << argc << std::endl;

    Autofocus::StepperPins motor1Pins;
    motor1Pins.step = 2;
    motor1Pins.en = 1;
    motor1Pins.dir = 0;
    motor1Pins.ms1 = 0;
    motor1Pins.ms1 = 0;

    Autofocus::StepperMotor motor1(motor1Pins);
    // For now 1 rotation = 1600 step
    // std::thread worker(&Autofocus::StepperMotor::RunMotor, std::ref(motor1), 1, 32000, 100);
    // worker.join();
    //motor1.RunMotor(1, 8000, 100);

    while(true)
    {
        std::cout << "Input Waiting" << std::endl;
        std::string input;
        std::cin >> input;

        if(input[0] == 'c')
        {
            cv::Mat* frame = new cv::Mat;
            img.CaptureImage(frame);
            cv::imwrite("img.png", *frame);
            delete(frame);
        }
        else if(input[0] == 'm')
        {
            std::cout << "Write motor angle" << std::endl;
            unsigned int step;
            std::cin >> step;

            std::cout << "Write motor direction 1/0" << std::endl;
            int dir;
            std::cin >> dir;
            motor1.RunMotor(dir, step, 100);
        }
    }

    return 0;
}