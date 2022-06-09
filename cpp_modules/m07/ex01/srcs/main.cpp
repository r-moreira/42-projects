#include <iostream>
#include "iter.h"

template<typename T>
void print(T const i) {
    std::cout << i << std::endl;
}

int main() {
    std::cout << "----- Integer Array -----" << std::endl;
    int integerArray[3] = {21, 42, 84};
    iter(integerArray, 3, print);


    std::cout << "----- String Array -----" << std::endl;
    std::string stringArray[5] = {"first", "second", "third", "fourth", "fifth"};
    iter(stringArray, 3, print);

    return 0;
}

