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

#ifndef M04_CAT_H
#define M04_CAT_H

#include "Animal.h"
#include <iostream>

class Cat : public Animal {
public:
    Cat();

    Cat(const Cat &cat);

    ~Cat();

    Cat &operator=(const Cat &cat);

    void makeSound() const;
};

#endif //M04_CAT_H
