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

    bool operator>(const Fixed &origin) const;

    bool operator<(const Fixed &origin) const;

    bool operator>=(const Fixed &origin) const;

    bool operator<=(const Fixed &origin) const;

    bool operator==(const Fixed &origin) const;

    bool operator!=(const Fixed &origin) const;

    Fixed operator+(const Fixed &origin) const;

    Fixed operator-(const Fixed &origin) const;

    Fixed operator*(const Fixed &origin) const;

    Fixed operator/(const Fixed &origin) const;

    Fixed operator--(int);

    Fixed &operator--();

    Fixed operator++(int);

    Fixed &operator++();

    static Fixed &min(Fixed &f1, Fixed &f2);

    static Fixed &max(Fixed &f1, Fixed &f2);

    static const Fixed &min(Fixed const &f1, Fixed const &f2);

    static const Fixed &max(Fixed const &f1, Fixed const &f2);

private:
    int _value;
    static const int _bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &origin);

#endif //M02_FIXED_H
