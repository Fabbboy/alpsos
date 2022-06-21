#include "print.h"
#include "./drivers/keyboard.h"

void kernel_main() {
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_clear();
    print_str("Hello world!\n");

    while (1) {
        keyboard_handle_input();
    }

    return;
}