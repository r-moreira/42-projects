#ifndef CPP01_ZOMBIE_H
#define CPP01_ZOMBIE_H

#include <string>
#include <iostream>

class Zombie {

private:
    std::string _name;

public:

    Zombie();

    Zombie(const std::string &name);

    ~Zombie();

    const std::string &getName() const;

    void setName(const std::string &name);

    void announce();
};

Zombie *zombieHorde(int N, std::string name);

#endif //CPP01_ZOMBIE_H
