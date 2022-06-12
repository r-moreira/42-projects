/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:43:21 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:43:21 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    _type = wrongAnimal._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal) {
    _type = wrongAnimal._type;
    return *this;
}

std::string const &WrongAnimal::getType() const {
    return _type;
}

void WrongAnimal::makeSound() const {
    std::cout << "WRONG UNKNOWN" << std::endl;
}


