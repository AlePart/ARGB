#ifndef WS2812B_HPP
#define WS2812B_HPP

#include <ILed.hpp>
#include <vector>
#include <memory>

class WS2812B 
{
private:
    std::vector<std::unique_ptr<ILed>> m_leds;
public:
    WS2812B();
    WS2812B(std::vector<std::unique_ptr<ILed>> leds);
    void AddLed(std::unique_ptr<ILed> led);
    std::vector<uint8_t> GetBytes();
    
};

#endif // WS2812B_HPP