#include "Conversion.h"

Conversion::Conversion(const std::string &input) : _input(input) {}

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


void Conversion::getType() throw(InvalidArgumentException) {
    if (isPrintableChar()) {
        _type = CHAR;
    } else if (isInt()) {
        _type = INT;
    } else if (isFloat()) {
        _type = FLOAT;
    } else if (isDouble()) {
        _type = DOUBLE;
    } else {
        throw InvalidArgumentException();
    }
}

void Conversion::display() {

    try {
        std::cout << "char:   " << toChar() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "char:    " << e.what() << std::endl;
    }

    try {
        std::cout << "int:\t" << toInt() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "int:\t" << e.what() << std::endl;
    }

    try {
        std::cout << "float:\t" << toFloat() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "float:\t" << e.what() << std::endl;
    }

    try {
        std::cout << "double:\t" << toDouble() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "double:\t" << e.what() << std::endl;
    }
}

char Conversion::toChar() throw(Conversion::ImpossibleConversionException, Conversion::NonPrintableException) {
    if (isPseudoLiteral()) {
        throw ImpossibleConversionException();
    }

    if (_type == CHAR) {
        return static_cast<char>(_input[0]);
    }

    double result = strtod(_input.c_str(), NULL);

    if (result > 255 || result < 0) {
        throw ImpossibleConversionException();
    }

    if (!isPrintableChar(static_cast<char>(result))) {
        throw NonPrintableException();
    }

    return static_cast<char>(result);
}

int Conversion::toInt() throw(Conversion::ImpossibleConversionException) {

    if (isPseudoLiteral()) {
        throw ImpossibleConversionException();
    }

    if (_type == CHAR) {
        return static_cast<int>(_input[0]);
    }

    double result = strtod(_input.c_str(), NULL);

    if (result < INT_MIN || result > INT_MAX) {
        throw ImpossibleConversionException();
    }

    return static_cast<int>(result);
}


float Conversion::toFloat() throw(Conversion::ImpossibleConversionException) {
    return 0;
}

double Conversion::toDouble() throw(Conversion::ImpossibleConversionException) {
    return 0;
}

bool Conversion::isPseudoLiteral() {
    if (_input == "-inf" || _input == "+inf" || _input == "nan" ||
        _input == "-inff" || _input == "+inff" || _input == "nanf") {
        return true;
    }
    return false;
}


bool Conversion::isInt() {
    size_t i;

    _input[0] == '+' || _input[0] == '-' ? i = 1 : i = 0;
    for (; i < _input.length() && isdigit(_input[i]); i++);
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

bool Conversion::isPrintableChar() {
    if (((_input[0] >= '!' && _input[0] < '0') || (_input[0] > '9' && _input[0] <= '~')) && _input[1] == '\0') {
        return true;
    }
    return false;
}

bool Conversion::isPrintableChar(char c) {
    if (((c >= '!' && c < '0') || (c > '9' && c <= '~')) && c == '\0') {
        return true;
    }
    return false;
}

