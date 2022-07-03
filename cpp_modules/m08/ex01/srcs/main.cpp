/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:48:24 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:48:24 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.h"
#include <ctime>

static void subjectTest() {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Sucess! Got the shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Sucess! Got the longest span: " << sp.longestSpan() << std::endl;
}

static void tooManyElementsExceptionTest() {
    Span sp = Span(2);
    try {
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
    } catch (const std::exception &e) {
		std::cout << "Success! Got TooManyElementsException, with message -> " << e.what() << std::endl;
    }
}


static void tooFewElementsExceptionTest() {
    Span sp = Span(9999);

    try {
        sp.addNumber(1);
    } catch (const std::exception &e) {
		std::cout << "Failure! Must not catch any exception" << std::endl;
	}

    try {
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
   		std::cout << "Success! Got TooFewElementsException, with message -> " << e.what() << std::endl;
    }

    try {
        std::cout << sp.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
  		std::cout << "Success! Got TooFewElementsException, with message -> " << e.what() << std::endl;
    }
}

static void rangeOfIteratorsTest() {
    std::cout << "> Span of 10" << std::endl;	
	Span span = Span(10);
    std::vector<int> iterator;

    srand(time(NULL));
    for (int i = 0; i <= 10; i++) {
        iterator.push_back(rand() % 1000000000000);
    }

    std::vector<int>::iterator start = iterator.begin();
    std::vector<int>::iterator end = iterator.end() - 1;

    span.bulkAddNumber(start, end);

    try {
        std::cout << "Sucess! Got the shortest span: " << span.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "Sucess! Got the longest span: " << span.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


    std::cout << "> Span of 10000" << std::endl;
  	Span span10k = Span(10000);
    std::vector<int> iterator10k;

    for (int i = 0; i < 10000; i++) {
        iterator10k.push_back(rand() % 1000000000000);
    }

    std::vector<int>::iterator start10k = iterator10k.begin();
    std::vector<int>::iterator end10k = iterator10k.end() - 1;

    span10k.bulkAddNumber(start10k, end10k);

    try {
        std::cout << "Sucess! Got the shortest span: " << span10k.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "Sucess! Got the longest span: " << span10k.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

static void rangeOfIteratorsExceptionTest() {
    Span span = Span(10);

    std::vector<int> iterator;

    srand(time(NULL));
    for (int i = 0; i <= 100; i++) {
        iterator.push_back(rand() % 100);
    }

    std::vector<int>::iterator start = iterator.begin();
    std::vector<int>::iterator end = iterator.end() - 1;
   
    try {
  		span.bulkAddNumber(start, end);
    } catch (const std::exception &e) {
		std::cout << "Success! Got TooManyElementsException for range of iterators, with message -> " << e.what() << std::endl;
    }
}

int main() {
    std::cout << std::endl << "===== Subject Test (Check Algorithm) =====" << std::endl;
    subjectTest();

    std::cout << std::endl << "===== TooManyElementsException Test =====" << std::endl;
    tooManyElementsExceptionTest();

    std::cout << std::endl << "===== TooFewElementsException Test =====" << std::endl;
    tooFewElementsExceptionTest();

    std::cout << std::endl << "===== Adding many numbers tests (Check range of iterators algorithm) =====" << std::endl;
    rangeOfIteratorsTest();

    std::cout << std::endl << "===== TooManyElementsException for range of iterators =====" << std::endl;
    rangeOfIteratorsExceptionTest();

    return 0;
}
