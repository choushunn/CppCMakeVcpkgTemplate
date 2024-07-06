#include "example.h"
#include <iostream>

int main(int argc, char *argv[])
{
    example_spdlog();
    test_signals();
    test_vtk();
    test_libevent();
    return 0;
}