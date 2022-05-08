/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:28:07 by romoreir          #+#    #+#             */
/*   Updated: 2022/05/08 19:28:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP01_HUMANB_H
#define CPP01_HUMANB_H

#include "Weapon.h"
#include <iostream>

class HumanB {
    Weapon *_weapon;
    std::string _name;

public:
    HumanB(std::string name);

    ~HumanB();

    void setWeapon(Weapon &weapon);

    void attack() const;
};

#endif //CPP01_HUMANB_H
