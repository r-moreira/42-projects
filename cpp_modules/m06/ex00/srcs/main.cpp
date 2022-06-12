/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:46:38 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:46:38 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Conversion.h"

int main(int argc, char **argv) {

    if (argc == 1) {
        std::cout << "Error: No argument provided" << std::endl;
        return 1;
    }
    if (argc != 2) {
        std::cout << "Error: More than one argument provided" << std::endl;
        return 1;
    }

    Conversion conversion(argv[1]);

    try {
        conversion.getType();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    conversion.display();
    return 0;
}
