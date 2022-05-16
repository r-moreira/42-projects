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

#include "ScavTrap.h"
#include "FragTrap.h"

int main() {
    ScavTrap r2d2("R2D2");
    FragTrap c3p0("C3P0");

    c3p0.highFivesGuys();
    r2d2.attack("C3P0");
    c3p0.takeDamage(r2d2.getAttackDamage());
    r2d2.guardGate();
}