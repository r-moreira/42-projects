/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:46:31 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:46:31 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    if (isPrintableNonNumericChar()) {
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
    char c;
    int i;
    float f;
    double d;

    try {
        c = toChar();
        std::cout << "char:\t" << c << std::endl;
    } catch (const std::exception &e) {
        std::cout << "char:\t" << e.what() << std::endl;
    }

    try {
        i = toInt();
        std::cout << "int:\t" << i << std::endl;
    } catch (const std::exception &e) {
        std::cout << "int:\t" << e.what() << std::endl;
    }

    try {
        if (!isPseudoLiteral()) {
            f = toFloat();
            std::cout << "float:\t" << std::setprecision(1) << std::fixed << f << "f" << std::endl;
        } else {
            std::cout << "float:\t" << handleFloatPseudoLiteral() << std::endl;
        }
    } catch (const std::exception &e) {
        std::cout << "float:\t" << e.what() << std::endl;
    }

    try {
        if (!isPseudoLiteral()) {
            d = toDouble();
            std::cout << "double:\t" << d << std::endl;
        } else {
            std::cout << "double:\t" << handleDoublePseudoLiteral() << std::endl;
        }
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

    if (result < -INT_MAX || result > INT_MAX) {
        throw ImpossibleConversionException();
    }

    return static_cast<int>(result);
}

float Conversion::toFloat() throw(Conversion::ImpossibleConversionException) {
    if (_input.length() == 1 && !isdigit(_input[0])) {
        return static_cast<float>(_input[0]);
    }

    double result = strtod(_input.c_str(), NULL);

    if (result < -FLT_MAX || result > FLT_MAX) {
        throw ImpossibleConversionException();
    }
    return static_cast<float>(result);
}

double Conversion::toDouble() throw(Conversion::ImpossibleConversionException) {
    if (_input.length() == 1 && !isdigit(_input[0])) {
        return static_cast<double>(_input.c_str()[0]);
    }

    long double result = strtod(_input.c_str(), NULL);
    if (result < -DBL_MAX || result > DBL_MAX) {
        throw ImpossibleConversionException();
    }
    return static_cast<double>(result);
}

std::string Conversion::handleFloatPseudoLiteral() {
    if (_type == DOUBLE) {
        std::string tmp = _input;
        return tmp.append(1, 'f');
    }
    return _input;
}

std::string Conversion::handleDoublePseudoLiteral() {
    if (_type == FLOAT) {
        return _input.substr(0, _input.length() - 1);
    }
    return _input;
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

bool Conversion::isPrintableNonNumericChar() {
    if (((_input[0] >= '!' && _input[0] < '0') || (_input[0] > '9' && _input[0] <= '~')) && _input[1] == '\0') {
        return true;
    }
    return false;
}

bool Conversion::isPrintableChar(char c) {
    if (c >= '!' && c <= '~') {
        return true;
    }
    return false;
}

