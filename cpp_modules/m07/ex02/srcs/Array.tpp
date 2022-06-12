/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:47:54 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:47:54 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M07_ARRAY_TPP
#define M07_ARRAY_TPP

#include <exception>
#include <iostream>

template<typename T>
class Array {
private:
    unsigned int _n;
    T *_data;

public:
    Array() : _n(0), _data(0) {};

    Array(unsigned int n) : _n(n), _data(new T[n]()) {
        for (unsigned int i = 0; i < n; i++) {
            this->_data[i] = 0;
        }
    };

    Array(Array const &array) : _n(array.size()), _data(new T[this->_n]()) {
        *this = array;
    };

    ~Array() {
        if (this->_data) {
            delete[] this->_data;
        }
    }

    Array &operator=(Array const &array) {
        delete[] this->_data;

        this->_data = new T[array._n];
        this->_n = array._n;

        for (unsigned int i = 0; i < array._n; i++)
            this->_data[i] = array._data[i];

        return *this;
    }

    T &operator[](unsigned int n) {
        if (n >= _n || n < 0) {
            throw IndexOutOfBoundsException();
        }
        return (_data[n]);
    }

    unsigned int size() const {
        return (_n);
    };

    class IndexOutOfBoundsException : public std::exception {
    public:
        const char *what() const throw() {
            return "Error: Array Overflow due to invalid memory access";
        }
    };
};

#endif //M07_ARRAY_TPP
