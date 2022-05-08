/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:26:49 by romoreir          #+#    #+#             */
/*   Updated: 2022/05/08 19:26:49 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie() {

}

Zombie::Zombie(const std::string &name) : _name(name) {

}

Zombie::~Zombie() {
    std::cout << _name << ": " << "Is destroyed" << std::endl;
}

void Zombie::announce() {
    std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

const std::string &Zombie::getName() const {
    return _name;
}

void Zombie::setName(const std::string &name) {
    _name = name;
}


