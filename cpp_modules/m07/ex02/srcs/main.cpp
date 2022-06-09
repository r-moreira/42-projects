#include <iostream>
#include "Array.tpp"
#include <cstdlib>
#include <ctime>

void testArrayIndexOperatorValues(const int &len) {

    Array<int> myArray(len);
    int *cppArray = new int[len];

    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        const int value = rand();
        myArray[i] = value;
        cppArray[i] = value;
    }

    for (int i = 0; i < len; i++) {
        if (myArray[i] != cppArray[i]) {
            std::cerr << "Error: Arrays have different values for same index" << std::endl;
            exit(1);
        }
    }

    std::cout << "Success: Both arrays have same vales for the same index" << std::endl;
}

void testArrayException() {
    Array<int> array(5);

    try {
        array[6] = 0;
    } catch (const std::exception &e) {
        std::cout << "Success: Array throw an exception" << std::endl;
    }
}

void testSizeFunction() {
    Array<char> array(42);

    if (array.size() == 42) {
        std::cout << "Success: Array has correct size" << std::endl;
    } else {
        std::cerr << "Error: Array has an invalid size" << std::endl;
    }
}

void testChangeSpecficIndexValue() {
    Array<float> array(3);

    array[2] = 42.0f;

    if (array[2] == 42.0f) {
        std::cout << "Success: Array index has correct value" << std::endl;
    } else {
        std::cerr << "Error: Array has an incorrect value" << std::endl;
    }
}

void testArrayCopy() {
    Array<int> array = Array<int>(5);
    Array<int> arrayCopy(array);;

    array[2] = 42;
    if (arrayCopy[2] != 42) {
        std::cout << "Success: Array copy not changed" << std::endl;
    } else {
        std::cerr << "Error: Array has changed" << std::endl;
    }
}

void testEmptyConstructor() {
    Array<std::string> array = Array<std::string>();

    if (array.size() == 0) {
        std::cout << "Success: Empty constructor has initialized an empty array" << std::endl;
    } else {
        std::cerr << "Error: Empty constructor has not initialized an empty array" << std::endl;
    }
}

int main(int, char **) {
    testArrayIndexOperatorValues(1000);
    testArrayException();
    testSizeFunction();
    testChangeSpecficIndexValue();
    testArrayCopy();
    testEmptyConstructor();

    return 0;
}