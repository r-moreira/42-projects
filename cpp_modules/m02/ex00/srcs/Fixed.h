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

#ifndef M02_FIXED_H
#define M02_FIXED_H

#include <iostream>

class Fixed {
public:
    Fixed();

    ~Fixed();

    Fixed(const Fixed &origin);

    int getRawBits() const;

    void setRawBits(int raw);

    Fixed &operator=(const Fixed &origin);

private:
    int value{};
    static const int n_bits = 8;
};

#endif //M02_FIXED_H
