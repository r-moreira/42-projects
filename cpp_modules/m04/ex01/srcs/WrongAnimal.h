#ifndef M04_WRONGANIMAL_H
#define M04_WRONGANIMAL_H

#include <iostream>

class WrongAnimal {
protected:
    std::string _type;

public:
    WrongAnimal();

    WrongAnimal(const WrongAnimal &wrongAnimal);

    virtual ~WrongAnimal();

    WrongAnimal &operator=(const WrongAnimal &wrongAnimal);

    std::string const &getType() const;

    virtual void makeSound() const;
};

#endif //M04_WRONGANIMAL_H
