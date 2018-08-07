#ifndef _ENTRY_H_
#define _ENTRY_H_

//Memory Map Device Starting Offset
//BCM2835 Specific
#define BCM2708_MM_P_BASE                    0x3F000000
#define BCM2708_MM_P_BASE                    0x20000000

#define GPIO_BASE                            (BCM2708_MM_P_BASE + 0x200000)
#define BSC0_BASE                            (BCM2708_MM_P_BASE + 0x804000)
#define BLOCK_SIZE                           4096

enum device_type
{
    DEV_GPIO  = 0x1,
    DEV_SPI   = 0x2,
    DEV_I2C   = 0x3,
    DEV_UART  = 0x4,
    DEV_TIMER = 0x5
};

enum debug_status
{
    EXE_FAILED  = 0xE,
    EXE_SUCCESS = 0xF,
};

typedef struct BCM2835_device
{
    uint64_t            device_pa;
    int                 mem_fd;    //file descriptor
    void*               device_handle;
    volatile uint32_t*  device_va;   
}BCM2835_device_t;

typedef struct BCM2835
{
    //Add more device
    BCM2835_device_t* device_gpio;
    BCM2835_device_t* device_i2c;
    BCM2835_device_t* device_spi;
    BCM2835_device_t* device_uart;
    BCM2835_device_t* device_timer;
}BCM2835_t;

bool bcm2835_device_init(BCM2835_device_t* this_device, enum device_type);

bool gpio_init(BCM2835_device_t* this_device);
bool i2c_init(BCM2835_device_t* this_device);
bool spi_init(BCM2835_device_t* this_device);
bool uart_init(BCM2835_device_t* this_device);
bool timer_init(BCM2835_device_t* this_device);

#endif 