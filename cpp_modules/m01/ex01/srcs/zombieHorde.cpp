/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:27:06 by romoreir          #+#    #+#             */
/*   Updated: 2022/05/08 19:27:06 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.h"

Zombie *zombieHorde(int N, std::string name) {
    Zombie *horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
        horde[i].announce();
    }
    return horde;
}
