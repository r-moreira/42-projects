/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:29:15 by romoreir          #+#    #+#             */
/*   Updated: 2022/05/08 19:29:15 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

Harl::Harl() {

}

Harl::~Harl() {

}

void Harl::complain(std::string level) {
    int i;

    std::string levelOptions[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*levels[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (i = 0; level != levelOptions[i] && i < 4; i++) {}

    (this->*levels[i])();
}

void Harl::debug() {
    std::cout
            << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!"
            << std::endl;
}

void Harl::info() {
    std::cout
            << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!"
            << std::endl;
}

void Harl::warning() {
    std::cout
            << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month."
            << std::endl;
}

void Harl::error() {
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

