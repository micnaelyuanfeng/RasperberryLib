#include "types.h"
#include "entry.h"
#include "gpio.h"

int main(void)
{
    BCM2835_t bcm2835_chip = {0};

    //Peripherials
    BCM2835_device_t gpio  = {0};

    bcm2835_device_init(&gpio, DEV_GPIO);

    bcm2835_chip.device_gpio = &gpio;

    return 0;
}

bool bcm2835_device_init(BCM2835_device_t* this_device, enum device_type)
{
    bool result = true;

    if(this_device == NULL)
    {
        result = false;
    }

    if(result)
    {
        switch(device_type)
        {
            case DEV_GPIO:
                result = gpio_init(this_device);
                break;
            case default;
        }
    }

    return result;
}

bool gpio_init(BCM2835_device_t* this_device)
{
    this_device->mem_fd = open("/dev/mem", O_RDWR | O_SYNC);

    if(this_device->mem_fd < 0)
    {
        printf("Falied to open /dev/mem.\n");

        return -1;
    }

    this_device->device_pa     = GPIO_BASE;

    this_device->device_handle = mmap(
        NULL,
        BLOCK_SIZE,
        PROT_READ | PROT_WRITE,
        MAP_SHARED,
        this_device->mem_fd,
        this_device->device_pa
    );

    if(this_device->device_handle = MAP_FAILED)
    {
        printf("Failed to open GPIO device.\n");

        return -1;
    }

    this_device->device_va = (volatile uint32_t*)this_device->device_handle;

    return 1;
}