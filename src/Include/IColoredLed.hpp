#ifndef __IColoredLed_hpp__
#define __IColoredLed_hpp__
#include <ILed.hpp>

class IColoredLed : public ILed
{
public:
    IColoredLed():ILed(){};
    virtual void SetColor(uint8_t red, uint8_t green, uint8_t blue) =0;
    virtual void SetColor(uint32_t color) =0;
    virtual uint8_t GetRed() =0;
    virtual uint8_t GetGreen() =0;
    virtual uint8_t GetBlue() =0;
};

#endif // __IColoredLed_hpp__