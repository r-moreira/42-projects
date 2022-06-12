/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:43:26 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:43:26 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M04_WRONGANIMAL_H
#define M04_WRONGANIMAL_H

#include <iostream>

class WrongAnimal {
protected:
    std::string _type;

public:
    WrongAnimal();

    WrongAnimal(const WrongAnimal &wrongAnimal);

    virtual ~WrongAnimal();

    WrongAnimal &operator=(const WrongAnimal &wrongAnimal);

    std::string const &getType() const;

    virtual void makeSound() const;
};

#endif //M04_WRONGANIMAL_H
