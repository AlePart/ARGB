#ifndef COLORED_LED_HPP
#define COLORED_LED_HPP
#include <IColoredLed.hpp>

class ColoredLed : public IColoredLed
{
private:
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
  
public:
    ColoredLed();
    ColoredLed(uint8_t red, uint8_t green, uint8_t blue);
    bool IsOn() override;   
    void On() override;
    void Off() override;
    void SetColor(uint8_t red, uint8_t green, uint8_t blue) override;
    void SetColor(uint32_t color) override;
    uint8_t GetRed() override;
    uint8_t GetGreen() override;
    uint8_t GetBlue() override;

};

#endif // COLORED_LED_HPP