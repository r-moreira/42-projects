#include <iostream>
#include <vector>
#include <list>
#include "MutantStack.h"

static void subjectTest() {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
}

static void compareMutantStackTests() {

    MutantStack<int, std::vector<int> > mstack;
    mstack.push(21);
    mstack.push(42);
    mstack.push(84);

    MutantStack<int, std::vector<int> >::iterator msIt = mstack.begin();
    MutantStack<int, std::vector<int> >::iterator msIte = mstack.end();


    std::list<int> compareList;
    compareList.push_back(21);
    compareList.push_back(42);
    compareList.push_back(84);

    std::list<int>::iterator lstIt = compareList.begin();
    std::list<int>::iterator lstIte = compareList.end();

    std::cout << "> Mutant Stack Output:" << std::endl;
    while (msIt != msIte) {
        std::cout << *msIt << std::endl;
        msIt++;
    }

    std::cout << "> List Output:" << std::endl;
    while (lstIt != lstIte) {
        std::cout << *lstIt << std::endl;
        lstIt++;
    }

}

int main() {
    std::cout << "===== Subject Tests =====" << std::endl;
    subjectTest();

    std::cout << "===== Compare Tests =====" << std::endl;
    compareMutantStackTests();
    return 0;
}
