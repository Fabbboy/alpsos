#include "print.h"
#include "./drivers/keyboard.h"

void kernel_main() {

    print_clear();
    print_str("Hello world!");

    while (1) {
        char* input = keyboard_handle_input();
        print_str(input);
    }

    return;
}