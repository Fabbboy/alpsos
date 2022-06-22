#include <stdint.h>
#include "utils.h"

uint8_t inb(uint16_t port) {
    uint8_t ret;
    asm volatile("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
};

//read from port 0x60
uint8_t keyboard_read_input() {
    //if something is on port 0x60
    while (!(inb(0x64) & 1));
    return inb(0x60);
};
int shifting = 0;

void checkShift() {
    if (inb(0x60) == 0x2A) {
        shifting = 1;
    }
    if (inb(0x60) == 0xAA) {
        shifting = 0;
    }
};

//identify the key pressed
void keyboard_handle_input() {
    uint8_t input = keyboard_read_input();
    //don't use a long line of ifs (use a lookup table). d) in an OS, make the function non-blocking
    //using switzerlands keyboard layout
    //https://en.wikipedia.org/wiki/Keyboard_layout#Swedish_Switzerland

    //if the key is letter a


    //check if shift is pressed

    if (input == 0x1E) {
        //if shift is pressed
        if (shifting == 1) {
            //print a
            print_char('A');
        } else {
            //print A
            print_char('a');
        }
    } else if (input == 0x30) {
        //if shift is pressed
        if (shifting == 1) {
            //print b
            print_char('B');
        } else {
            //print B
            print_char('b');
        }
    }
        //if the key is letter c
    else if (input == 0x2E) {
        //if shift is pressed
        if (shifting == 1) {
            //print c
            print_char('C');
        } else {
            //print C
            print_char('c');
        }
    }
        //if the key is letter d
    else if (input == 0x20) {
        //if shift is pressed
        if (shifting == 1) {
            //print d
            print_char('D');
        } else {
            //print D
            print_char('d');
        }
    }
        //if the key is letter e
    else if (input == 0x12) {
        //if shift is pressed
        if (shifting == 1) {
            //print e
            print_char('E');
        } else {
            //print E
            print_char('e');
        }
    }
        //if the key is letter f
    else if (input == 0x21) {
        //if shift is pressed
        if (shifting == 1) {
            //print f
            print_char('F');
        } else {
            //print F
            print_char('f');
        }
    }
        //if the key is letter g
    else if (input == 0x22) {
        //if shift is pressed
        if (shifting == 1) {
            //print g
            print_char('G');
        } else {
            //print G
            print_char('g');
        }
    }
        //if the key is letter h
    else if (input == 0x23) {
        //if shift is pressed
        if (shifting == 1) {
            //print h
            print_char('H');
        } else {
            //print H
            print_char('h');
        }
    }
        //if the key is letter i
    else if (input == 0x17) {
        //if shift is pressed
        if (shifting == 1) {
            //print i
            print_char('I');
        } else {
            //print I
            print_char('i');
        }
    }
        //if the key is letter j
    else if (input == 0x24) {
        //if shift is pressed
        if (shifting == 1) {
            //print j
            print_char('J');
        } else {
            //print J
            print_char('j');
        }
    }
        //if the key is letter k
    else if (input == 0x25) {
        //if shift is pressed
        if (shifting == 1) {
            //print k
            print_char('K');
        } else {
            //print K
            print_char('k');
        }
    }
        //if the key is letter l
    else if (input == 0x26) {
        //if shift is pressed
        if (shifting == 1) {
            //print l
            print_char('L');
        } else {
            //print L
            print_char('l');
        }
    }
        //if the key is letter m
    else if (input == 0x32) {
        //if shift is pressed
        if (shifting == 1) {
            //print m
            print_char('M');
        } else {
            //print M
            print_char('m');
        }
    }
        //if the key is letter n
    else if (input == 0x31) {
        //if shift is pressed
        if (shifting == 1) {
            //print n
            print_char('N');
        } else {
            //print N
            print_char('n');
        }
    }
        //if the key is letter o
    else if (input == 0x18) {
        //if shift is pressed
        if (shifting == 1) {
            //print o
            print_char('O');
        } else {
            //print O
            print_char('o');
        }
    }
        //if the key is letter p
    else if (input == 0x19) {
        //if shift is pressed
        if (shifting == 1) {
            //print p
            print_char('P');
        } else {
            //print P
            print_char('p');
        }
    }
        //if the key is letter q
    else if (input == 0x10) {
        //if shift is pressed
        if (shifting == 1) {
            //print q
            print_char('Q');
        } else {
            //print Q
            print_char('q');
        }
    }
        //if the key is letter r
    else if (input == 0x13) {
        //if shift is pressed
        if (shifting == 1) {
            //print r
            print_char('R');
        } else {
            //print R
            print_char('r');
        }
    }
        //if the key is letter s
    else if (input == 0x1F) {
        //if shift is pressed
        if (shifting == 1) {
            //print s
            print_char('S');
        } else {
            //print S
            print_char('s');
        }
    }
        //if the key is letter t
    else if (input == 0x14) {
        //if shift is pressed
        if (shifting == 1) {
            //print t
            print_char('T');
        } else {
            //print T
            print_char('t');
        }
    }
        //if the key is letter u
    else if (input == 0x16) {
        //if shift is pressed
        if (shifting == 1) {
            //print u
            print_char('U');
        } else {
            //print U
            print_char('u');
        }
    }
        //if the key is letter v
    else if (input == 0x2F) {
        //if shift is pressed
        if (shifting == 1) {
            //print v
            print_char('V');
        } else {
            //print V
            print_char('v');
        }
    }
        //if the key is letter w
    else if (input == 0x11) {
        //if shift is pressed
        if (shifting == 1) {
            //print w
            print_char('W');
        } else {
            //print W
            print_char('w');
        }
    }
        //if the key is letter x
    else if (input == 0x2D) {
        //if shift is pressed
        if (shifting == 1) {
            //print x
            print_char('X');
        } else {
            //print X
            print_char('x');
        }
    }
        //if the key is letter y
    else if (input == 0x15) {
        //if shift is pressed
        if (shifting == 1) {
            //print y
            print_char('Y');
        } else {
            //print Y
            print_char('y');
        }
    }
        //if the key is letter z
    else if (input == 0x2C) {
        //if shift is pressed
        if (shifting == 1) {
            //print z
            print_char('Z');
        } else {
            //print Z
            print_char('z');
        }
    }
//if the key is letter 1
    else if (input == 0x02) {
        //if shift is pressed
        if (shifting == 1) {
            //print !
            print_char('+');
        } else {
            //print 1
            print_char('1');
        }
    }
        //if the key is letter 2
    else if (input == 0x03) {
        //if shift is pressed
        if (shifting == 1) {
            //print @
            print_char('"');
        }else{
                //print 2
                print_char('2');
        }

    }else if (input == 0x04) {
        //if shift is pressed
        if (shifting == 1) {
            //print #
            print_char('$');
        } else {
            //print 3
            print_char('3');
        }
    }
        //if the key is letter 4
    else if (input == 0x05) {
        //if shift is pressed
        if (shifting == 1) {
            //print $
            print_char('ç');
        } else {
            //print 4
            print_char('4');
        }
    }
    else if (input == 0x06) {
        //if shift is pressed
        if (shifting == 1) {
            //print %
            print_char('%');
        } else {
            //print 5
            print_char('5');
        }
    }
    else if (input == 0x07) {
        //if shift is pressed
        if (shifting == 1) {
            //print ^
            print_char('&');
        } else {
            //print 6
            print_char('6');
        }
    }
    else if (input == 0x08) {
        //if shift is pressed
        if (shifting == 1) {
            //print *
            print_char('/');
        } else {
            //print 7
            print_char('7');
        }
    }
        //if the key is letter 8
    else if (input == 0x09) {
        //if shift is pressed
        if (shifting == 1) {
            //print (
            print_char('(');
        } else {
            //print 8
            print_char('8');
        }
    } else if (input == 0x0A) {
        //if shift is pressed
        if (shifting == 1) {
            //print )
            print_char(')');
        } else {
            //print 9
            print_char('9');
        }
    } else if (input == 0x0B) {
        //if shift is pressed
        if (shifting == 1) {
            //print =
            print_char('=');
        } else {
            //print 0
            print_char('0');
        }
    } else if (input == 0x1C) {
        //if caps lock is on
        //print_char('\n');
        line_down();
    } else if (input == 0x0E) {
        //if caps lock is on
        backspace();
    } else if (input == 0x39) {
        //if caps lock is on
        moveRight();
    } else if (input == 0x0C) {
        //if caps lock is on
       moveRight();
        moveRight();
        moveRight();
        moveRight();
    } else if (input == 0x4B) {
        //if caps lock is on
        moveLeft();
    } else if (input == 0x4D) {
        //if caps lock is on
        moveRight();
    }
    //if letter is $
    else if (input == 0x1A) {
        //if shift is pressed
        if (shifting == 1) {
            //print _
            print_char('£');
        } else {
            //print $
            print_char('$');
        }
    }
//if letter is ¨
    else if (input == 0x1B) {
        //if shift is pressed
        if (shifting == 1) {
            //print `
            print_char('!');
        } else {
            //print ¨
            print_char('¨');
        }
    }
    //if letter is '
    else if (input == 0x28) {
        //if shift is pressed
        if (shifting == 1) {
            //print "
            print_char('?');
        } else {
            //print '
            print_char('\'');
        }
    }
}
