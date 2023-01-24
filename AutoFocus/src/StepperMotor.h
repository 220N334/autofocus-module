#include <wiringPi.h>

namespace Autofocus
{
    struct StepperPins
    {
        unsigned int in1;
        unsigned int in2;
        unsigned int in3;
        unsigned int in4;
    };
    
    class StepperMotor
    {
    public:
        StepperMotor(StepperPins pins);
        void SetGPIOPins(StepperPins pins);
        void RunMotor(int direction, unsigned int step, unsigned int speed);
        inline StepperPins GetGPIO() { return m_pins; }
    private:
        StepperPins m_pins;
    };
}