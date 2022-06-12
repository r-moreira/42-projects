/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:48:11 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:48:11 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M08_EASYFIND_H
#define M08_EASYFIND_H

#include <iostream>
#include <algorithm>

class OccurrenceNotFoundException : public std::exception {
public:
    virtual const char *what() const throw() {
        return "No occurrence is found";
    }
};

template<typename T>
void easyfind(T &t, int n) {
    typename T::const_iterator iter;

    iter = std::find(t.begin(), t.end(), n);
    try {
        if (iter == t.end()) {
            throw (OccurrenceNotFoundException());
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return;
    }

    std::cout << "Element occurrence found: " << *iter << std::endl;
}


#endif //M08_EASYFIND_H
