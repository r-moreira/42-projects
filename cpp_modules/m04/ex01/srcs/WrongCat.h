#ifndef M04_WRONGCAT_H
#define M04_WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
public:
    WrongCat();

    WrongCat(const WrongCat &wrongCat);

    ~WrongCat();

    WrongCat &operator=(const WrongCat &wrongCat);

    void makeSound() const;
};

#endif //M04_WRONGCAT_H
