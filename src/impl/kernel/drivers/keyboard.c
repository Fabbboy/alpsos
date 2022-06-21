#include <stdint.h>

uint8_t inb(uint16_t port){
    uint8_t ret;
    asm volatile("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
};
//read from port 0x60
uint8_t keyboard_read_input(){
    //if something is on port 0x60
    while(!(inb(0x64) & 1));
    return inb(0x60);
};
//identify the key pressed
char keyboard_handle_input(){
    uint8_t input = keyboard_read_input();
    if(input == 0x1C){
        return '\n';
    }
    if(input == 0x0E){
        return '\b';
    }
    if(input == 0x0F){
        return '\t';
    }
    //identify the letter a to z
    if(input >= 0x1E && input <= 0x27){
        return input + 'a' - 0x1E;
    }
    //identify the number 0 to 9
    if(input >= 0x2F && input <= 0x39){
        return input + '0' - 0x2F;
    }
    //identify the number pad 0 to 9
    if(input >= 0x47 && input <= 0x4F){
        return input + '0' - 0x47;
    }
    //identify the number pad * and +
    if(input == 0x37 || input == 0x4A){
        return '*';
    }
    if(input == 0x4E){
        return '+';
    }
    //identify the number pad - and /
    if(input == 0x4A || input == 0x4E){
        return '-';
    }
    if(input == 0x4F){
        return '/';
    }
    //identify the number pad = and enter
    if(input == 0x50 || input == 0x1C){
        return '=';
    }
    //identify the number pad backspace
    if(input == 0x66){
        return '\b';
    }
    //identify the number pad tab
    if(input == 0x0F){
        return '\t';
    }
    //identify the number pad left arrow
    if(input == 0x4B){
        return '<';
    }
    //identify the number pad right arrow
    if(input == 0x4D){
        return '>';
    }
    //identify the number pad up arrow
    if(input == 0x48){
        return '^';
    }
    //identify the number pad down arrow
    if(input == 0x50){
        return 'v';
    }
};