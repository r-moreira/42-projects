/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:27:55 by romoreir          #+#    #+#             */
/*   Updated: 2022/05/08 19:27:55 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;
}

void HumanB::attack() const {
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
