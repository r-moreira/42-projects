/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:47:37 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:47:37 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M07_WHATEVER_H
#define M07_WHATEVER_H

template<typename T>
void swap(T &a, T &b) {
    T c = a;
    a = b;
    b = c;
}

template<typename T>
T const &min(T const &a, T const &b) {
    return a == b ? b : a < b ? a : b;
}

template<typename T>
T const &max(T const &a, T const &b) {
    return a == b ? b : a > b ? a : b;
}

#endif //M07_WHATEVER_H
