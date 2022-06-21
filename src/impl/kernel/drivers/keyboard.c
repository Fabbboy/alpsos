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
        return 'A';
    }
    if(input == 0x1D){
        return 'B';
    }
    if(input == 0x1E){
        return 'C';
    }
if(input == 0x1F){
        return 'D';
    }
    if(input == 0x20){
        return 'E';
    }
    if(input == 0x21){
        return 'F';
    }
    if(input == 0x22){
        return 'G';
    }
    if(input == 0x23){
        return 'H';
    }
    if(input == 0x24){
        return 'I';
    }
    if(input == 0x25){
        return 'J';
    }
    if(input == 0x26){
        return 'K';
    }
    if(input == 0x27){
        return 'L';
    }
    if(input == 0x28){
        return 'M';
    }
    if(input == 0x29){
        return 'N';
    }
    if(input == 0x2A){
        return 'O';
    }
    if(input == 0x2B){
        return 'P';
    }
    if(input == 0x2C){
        return 'Q';
    }
    if(input == 0x2D){
        return 'R';
    }
    if(input == 0x2E){
        return 'S';
    }
    if(input == 0x2F){
        return 'T';
    }
    if(input == 0x30){
        return 'U';
    }
    if(input == 0x31){
        return 'V';
    }
    if(input == 0x32){
        return 'W';
    }
    if(input == 0x33){
        return 'X';
    }
    if(input == 0x34){
        return 'Y';
    }
    if(input == 0x35){
        return 'Z';
    }

};