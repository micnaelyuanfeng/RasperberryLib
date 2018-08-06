#ifndef _GPIO_H_
#define _GPIO_H_

struct device_gpio
{
    void (*set_gpio_pin_input)(uint32_t gpio, uint32_t pin_index);
    void (*set_gpio_pin_output)(uint32_t gpio, uint32_t pin_index);
    void (*set_gpio_pin_function)(uint32_t gpio, uint32_t pin_index);
    void (*gpio_set)(uint32_t pin_index);
    void (*gpio_clear)(uint32_t pin_index);
    void (*gpio_read)(uint32_t gpio, uitn32_t pin_index);
};

void set_gpio_pin_input(uint64_t* gpio, uin32_t pin_index);
void set_gpio_pin_output(uint64_t* gpio, uin32_t pin_index);
void set_gpio_pin_function(uint64_t* gpio, uin32_t pin_index);
void gpio_set(uint32_t pin_index);
void gpio_clear(uint32_t pin_index);
void gpio_read(uint64_t* gpio, uin32_t pin_index);

#endif