/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:25:51 by romoreir          #+#    #+#             */
/*   Updated: 2022/05/08 19:25:51 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main() {
    randomChump("Alfredo");

    Zombie *zombie = newZombie("Astolfo");
    zombie->announce();

    delete zombie;
    return (0);
}
