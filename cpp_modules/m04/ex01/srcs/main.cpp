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

#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include <iostream>

int main() {
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    delete j;//should not create a leak
    delete i;

    //More tests
    std::cout << std::endl;
    const Animal *animals[4];
    for (int len = 0; len < 4; len++) {
        if (len % 2)
            animals[len] = new Dog();
        else
            animals[len] = new Cat();
    }
    std::cout << std::endl;
    for (int len = 0; len < 4; len++) {
        delete animals[len];
    }
    return 0;
}
