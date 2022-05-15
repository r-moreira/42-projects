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

#include <iostream>
#include "ClapTrap.h"

int main() {
    ClapTrap r2d2("R2D2");
    ClapTrap c3p0("C3P0");

    std::cout << std::endl;

    r2d2.attack("C3P0");
    c3p0.takeDamage(0);
    c3p0.beRepaired(4);

    std::cout << std::endl;

    c3p0.attack("R2D2");
    r2d2.takeDamage(0);
    r2d2.beRepaired(2);

    std::cout << std::endl;
}