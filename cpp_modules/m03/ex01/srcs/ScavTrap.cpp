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

#include "ScavTrap.h"

ScavTrap::ScavTrap() : ClapTrap("unknown") {
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << "Default Constructor of ScavTrap " << _name << " has been called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << "Default Constructor of ScavTrap " << _name << " has been called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap) {
    std::cout << "Copy constructor of ScavTrap " << _name << " has been called" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "Destructor of ScavTrap " << _name << " has been called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap) {
    this->_name = scavTrap.getName();
    this->_hitPoints = scavTrap.getHitPoints();
    this->_energyPoints = scavTrap.getHitPoints();
    this->_attackDamage = scavTrap.getAttackDamage();
    return *this;
}

void ScavTrap::attack(const std::string &target) {
    if (_energyPoints == 0) {
        std::cout << "ScavTrap " << _name << "does not have energy" << std::endl;
        return;
    } else {
        _energyPoints--;
    }

    std::cout
            << "ScavTrap "
            << _name << " attack " << target
            << ", causing " << _attackDamage << " points of damage"
            << " and loses 1 energy point"
            << std::endl;
}

void ScavTrap::guardGate() const {
    std::cout << "ScavTrap is now in Gatekeeper mode." << std::endl;
}
