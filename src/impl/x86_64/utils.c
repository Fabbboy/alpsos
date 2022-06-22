#include "print.h"
void SysError(const char* msg){
    printStrColored(msg, PRINT_COLOR_RED | PRINT_COLOR_BLACK);
};

void SysWarning(const char* msg){
    printStrColored(msg, PRINT_COLOR_YELLOW | PRINT_COLOR_BLACK);
};
void SysInfo(const char* msg){
    printStrColored(msg, PRINT_COLOR_GREEN | PRINT_COLOR_BLACK);
};

