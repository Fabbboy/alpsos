#include "print.h"
#include "./drivers/keyboard.h"

void kernel_main() {

    print_clear();
    print_str("Hello world!\n");

    while (1) {
        char input = keyboard_handle_input();
        print_char(input);
    }

    return;
}