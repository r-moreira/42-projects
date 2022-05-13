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
    this->value = 0;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &origin) {
    std::cout << "Copy constructor called" << std::endl;
    *this = origin;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits(int raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

Fixed &Fixed::operator=(const Fixed &origin) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &origin) {
        return (*this);
    }
    value = origin.getRawBits();
    return (*this);
}
