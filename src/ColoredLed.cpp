#include<ColoredLed.hpp>

ColoredLed::ColoredLed()
{
    m_red = 0;
    m_green = 0;
    m_blue = 0;
    m_isOn = false;
}

void ColoredLed::On()
{
    m_isOn = true;
}

void ColoredLed::Off()
{
    m_isOn = false;
}

void ColoredLed::SetColor(uint8_t red, uint8_t green, uint8_t blue)
{
    m_red = red;
    m_green = green;
    m_blue = blue;
}

void ColoredLed::SetColor(uint32_t color)
{
    m_red = (color & 0xFF0000) >> 16;
    m_green = (color & 0x00FF00) >> 8;
    m_blue = (color & 0x0000FF);
}

uint8_t ColoredLed::GetRed()
{
    return m_red;
}

uint8_t ColoredLed::GetGreen()
{
    return m_green;
}

uint8_t ColoredLed::GetBlue()
{
    return m_blue;
}

