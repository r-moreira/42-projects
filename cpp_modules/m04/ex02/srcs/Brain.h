#ifndef M04_BRAIN_H
#define M04_BRAIN_H

#include <iostream>
#include <string>

class Brain {
public:
    Brain();

    Brain(Brain const &brain);

    ~Brain();

    Brain &operator=(Brain const &brain);

private:
    std::string _ideas[100];

};

#endif //M04_BRAIN_H
