#include <iostream>
#include "Conversion.h"

/*void tests() {

    std::cout << "========== INT TESTS ==========" << std::endl;

    std::cout << Conversion("+42").isInt() << " = 1" << std::endl;
    std::cout << Conversion("-42").isInt() << " = 1" << std::endl;
    std::cout << Conversion("42").isInt() << " = 1" << std::endl;
    std::cout << Conversion("42das").isInt() << " = 0"<< std::endl;
    std::cout << Conversion("adsd42").isInt() << " = 0" << std::endl;

    std::cout << "========== FLOAT TESTS ==========" << std::endl;

    std::cout << Conversion("+inff").isFloat() << " = 1" << std::endl;
    std::cout << Conversion("-inff").isFloat() << " = 1" << std::endl;
    std::cout << Conversion("nanf").isFloat() << " = 1" << std::endl;
    std::cout << Conversion("+42.42f").isFloat() << " = 1" << std::endl;
    std::cout << Conversion("-42.42f").isFloat() << " = 1" << std::endl;
    std::cout << Conversion("42.42f").isFloat() << " = 1" << std::endl;
    std::cout << Conversion("f42.42").isFloat() << " = 0" << std::endl;
    std::cout << Conversion("4242").isFloat() << " = 0" << std::endl;
    std::cout << Conversion("42.42fdas").isFloat() << " = 0" << std::endl;
    std::cout << Conversion("adsd42.42f").isFloat() << " = 0" << std::endl;
    std::cout << Conversion("+inffz").isFloat() << " = 0" << std::endl;
    std::cout << Conversion("z-inff").isFloat() << " = 0" <<std::endl;
    std::cout << Conversion("42.42.42f").isFloat() << " = 0" << std::endl;


    std::cout << "========== DOUBLE TESTS ==========" << std::endl;

    std::cout << Conversion("+inf").isDouble() << " = 1" << std::endl;
    std::cout << Conversion("-inf").isDouble() << " = 1" << std::endl;
    std::cout << Conversion("nan").isDouble() << " = 1" << std::endl;
    std::cout << Conversion("+42.42").isDouble() << " = 1" << std::endl;
    std::cout << Conversion("-42.42").isDouble() << " = 1" << std::endl;
    std::cout << Conversion("42.42").isDouble() << " = 1" << std::endl;
    std::cout << Conversion("42.42sdads").isDouble() << " = 0" << std::endl;
    std::cout << Conversion("adsd42.42").isDouble() << " = 0" << std::endl;
    std::cout << Conversion("+infz").isDouble() << " = 0" << std::endl;
    std::cout << Conversion("z-inf").isDouble() << " = 0" <<std::endl;
    std::cout << Conversion("42.42.42").isDouble() << " = 0" << std::endl;


    std::cout << "========== CHAR TESTS ==========" << std::endl;

    std::cout << Conversion("a").isDouble() << " = 1" << std::endl;
    std::cout << Conversion("\\").isDouble() << " = 1" << std::endl;
    std::cout << Conversion("z").isDouble() << " = 1" << std::endl;
    std::cout << Conversion("{").isDouble() << " = 1" << std::endl;
    std::cout << Conversion("").isDouble() << " = 0" << std::endl;
}*/

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

    if (!conversion.validateInput()) {
        std::cout << "Error: Invalid argument" << std::endl;
        return 1;
    }

    conversion.display();
    return 0;
}