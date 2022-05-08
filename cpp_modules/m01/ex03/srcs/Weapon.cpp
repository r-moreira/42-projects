/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:28:17 by romoreir          #+#    #+#             */
/*   Updated: 2022/05/08 19:28:17 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::~Weapon() {}

Weapon::Weapon(const std::string &type) {
    this->setType(type);
}

const std::string &Weapon::getType() {
    return Weapon::_type;
}

void Weapon::setType(const std::string &type) {
    this->_type = type;
}

