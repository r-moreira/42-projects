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

#ifndef M04_ANIMAL_H
#define M04_ANIMAL_H

#include <iostream>

class Animal {
protected:
    std::string _type;

public:
    Animal();

    virtual ~Animal();

    Animal(const Animal &animal);

    Animal &operator=(const Animal &animal);

    std::string const &getType() const;

    virtual void makeSound() const;
};

#endif //M04_ANIMAL_H
