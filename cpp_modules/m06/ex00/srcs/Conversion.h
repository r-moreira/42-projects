/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:46:34 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:46:34 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
#define CONVERSION_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <float.h>
#include <iomanip>

#define CHAR    0
#define INT     1
#define FLOAT   2
#define DOUBLE  3

class Conversion {

    class InvalidArgumentException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("Error: Invalid Argument");
        }
    };

    class ImpossibleConversionException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("Impossible");
        }
    };

    class NonPrintableException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("Non Printable");
        }
    };

private:
    std::string _input;
    short unsigned int _type;

public:
    Conversion(const std::string &input);

    Conversion(Conversion const &conversion);

    ~Conversion();

    Conversion &operator=(Conversion const &conversion);

    void getType() throw(InvalidArgumentException);

    void display();

private:
    bool isPseudoLiteral();

    bool isInt();

    bool isFloat();

    bool isDouble();

    bool isPrintableNonNumericChar();

    bool isPrintableChar(char c);

    char toChar() throw(Conversion::ImpossibleConversionException, NonPrintableException);

    int toInt() throw(Conversion::ImpossibleConversionException);

    float toFloat() throw(Conversion::ImpossibleConversionException);

    double toDouble() throw(Conversion::ImpossibleConversionException);

    std::string handleFloatPseudoLiteral();

    std::string handleDoublePseudoLiteral();

};

#endif //CONVERSION_H
