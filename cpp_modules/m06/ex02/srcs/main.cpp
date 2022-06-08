#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Base.h"
#include "C.h"
#include "B.h"
#include "A.h"

Base *sortClass() {
    srand(time(NULL));
    switch (rand() % 3) {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        default:
            return NULL;
    }
}

void getType(Base &base) {
    try {
        (void) dynamic_cast<A &>(base);
        std::cout << "Type &: A" << std::endl;
    }
    catch (const std::exception &e) {
    }
    try {
        (void) dynamic_cast<B &>(base);
        std::cout << "Type &: B" << std::endl;
    }
    catch (const std::exception &e) {
    }
    try {
        (void) dynamic_cast<C &>(base);
        std::cout << "Type &: C" << std::endl;
    }
    catch (const std::exception &e) {
    }
}

void getType(Base *base) {
    if (dynamic_cast<A *>(base)) {
        std::cout << "Type *: A" << std::endl;
    }
    if (dynamic_cast<B *>(base)) {
        std::cout << "Type *: B" << std::endl;
    }
    if (dynamic_cast<C *>(base)) {
        std::cout << "Type *: C" << std::endl;
    }
}

int main() {
    Base *randomClass;

    randomClass = sortClass();
    getType(randomClass);
    getType(*randomClass);

    delete randomClass;
    return 0;
}