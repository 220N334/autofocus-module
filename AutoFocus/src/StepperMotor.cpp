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

        if(m_pins.ms1 && m_pins.ms2)
        {
            m_stepFactor = 1.8f / 16.0f;
        }
        else if(!m_pins.ms1 && !m_pins.ms2)
        {
            m_stepFactor = 1.8f / 8.0f;
        }
        else if(!m_pins.ms1 && m_pins.ms2)
        {
            m_stepFactor = 1.8f / 4.0f;
        }
        else if(m_pins.ms1 && !m_pins.ms2)
        {
            m_stepFactor = 1.8f / 2.0f;
        }
    }
}