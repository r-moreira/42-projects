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

#ifndef M03_SCAVTRAP_H
#define M03_SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap {

public:
    ScavTrap();

    ScavTrap(std::string name);

    ScavTrap(ScavTrap const &scavTrap);

    ~ScavTrap();

    ScavTrap &operator=(ScavTrap const &scavTrap);

    void attack(std::string const &target);

    void guardGate() const;
};


#endif //M03_SCAVTRAP_H
