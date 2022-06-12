/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:48:31 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:48:31 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M08_SPAN_H
#define M08_SPAN_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>

class Span {
    class TooManyElementsException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Error: Span cannot accept more elements.";
        }
    };

    class TooFewElementsException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Error: Too few elements to perform this operation.";
        }
    };

private:
    unsigned int _n;
    std::vector<int> _vect;

public:

    Span();

    Span(unsigned int n);

    Span(Span const &span);

    ~Span();

    Span &operator=(Span const &span);

    void addNumber(int n);

    int shortestSpan() const;

    int longestSpan() const;

    void bulkAddNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
};


#endif //M08_SPAN_H
