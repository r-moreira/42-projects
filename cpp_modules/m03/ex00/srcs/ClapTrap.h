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

private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

public:
    ClapTrap();

    ClapTrap(std::string _name);

    ClapTrap(const ClapTrap &ct);

    virtual ~ClapTrap();

    void attack(std::string const &target);

    void takeDamage(unsigned int amount);

    void beRepaired(unsigned int amount);

    ClapTrap &operator=(const ClapTrap &ct);
};

#endif //M03_CLAPTRAP_H
