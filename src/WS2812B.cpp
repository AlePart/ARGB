#include <WS2812B.hpp>
#include <IColoredLed.hpp>
WS2812B::WS2812B()
{
}

WS2812B::WS2812B(std::vector<std::unique_ptr<ILed>> leds)
{
    m_leds = std::move(leds);
}

void WS2812B::AddLed(std::unique_ptr<ILed> led)
{
    m_leds.push_back(std::move(led));
}

std::vector<uint8_t> WS2812B::GetBytes()
{
    std::vector<uint8_t> bytes;
    for (auto& led : m_leds)
    {
        if( typeid(led) == typeid(std::unique_ptr<IColoredLed>) )
        {
            const auto& coloredLed = static_cast<IColoredLed*>(led.get());
            bytes.push_back(coloredLed->GetGreen());
            bytes.push_back(coloredLed->GetRed());
            bytes.push_back(coloredLed->GetBlue());
        }
        else
        {
            
            bytes.push_back(0);
            bytes.push_back(0);
            bytes.push_back(0);
        }
        
    }
    return bytes;
}



