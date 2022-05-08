/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:26:44 by romoreir          #+#    #+#             */
/*   Updated: 2022/05/08 19:26:44 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main() {
    Zombie *horde;

    horde = zombieHorde(9, "Alfredo");

    delete[] horde;
    return (0);
}
