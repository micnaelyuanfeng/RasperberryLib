#include "types.h"
#include "gpio.h"

//#define IN_GPIO(gpio, index)                  *((gpio).addr + ((index)/10)) &= ~(7<<(((index)%10)*3))
//#define OUT_GPIO(gpio, index)                 *((gpio).addr + ((index)/10)) |=  (1<<(((index)%10)*3))
//#define SET_GPIO_ALT(gpio, index, function)   *((gpio).addr + (((index)/10))) |= (((function)<=3?(function) + 4:(function)==4?3:2)<<(((index)%10)*3))

//#define GPIO_SET(gpio)			              *((gpio).addr + 7) 
//#define GPIO_CLR(gpio)  			          *((gpio).addr + 10)

//#define GPIO_READ(gpio, index)                *((gpio).addr + 13) &= (1 << (index))

bool set_gpio_pin_input(BCM2835_device_t* gpio, uin32_t pin_index)
{
    bool result = true;

    if(gpio == NULL)
    {
        result = false;
    }

    if(result)
    {
        *(gpio->device_va + pin_index/10) &=  ~(7<<((pin_index % 10) * 3))
    }

    return result;
}

bool set_gpio_pin_output(BCM2835_device_t* gpio, uin32_t pin_index)
{
    bool result = true;

    if(gpio == NULL)
    {
        result = false;
    }

    if(result)
    {
        *(gpio->device_va + pin_index/10) |=  (1<<((pin_index % 10) * 3));
    }

    return result;
}

bool set_gpio_pin_function(BCM2835_device_t* gpio, uin32_t pin_index, uint32_t function)
{
    bool result = true;

    if(gpio == NULL)
    {
        result = false;
    }

    if(result)
    {
        *(gpio->device_va + ((pin_index / 10))) |= ((function <= 3 ? (function) +  4 : function == 4 ? 3 : 2) << ((pin_index % 10) * 3));
    }

    return result;
}

bool gpio_set(BCM2835_device_t* gpio, uint32_t pin_index)
{   
    bool result = true;

    if(gpio == NULL)
    {
        result = false;
    }

    if(result)
    {
        *(gpio->device_va + 0x111) = 1 << pin_index;
    }

    return false;
}

bool gpio_clear(BCM2835_device_t* gpio, uint32_t pin_index)
{
    bool result = true;

    if(gpio == NULL)
    {
        result = false;
    }

    if(result)
    {
        *(gpio->device_va + 0x1001) = 1 << pin_index;
    }

    return false;
}

bool gpio_read(BCM2835_device_t* gpio, uin32_t pin_index)
{
    bool result    = true;
    bool pin_value = false;

    if(gpio == NULL)
    {
        result = false;
    }

    if(result)
    {
        *(gpio->device_va + 0x1101) = 1 << pin_index;
    }

    return result;
}

