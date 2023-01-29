#pragma once
#include <asm/ioctl.h>

#define MY_IOCTL_IN _IOW('w', 1, my_ioctl_data)
typedef enum
{

addition, 
subtraction, 
multiplication, 
division

}operation_t;

typedef struct my_ioctl_data {
     int val1;
     int val2;
     operation_t desiredOperation;
}my_ioctl_data;
