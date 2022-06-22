#include "print.h"
#include "drivers/keyboard/keyboard.h"
#include "utils.h"
#include "drivers/time/time.h"

void kernel_main() {
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);

    print_clear();
    SysInfo("Running AlpsOS v0.1 by Fabboy\n");

    while (1) {
        checkShift();
        keyboard_handle_input();
    }

    return;
}