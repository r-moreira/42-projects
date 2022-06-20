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
#include <cmath>

class Fixed {
public:
    Fixed();

    ~Fixed();

    Fixed(const Fixed &origin);

    Fixed(const int param);

    Fixed(const float param);

    int getRawBits() const;

    void setRawBits(int raw);

    float toFloat() const;

    int toInt() const;

    Fixed &operator=(const Fixed &origin);


private:
    int _value;
    static const int _bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &origin);

#endif //M02_FIXED_H
