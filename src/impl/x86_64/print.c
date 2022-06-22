#include "print.h"
#include "shell.h"
#include "utils.h"

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;
char* storedString;
struct Char {
    uint8_t character;
    uint8_t color;
};
struct Char* buffer = (struct Char*) 0xb8000;
size_t col = 0;
size_t row = 0;
uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;

void clear_row(size_t row) {
    struct Char empty = (struct Char) {
        character: ' ',
        color: color,
    };

    for (size_t col = 0; col < NUM_COLS; col++) {
        buffer[col + NUM_COLS * row] = empty;
    }
}
void print_clear() {
    for (size_t i = 0; i < NUM_ROWS; i++) {
        clear_row(i);
    }
}

void print_newline() {
    col = 0;

    if (row < NUM_ROWS - 1) {
        row++;
        return;
    }

    for (size_t row = 1; row < NUM_ROWS; row++) {
        for (size_t col = 0; col < NUM_COLS; col++) {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clear_row(NUM_COLS - 1);
}

void print_char(char character) {
    //if line is 24 add every char to storedString
    if (row == NUM_ROWS - 1) {
        storedString[col] = character;
    }
    //add char to messsage
    eval(character);
    if (character == '\n') {
        print_newline();
        return;
    }

    if (col > NUM_COLS) {
        print_newline();
    }

    buffer[col + NUM_COLS * row] = (struct Char) {
        character: (uint8_t) character,
        color: color,
    };
    //if backspace
    if (character == '\b') {
        if (col > 0) {
            col--;
        }
    } else {
        col++;
    }
}

void print_str(char* str) {
    for (size_t i = 0; 1; i++) {
        char character = (uint8_t) str[i];

        if (character == '\0') {
            return;
        }

        print_char(character);
        //if line count is 25 store string
    }
}

void sys_print_char(char character){
    //if line is 24 add every char to storedString
    if (row == NUM_ROWS - 1) {
        storedString[col] = character;
    }
    if (character == '\n') {
        print_newline();
        return;
    }

    if (col > NUM_COLS) {
        print_newline();
    }

    buffer[col + NUM_COLS * row] = (struct Char) {
            character: (uint8_t) character,
            color: color,
    };
    //if backspace
    if (character == '\b') {
        if (col > 0) {
            col--;
        }
    } else {
        col++;
    }
};
void sys_print_str(char* string){
    for (size_t i = 0; 1; i++) {
        char character = (uint8_t) string[i];

        if (character == '\0') {
            return;
        }

        sys_print_char(character);
        //if line count is 25 store string
    }
};

void print_set_color(uint8_t foreground, uint8_t background) {
    color = foreground + (background << 4);
}
void line_down(){
   //top: ab (line count 2, prevLineCol = 0) -> linedown: abc (line count 3, prevLineCol = 2) -> lineup: ab (line count 2, prevLineCol = 3) -> linedown (line count 3, prevLineCol = 2) and so on....
   //if line count is under 25
    if(row < NUM_ROWS - 1){
         row++;
         col = 0;
    }else{
        //clear all lines
        for(size_t i = 0; i < NUM_ROWS; i++){
            clear_row(i);
        }
        //set row to 0
        row = 0;
        //set col to 0
        col = 0;
        //print stored string
        clear_row(0);
        print_str(storedString);
        //clear stored string
        for(size_t i = 0; i < NUM_COLS; i++){
            storedString[i] = '\0';
        }
        row++;
        col = 0;
    }

};

void printStrColored(char* string,uint8_t color){
    print_set_color(color, PRINT_COLOR_BLACK);
    sys_print_str(string);
    //set default color
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
};
void printCharColored(char character, uint8_t color){
    print_set_color(color, PRINT_COLOR_BLACK);
    sys_print_char(character);
    //set default color
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
};


void backspace(){
    if(col > 0){
        col--;
        buffer[col + NUM_COLS * row] = (struct Char) {
            character: ' ',
            color: color,
        };
    }
};

void moveLeft(){
    if(col > 0){
        col--;
    }
};

void moveRight(){
    if(col < NUM_COLS - 1){
        col++;
    }
};

void printTab(){
    col + 4;
};
