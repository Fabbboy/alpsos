#include <stdint.h>
#include "utils.h"

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
void keyboard_handle_input(){
    uint8_t input = keyboard_read_input();
     //don't use a long line of ifs (use a lookup table). d) in an OS, make the function non-blocking

    //using switzerlands keyboard layout
    //https://en.wikipedia.org/wiki/Keyboard_layout#Swedish_Switzerland

    //if the key is letter a
    if(input == 0x1E){
        //if caps lock is on
        print_char('A');
    }
    //if the key is letter b
    else if(input == 0x30){
        //if caps lock is on
        print_char('B');
    }
    //if the key is letter c
    else if(input == 0x2E){
        //if caps lock is on
        print_char('C');
    }
    //if the key is letter d
    else if(input == 0x20){
        //if caps lock is on
        print_char('D');
    }
    //if the key is letter e
    else if(input == 0x12){
        //if caps lock is on
        print_char('E');
    }
    //if the key is letter f
    else if(input == 0x21){
        //if caps lock is on
        print_char('F');
    }
    //if the key is letter g
    else if(input == 0x22){
        //if caps lock is on
        print_char('G');
    }
    //if the key is letter h
else if(input == 0x23){
        //if caps lock is on
        print_char('H');
    }
    //if the key is letter i
    else if(input == 0x17){
        //if caps lock is on
        print_char('I');
    }
    //if the key is letter j
    else if(input == 0x24){
        //if caps lock is on
        print_char('J');
    }
    //if the key is letter k
    else if(input == 0x25){
        //if caps lock is on
        print_char('K');
    }
    //if the key is letter l
else if(input == 0x26){
        //if caps lock is on
        print_char('L');
    }
    //if the key is letter m
    else if(input == 0x32){
        //if caps lock is on
        print_char('M');
    }
    //if the key is letter n
    else if(input == 0x31){
        //if caps lock is on
        print_char('N');
    }
    //if the key is letter o
    else if(input == 0x18){
        //if caps lock is on
        print_char('O');
    }
    //if the key is letter p
    else if(input == 0x19){
        //if caps lock is on
        print_char('P');
    }
    //if the key is letter q
    else if(input == 0x10){
        //if caps lock is on
        print_char('Q');
    }
    //if the key is letter r
    else if(input == 0x13){
        //if caps lock is on
        print_char('R');
    }
    //if the key is letter s
    else if(input == 0x1F){
        //if caps lock is on
        print_char('S');
    }
    //if the key is letter t
    else if(input == 0x14){
        //if caps lock is on
        print_char('T');
    }
    //if the key is letter u
    else if(input == 0x16){
        //if caps lock is on
        print_char('U');
    }
    //if the key is letter v
    else if(input == 0x2F){
        //if caps lock is on
        print_char('V');
    }
    //if the key is letter w
    else if(input == 0x11){
        //if caps lock is on
        print_char('W');
    }
    //if the key is letter x
    else if(input == 0x2D){
        //if caps lock is on
        print_char('X');
    }
    //if the key is letter y
    else if(input == 0x15){
        //if caps lock is on
        print_char('Y');
    }
    //if the key is letter z
    else if(input == 0x2C){
        //if caps lock is on
        print_char('Z');
    }
//if the key is letter 1
    else if(input == 0x02){
        //if caps lock is on
        print_char('1');
    }
    //if the key is letter 2
    else if(input == 0x03){
        //if caps lock is on
        print_char('2');
    }
    //if the key is letter 3
    else if(input == 0x04){
        //if caps lock is on
        print_char('3');
    }
    //if the key is letter 4
    else if(input == 0x05){
        //if caps lock is on
        print_char('4');
    }
    //if the key is letter 5
    else if(input == 0x06){
        //if caps lock is on
        print_char('5');
    }
    //if the key is letter 6
    else if(input == 0x07){
        //if caps lock is on
        print_char('6');
    }
    //if the key is letter 7
    else if(input == 0x08){
        //if caps lock is on
        print_char('7');
    }
    //if the key is letter 8
    else if(input == 0x09){
        //if caps lock is on
        print_char('8');
    }
    //if the key is letter 9
    else if(input == 0x0A){
        //if caps lock is on
        print_char('9');
    }
    //if the key is letter 0
    else if(input == 0x0B){
        //if caps lock is on
        print_char('0');
    }
    //if letter is \n
    else if(input == 0x1C){
        //if caps lock is on
        //print_char('\n');
        line_down();
    }
    //if letter is backspace
    else if(input == 0x0E){
        //if caps lock is on
        print_char('\b');
    }
    //if letter is space
    else if(input == 0x39){
        //if caps lock is on
        print_char(' ');
    }
    //if letter is tab
    else if(input == 0x0C){
        //if caps lock is on
        print_char('\t');
    }
    //if letter is arrow up
    else if(input == 0x48){
        //print line up
        SysError("\nArrow up not supported\n");
    }
    //if letter is arrow down
    else if(input == 0x50){
        //print line down
        line_down();
    }
};