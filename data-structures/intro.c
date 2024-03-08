#include "../utils/errors.h"
#include<stdio.h>

int main() {
    // Test case 1: No error
    Error err1 = new_error(0, "No error");
    panic_if_err(err1);

    // Test case 2: Error occurred
    Error err2 = new_error(404, "File not found");
    panic_if_err(err2);

    return 0;
}