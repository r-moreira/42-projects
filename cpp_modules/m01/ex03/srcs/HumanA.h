/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:27:39 by romoreir          #+#    #+#             */
/*   Updated: 2022/05/08 19:27:39 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP01_HUMANA_H
#define CPP01_HUMANA_H

#include "Weapon.h"
#include <iostream>

class HumanA {
private:
    Weapon &_weapon;
    std::string _name;

public:
    HumanA(std::string name, Weapon &weapon);

    ~HumanA();

    void attack();

private:
    std::string name;

};


#endif //CPP01_HUMANA_H
