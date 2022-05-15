/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 05:05:37 by romoreir          #+#    #+#             */
/*   Updated: 2022/05/10 05:05:37 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}

Fixed::Fixed(const int param) {
    std::cout << "Int constructor called" << std::endl;
    this->_value = param << Fixed::_bits;
}

Fixed::Fixed(const float param) {
    std::cout << "Float constructor called" << std::endl;
    this->_value = (int) (roundf)(param * (1 << Fixed::_bits));
}


Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &origin) {
    std::cout << "Copy constructor called" << std::endl;
    *this = origin;
}

int Fixed::getRawBits() const {
    return (this->_value);
}

void Fixed::setRawBits(int raw) {
    this->_value = raw;
}


float Fixed::toFloat() const {
    return ((float) this->_value / (1 << Fixed::_bits));
}

int Fixed::toInt() const {
    return (this->_value >> Fixed::_bits);
}


Fixed &Fixed::operator=(const Fixed &origin) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &origin) {
        return (*this);
    }
    _value = origin.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &origin) {
    out << origin.toFloat();
    return (out);
}