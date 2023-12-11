#ifndef __ILED_HPP__
#define __ILED_HPP__
#include <stdint.h>
class ILed
{
public:
    ILed(){};
    virtual bool IsOn() =0;
    virtual void On() =0;
    virtual void Off() =0;
    
};
#endif // __ILED_HPP__