/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:22:36 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/25 23:22:36 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

ClapTrap::ClapTrap() :
        _name("unknown"),
        _hitPoints(10),
        _energyPoints(10),
        _attackDamage(0) {
    std::cout << "Default Constructor of ClapTrap " << _name << " has been called!" << std::endl;
}

ClapTrap::ClapTrap(std::string _name) :
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

ClapTrap &ClapTrap::operator=(const ClapTrap &ct) {
    std::cout << "Assignment operator overload of ClapTrap " << _name << " has been called" << std::endl;
    _hitPoints = ct._hitPoints;
    _energyPoints = ct._energyPoints;
    _attackDamage = ct._attackDamage;
    return *this;
}

void ClapTrap::attack(const std::string &target) {
   	if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is dead and cannot attack" << std::endl;
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " does not have energy" << std::endl;
        return;
    } else {
        _energyPoints--;
    }

    std::cout
            << "ClapTrap "
            << _name << " attack " << target
            << ", causing " << _attackDamage << " points of damage"
            << " and loses 1 energy point"
            << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout
            << "ClapTrap " << _name << " is attacked, and took "
            << amount << " points of damage"
            << std::endl;

    amount >= _hitPoints ? _hitPoints = 0 : _hitPoints = _hitPoints - amount;

    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " died" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hit points" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is dead and cannot be repaired" << std::endl;
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " does not have energy" << std::endl;
        return;
    } else {
        _energyPoints--;
    }

    _hitPoints += amount;

    if (_hitPoints > 10) {
        amount = amount - (_hitPoints - 10);
        _hitPoints = 10;
    }

    std::cout
            << "ClapTrap " << _name << " is repaired, recovers "
            << amount << " points of damage"
            << " and loses 1 energy point"
            << std::endl;

    std::cout << "ClapTrap " << _name << " is now at " << _hitPoints << " hit points" << std::endl;
}

void ClapTrap::setName(std::string name) {
    _name = name;
}

void ClapTrap::setHitPoints(unsigned int amount) {
    _hitPoints = amount;
}

void ClapTrap::setEnergyPoints(unsigned int amount) {
    _energyPoints = amount;
}

void ClapTrap::setAttackDamage(unsigned int amount) {
    _attackDamage = amount;
}

std::string ClapTrap::getName() const {
    return _name;
}

unsigned int ClapTrap::getHitPoints() const {
    return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
    return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
    return _attackDamage;
}
