#include "StepperMotor.h"

namespace Autofocus
{
    StepperMotor::StepperMotor(StepperPins pins)
        : m_pins(pins)
    {
        SetupPins();
    }

    void StepperMotor::SetGPIOPins(StepperPins pins)
    {
        m_pins = pins;
        SetupPins();
    }

    void StepperMotor::RunMotor(int direction, unsigned int step, unsigned int speed)
    {
        digitalWrite(m_pins.en, LOW);
        digitalWrite(m_pins.dir, LOW);

        for (int i = 0; i < step; i++)
        {
            digitalWrite(m_pins.step, HIGH);
            delay(0.5f);
            digitalWrite(m_pins.step, LOW);
            delay(0.5f);
        }
        digitalWrite(m_pins.en, HIGH);
    }

    void StepperMotor::SetupPins()
    {
        wiringPiSetup();
        pinMode (m_pins.dir, OUTPUT);
        pinMode (m_pins.step, OUTPUT);
        pinMode (m_pins.en, OUTPUT);
    }
}