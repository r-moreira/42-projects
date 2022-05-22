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

#include "Dog.h"

Dog::Dog() : Animal() {
    std::cout << "Dog constructor called" << std::endl;
    _type = "Dog";
    _brain = new Brain();
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}

Dog::Dog(const Dog &dog) : Animal(dog) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
    if (this == &dog) {
        return *this;
    }
    _type = dog._type;
    _brain = new Brain(*dog.getBrain());
    return *this;
}

void Dog::makeSound() const {
    std::cout << "AU AU!!!" << std::endl;
}

Brain *Dog::getBrain() const {
    return _brain;
}
