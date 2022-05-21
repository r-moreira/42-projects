
#include "WrongCat.h"

WrongCat::WrongCat() : WrongAnimal() {
    _type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal(wrongCat) {
    _type = wrongCat._type;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &cat) {
    _type = cat._type;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "WRONG MIAU!!!" << std::endl;
}

#include "WrongCat.h"
