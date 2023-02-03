#include "StepperMotor.h"

#include <chrono>
#include <iostream>

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

    void StepperMotor::RunMotor(int direction, unsigned int angle, unsigned int speed)
    {
        digitalWrite(m_pins.en, LOW);
        digitalWrite(m_pins.dir, direction);

        int step = angle / m_stepFactor;
        //auto start = std::chrono::high_resolution_clock::now();
        float delayMs = ((speed / (360 / m_stepFactor)) / 2) * 1000;

        for (int i = 0; i < step; i++)
        {
            digitalWrite(m_pins.step, HIGH);
            delayMicroseconds(delayMs);
            digitalWrite(m_pins.step, LOW);
            delayMicroseconds(delayMs);
        }
        //auto stop = std::chrono::high_resolution_clock::now();
        //auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        //std::cout << "Time taken by motor: " << duration.count() << " microseconds" << std::endl;
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
