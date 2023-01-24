#include "StepperMotor.h"

namespace Autofocus
{
    StepperMotor::StepperMotor(StepperPins pins)
        : m_pins(pins)
    {

    }

    void StepperMotor::SetGPIOPins(StepperPins pins)
    {
        m_pins = pins;
    }

    void StepperMotor::RunMotor(int direction, unsigned int step, unsigned int speed)
    {
        // Run Motor here
    }
}