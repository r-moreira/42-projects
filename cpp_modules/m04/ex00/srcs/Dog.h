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

#ifndef M04_DOG_H
#define M04_DOG_H

#include "Animal.h"

class Dog : public Animal {
public:
    Dog();

    Dog(const Dog &dog);

    ~Dog();

    Dog &operator=(const Dog &dog);

    void makeSound() const override;
};

#endif //M04_DOG_H
