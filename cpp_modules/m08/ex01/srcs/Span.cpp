/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:48:28 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:48:28 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"

Span::Span() {

}

Span::Span(unsigned int const n) : _n(n) {

}

Span::~Span() {
}

Span::Span(Span const &span) {
    *this = span;
}

Span &Span::operator=(Span const &span) {
    _n = span._n;
    _vect = span._vect;
    return *this;
}

void Span::addNumber(const int n) {
    if (_vect.size() >= _n) {
        throw Span::TooManyElementsException();
    }
    _vect.push_back(n);
}

void Span::bulkAddNumber(std::vector<int>::iterator start, std::vector<int>::iterator end) {
    try {
        while (start != end) {
            addNumber(*start);
            start++;
        }
        _vect.push_back(*end);

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}


int Span::shortestSpan() const {
    if (_vect.size() < 2) {
        throw TooFewElementsException();
    }

    int dist;
    int shortest = abs(_vect[1] - _vect[0]);

    for (unsigned long int i = 0; i < this->_vect.size(); i++) {
        for (unsigned long int y = i + 1; y < _vect.size(); y++) {
            dist = abs(_vect[y] - _vect[i]);
            dist < shortest ? shortest = dist : shortest;
        }
    }

    return shortest;
}

int Span::longestSpan() const {
    if (_vect.size() < 2) {
        throw TooFewElementsException();
    }

    int dist;
    int longest = abs(_vect[1] - _vect[0]);

    for (unsigned long int i = 0; i < _vect.size(); i++) {
        for (unsigned long int y = i + 1; y < _vect.size(); y++) {
            dist = abs(_vect[y] - _vect[i]);
            dist > longest ? longest = dist : longest;
        }
    }

    return longest;
}
