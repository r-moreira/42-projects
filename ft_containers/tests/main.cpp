#include <iostream>
#include "../srcs/containers/Vector.hpp"
#include <vector>
#include <cstdlib>

void TEST(const std::string& desc) {
    std::cout << "\033[1;34m#################### "<<desc<<" ####################"<<"\033[0m\n";
}

void TODO() { std::cout << "\033[1;33mTODO\033[0m\n"; }

void OK() { std::cout << "\033[1;32mOK\033[0m\n"; }

void ERR() { std::cout << "\033[1;31mERROR\033[0m\n";}

template<typename T, typename  V> void
ERR(T ft, V std) {
    std::cout << "\033[1;31mERROR\033[0m" << std::endl;
    std::cout << "\tft = " << ft <<  std::endl;
    std::cout << "\tstd: " << std << std::endl;
}

int randomIndex(int max) {
    srand(time(NULL));
    return rand() % max;
}

void vector_constructor_tests() {
    TEST("VECTOR CONSTRUCTOR TESTS");

    int i = 0;

    std::cout << "> Empty Constructor: ";
    ft::vector<double> ftEmpty;
    std::vector<double> stdEmpty;
    OK();

    std::cout << "> Fill Constructor with default value: ";
    ft::vector<double> ft(21);
    std::vector<double> std(21);
    i =  randomIndex(21);
    ft[i] == std[i] ? OK() : ERR(ft[i], std[i]);

    std::cout << "> Fill Constructor with specific value (42): ";
    ft::vector<int> ft2(21, 42);
    std::vector<int> std2(21, 42);
    i =  randomIndex(21);
    ft2[i] == std2[i] ? OK() : ERR(ft2[i], std2[i]);

    std::cout << "> Iterator Constructor Test: ";
    TODO();

    std::cout << "> Copy Constructor Test: ";
    TODO();
}

void vector_element_access_tests() {
    TEST("VECTOR ELEMENT ACCESS TESTS");
    TODO();
}

void vector_operators_tests() {
    TEST("VECTOR OPERATORS TESTS");
    TODO();
}

int main() {
    vector_constructor_tests();
    vector_operators_tests();
    vector_element_access_tests();
    return 0;
}