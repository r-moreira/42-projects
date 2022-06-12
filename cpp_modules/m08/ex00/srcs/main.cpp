#include <iostream>
#include <vector>
#include <list>
#include "easyfind.h"

template<typename T>
void testOccurrence(T t) {
    for (int i = 0; i <= 42; i++) {
        t.push_back(i);
    }

    easyfind(t, 21);
    easyfind(t, 42);
    easyfind(t, 84);
}

int main() {
    std::cout << "===== Vector Tests =====" << std::endl;
    std::vector<int> v;
    testOccurrence(v);

    std::cout << "===== List Tests =====" << std::endl;
    std::list<int> l;
    testOccurrence(l);

    return 0;
}
