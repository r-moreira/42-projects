#include <iostream>
#include "Conversion.h"

int main(int argc, char **argv) {

    if (argc == 1) {
        std::cout << "Error: No argument provided" << std::endl;
        return 1;
    }
    if (argc != 2) {
        std::cout << "Error: More than one argument provided" << std::endl;
        return 1;
    }

    Conversion conversion(argv[1]);

    try {
        conversion.getType();
    } catch (const std::exception &e) {
        e.what();
        return 1;
    }

    conversion.display();
    return 0;
}