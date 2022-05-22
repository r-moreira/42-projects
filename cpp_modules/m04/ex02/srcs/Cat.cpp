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

#include "Cat.h"

Cat::Cat() : Animal() {
    std::cout << "Cat constructor called" << std::endl;
    _type = "Cat";
    _brain = new Brain();
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}

Cat::Cat(const Cat &cat) : Animal(cat) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = cat;
}

Cat &Cat::operator=(const Cat &cat) {
    if (this == &cat) {
        return *this;
    }
    _type = cat._type;
    _brain = new Brain(*cat._brain);
    return *this;
}

void Cat::makeSound() const {
    std::cout << "MIAU!!!" << std::endl;
}

Brain *Cat::getBrain() const {
    return _brain;
}

