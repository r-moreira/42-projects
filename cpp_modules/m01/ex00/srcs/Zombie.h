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


    void announce();
};

Zombie *newZombie(std::string name);

void randomChump(std::string name);

#endif //CPP01_ZOMBIE_H
