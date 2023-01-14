#pragma once
#include <asm/ioctl.h>

#define MY_IOCTL_IN _IOW('w', 1, my_ioctl_data)

//kernel space definitions
typedef struct my_ioctl_data {
     int value;
}my_ioctl_data;
