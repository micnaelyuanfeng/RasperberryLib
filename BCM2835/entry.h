#ifndef _ENTRY_H_
#define _ENTRY_H_

//Memory Map Device Starting Offset
//BCM2835 Specific
#define BCM2708_MM_P_BASE                    0x3F000000
#define BCM2708_MM_P_BASE                    0x20000000

#define GPIO_BASE                            (BCM2708_MM_P_BASE + 0x200000)
#define BSC0_BASE                            (BCM2708_MM_P_BASE + 0x804000)
#define BLOCK_SIZE                           4096


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
    void* device_gpio;
    void* device_i2c;
    void* device_spi;
}BCM2835_t;

bool bcm2835_device_init(void);
bool bcm2835_map_device(BCM2835_device_t* this_device);
bool bcm2835_unmpa_device(BCM2835_device_t* this_device);

#endif 