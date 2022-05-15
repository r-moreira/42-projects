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
    this->_value = 0;
}

Fixed::Fixed(const int param) {
    this->_value = param << Fixed::_bits;
}

Fixed::Fixed(const float param) {
    this->_value = (int) (roundf)(param * (1 << Fixed::_bits));
}


Fixed::~Fixed() {
}

Fixed::Fixed(const Fixed &origin) {
    *this = origin;
}

int Fixed::getRawBits() const {
    return this->_value;
}

void Fixed::setRawBits(int raw) {
    this->_value = raw;
}


float Fixed::toFloat() const {
    return (float) this->_value / (1 << Fixed::_bits);
}

int Fixed::toInt() const {
    return this->_value >> Fixed::_bits;
}


Fixed &Fixed::operator=(const Fixed &origin) {
    if (this == &origin) {
        return (*this);
    }
    _value = origin.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed &origin) const {
    return this->_value > origin.getRawBits();
}

bool Fixed::operator<(const Fixed &origin) const {
    return this->_value < origin.getRawBits();
}

bool Fixed::operator>=(const Fixed &origin) const {
    return this->_value >= origin.getRawBits();
}


bool Fixed::operator<=(const Fixed &origin) const {
    return this->_value <= origin.getRawBits();
}

bool Fixed::operator==(const Fixed &origin) const {
    return this->_value == origin.getRawBits();
}

bool Fixed::operator!=(const Fixed &origin) const {
    return this->_value != origin.getRawBits();
}

Fixed Fixed::operator+(const Fixed &origin) const {
    Fixed newFixed = *this;

    newFixed.setRawBits(this->_value + origin.getRawBits());
    return newFixed;
}

Fixed Fixed::operator-(const Fixed &origin) const {
    Fixed newFixed = *this;

    newFixed.setRawBits(this->_value - origin.getRawBits());
    return newFixed;
}

Fixed Fixed::operator*(const Fixed &origin) const {
    Fixed newFixed = *this;

    newFixed.setRawBits((this->_value * origin.getRawBits()) >> Fixed::_bits);
    return newFixed;
}

Fixed Fixed::operator/(const Fixed &origin) const {
    Fixed newFixed = *this;

    newFixed.setRawBits((this->_value << Fixed::_bits) / origin.getRawBits());
    return newFixed;
}

Fixed Fixed::operator--(int) {
    Fixed newFixed;

    newFixed.setRawBits(this->_value--);
    return newFixed;
}

Fixed &Fixed::operator--() {
    this->_value--;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed newFixed;

    newFixed.setRawBits(this->_value++);
    return newFixed;
}

Fixed &Fixed::operator++() {
    this->_value++;
    return *this;
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
    if (f1 <= f2) {
        return (f1);
    }
    return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
    if (f1 >= f2) {
        return (f1);
    }
    return (f2);
}

const Fixed &Fixed::min(Fixed const &f1, Fixed const &f2) {
    if (f1 <= f2) {
        return (f1);
    }
    return (f2);
}

const Fixed &Fixed::max(Fixed const &f1, Fixed const &f2) {
    if (f1 >= f2) {
        return (f1);
    }
    return (f2);
}

std::ostream &operator<<(std::ostream &out, const Fixed &origin) {
    out << origin.toFloat();
    return (out);
}