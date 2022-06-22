#include <stdint.h>

void delay(uint32_t ms){
    uint32_t i, j;
    for(i = 0; i < ms; i++){
        for(j = 0; j < 1000; j++){
            asm volatile("nop");
        }
    }
};
