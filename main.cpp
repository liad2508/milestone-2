#include <iostream>
#include "./server/Main.h"
using namespace boot;
int main(int argc, char** argv) {
    string args[1];

    // If there is a required port.
    try {
        args[0] = string(argv[1]);
    } catch (std::logic_error e) {      // We define the port to 5600
         args[0] = string("5600");
    }
}
