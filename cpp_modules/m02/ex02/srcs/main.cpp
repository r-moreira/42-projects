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

#include <iostream>
#include "Fixed.h"

int main() {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    std::cout << "\nAnother tests" << std::endl;

    Fixed c(42);
    Fixed d(42.21f);
    std::cout << std::endl << "c: " << c << " d: " << d << std::endl;
    std::cout << "c / d: " << c / d << std::endl;
    std::cout << "c * d: " << c * d << std::endl;
    std::cout << "c + d: " << c + d << std::endl;
    std::cout << "c - d: " << c - d << std::endl;

    if (c < d) {
        std::cout << "c < d == true" << std::endl;
    }

    if (!(c > d)) {
        std::cout << "c > d == false" << std::endl;
    }

    if ((c <= 42)) {
        std::cout << "c <= d == true" << std::endl;
    }

    if (c >= 42) {
        std::cout << "c >= d == true" << std::endl;
    }

    if (c != d) {
        std::cout << "c != d == true" << std::endl;
    }

    if (!(c == d)) {
        std::cout << "c == d false" << std::endl;
    }
}