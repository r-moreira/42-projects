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

#ifndef M03_FRAGTRAP_H
#define M03_FRAGTRAP_H

#include <string>
#include "ClapTrap.h"

class FragTrap : public ClapTrap {

public:
    FragTrap();

    FragTrap(std::string name);

    FragTrap(FragTrap const &fragTrap);

    ~FragTrap();

    FragTrap &operator=(FragTrap const &fragTrap);

    void highFivesGuys();
};

#endif //M03_FRAGTRAP_H
