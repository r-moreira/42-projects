#include <iostream>
#include "Span.h"
#include <ctime>

static void subject_test() {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

static void rangeOfIteratorsTest() {
    Span span = Span(10000);

    std::vector<int> iterator;

    srand(time(NULL));
    for (int i = 0; i <= 10000; i++) {
        iterator.push_back(rand() % 1000000);
    }

    std::vector<int>::iterator start = iterator.begin();
    std::vector<int>::iterator end = iterator.end() - 1;

    span.bulkAddNumber(start, end);

    try {
        std::cout << span.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << span.longestSpan() << std::endl;
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

    span.bulkAddNumber(start, end);
}

static void tooManyElementsExceptionTest() {
    Span sp = Span(2);
    try {
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

static void tooFewElementsExceptionTest() {
    Span sp = Span(9999);

    try {
        sp.addNumber(1);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << sp.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}


int main() {
    std::cout << "===== Subject Test (Check Algorithm) =====" << std::endl;
    subject_test();

    std::cout << "===== TooManyElementsException Test =====" << std::endl;
    tooManyElementsExceptionTest();

    std::cout << "===== TooFewElementsException Test =====" << std::endl;
    tooFewElementsExceptionTest();

    std::cout << "===== Adding many numbers tests (Check Range of Iterators) =====" << std::endl;
    rangeOfIteratorsTest();

    std::cout << "===== Exception when adding many numbers tess (Check Error Handling) =====" << std::endl;
    rangeOfIteratorsExceptionTest();

    return 0;
}
