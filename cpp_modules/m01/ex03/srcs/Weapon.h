/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:28:21 by romoreir          #+#    #+#             */
/*   Updated: 2022/05/08 19:28:21 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP01_WEAPON_H
#define CPP01_WEAPON_H


#include <string>

class Weapon {
private:
    std::string _type;

public:
    Weapon(const std::string &type);

    ~Weapon();

    const std::string &getType();

    void setType(const std::string &type);
};


#endif //CPP01_WEAPON_H
