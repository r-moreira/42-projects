#include <iostream>
#include "Conversion.h"

Conversion::Conversion(const std::string& input): _input(input) {}

Conversion::Conversion(Conversion const &conversion) {
    *this = conversion;
}

Conversion::~Conversion() {

}

Conversion &Conversion::operator=(const Conversion &conversion) {
    if (this->_input != conversion._input)
        _input = conversion._input;
    return *this;
}

bool Conversion::validateInput() {
    if (!isChar() && !isInt() && !isFloat() && !isDouble()) {
        return false;
    }
    return true;
}

void Conversion::display() {

}

bool Conversion::isInt() {
    size_t i;

    _input[0] == '+' || _input[0] == '-' ? i = 1 : i = 0;
    for (; i < _input.length() && isdigit(_input[i]) ; i++);
    return (i == _input.length());
}

bool Conversion::isFloat() {
    size_t i;
    size_t dot = 0;

    if (_input[_input.length() - 1] != 'f') {
        return false;
    }

    if (_input == "-inff" || _input == "+inff" || _input == "nanf") {
        return true;
    }

    _input[0] == '+' || _input[0] == '-' ? i = 1 : i = 0;

    for (; i < _input.length(); i++) {
         if (!isdigit(_input[i])
            && !(_input[i] == 'f' && _input[i + 1] == '\0')
            && !(_input[i] == '.' && isdigit(_input[i + 1]))) {
            return false;
         }
        _input[i] == '.' ? dot++ : dot;
    }

    return dot == 1;
}

bool Conversion::isDouble() {
    size_t i;
    size_t dot = 0;

    if (_input == "-inf" || _input == "+inf" || _input == "nan") {
        return true;
    }

    _input[0] == '+' || _input[0] == '-' ? i = 1 : i = 0;

    for (; i < _input.length(); i++) {
        if (!isdigit(_input[i]) && !(_input[i] == '.' && isdigit(_input[i + 1]))) {
            return false;
        }
        _input[i] == '.' ? dot++ : dot;
    }

    return dot == 1;
}

bool Conversion::isChar() {
    if (_input.length() == 1 && std::isprint(_input[0])) {
        return true;
    }
    std::cout << "Error: The argument must be a displayable character" << std::endl;
    return false;
}






