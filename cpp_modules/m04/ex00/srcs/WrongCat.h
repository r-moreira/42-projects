/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:43:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:43:00 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M04_WRONGCAT_H
#define M04_WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
public:
    WrongCat();

    WrongCat(const WrongCat &wrongCat);

    ~WrongCat();

    WrongCat &operator=(const WrongCat &wrongCat);

    void makeSound() const;
};

#endif //M04_WRONGCAT_H
