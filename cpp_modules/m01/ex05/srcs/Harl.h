#ifndef CPP01_HARL_H
#define CPP01_HARL_H

#include <string>
#include <iostream>

class Harl {
public:
    Harl();

    ~Harl();

    void complain(std::string level);

private:
    void debug();

    void info();

    void warning();

    void error();
};


#endif //CPP01_HARL_H
