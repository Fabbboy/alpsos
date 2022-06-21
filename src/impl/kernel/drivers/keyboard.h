

#ifndef ALPSOS_KEYBOARD_H
#define ALPSOS_KEYBOARD_H
#include <stdint.h>

uint8_t inb(uint16_t port);
//read from port 0x60
uint8_t keyboard_read_input();
//identify the key pressed
char keyboard_handle_input();


#endif //ALPSOS_KEYBOARD_H
