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

#include "ClapTrap.h"

ClapTrap::ClapTrap():
    _name("unknown"),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(10) {
    std::cout << "Default Constructor of ClapTrap " << _name << " has been called!" << std::endl;
}

ClapTrap::ClapTrap(std::string _name):
    _name(_name),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0) {
    std::cout << "Default Constructor of ClapTrap " << _name << " has been called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct) {
    std::cout << "Copy constructor of ClapTrap " << _name << " has been called" << std::endl;
    *this = ct;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor of ClapTrap " << _name << " has been called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ct) {
    std::cout << "Assignment operator overload of ClapTrap " << _name << " has been called" << std::endl;
    _hitPoints = ct._hitPoints;
    _energyPoints = ct._energyPoints;
    _attackDamage = ct._attackDamage;
    return *this;
}

