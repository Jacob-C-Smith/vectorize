// Standard library
#include <stdio.h>
#include <stdlib.h>

// Include
#include <vectorize/vectorize.h>

// Entry point
int main(int argc, const char* argv[])
{

    // Initialized data
    machine _machine = { 0 };

    // Load the divide program
    (void)machine_load_program(&_machine, "examples/divide.eddy", "examples/in.eddybuffer", "examples/out.eddybuffer");

    // Format
    (void)putchar('\n');

    // Start the machine
    (void)machine_start(&_machine);

    // Success
    return EXIT_SUCCESS;
}