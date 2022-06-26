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

#ifndef M03_CLAPTRAP_H
#define M03_CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap {

protected:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

public:
    ClapTrap();

    ClapTrap(std::string _name);

    ClapTrap(const ClapTrap &ct);

    virtual ~ClapTrap();

    virtual void attack(std::string const &target);

    void takeDamage(unsigned int amount);

    void beRepaired(unsigned int amount);

    ClapTrap &operator=(const ClapTrap &ct);

    void setName(std::string name);

    void setHitPoints(unsigned int amount);

    void setEnergyPoints(unsigned int amount);

    void setAttackDamage(unsigned int amount);

    std::string getName() const;

    unsigned int getHitPoints() const;

    unsigned int getEnergyPoints() const;

    unsigned int getAttackDamage() const;
};

#endif //M03_CLAPTRAP_H
