/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:43:47 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:43:47 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M04_BRAIN_H
#define M04_BRAIN_H

#include <iostream>
#include <string>

class Brain {
public:
    Brain();

    Brain(Brain const &brain);

    ~Brain();

    Brain &operator=(Brain const &brain);

private:
    std::string _ideas[100];

};

#endif //M04_BRAIN_H
