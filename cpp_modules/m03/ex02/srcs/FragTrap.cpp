/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 05:05:37 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/26 03:56:48 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"

FragTrap::FragTrap() : ClapTrap("unknown") {
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    std::cout << "Default Constructor of FragTrap " << _name << " has been called!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    std::cout << "Default Constructor of FragTrap " << _name << " has been called!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap) {
    std::cout << "Copy constructor of FragTrap " << _name << " has been called" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "Destructor of FragTrap " << _name << " has been called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap) {
    this->_name = fragTrap.getName();
    this->_hitPoints = fragTrap.getHitPoints();
    this->_energyPoints = fragTrap.getHitPoints();
    this->_attackDamage = fragTrap.getAttackDamage();
    return *this;
}

void FragTrap::highFivesGuys() {
	if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << "is dead and cannot request high five" << std::endl;
        return;
    }
    std::cout << "FragTrap " << _name << " is requesting a high five" << std::endl;
}

