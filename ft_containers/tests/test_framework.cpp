#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include "test_framework.h"

void PRINT_TIME(struct timeval& start, struct timeval& end, std::string str)
{
    double start_time, end_time, diff;

    start_time = ((start.tv_sec) * 1000 + start.tv_usec/1000.0);
    end_time   = ((end.tv_sec) * 1000 + end.tv_usec/1000.0);
    diff = end_time - start_time;

    std::cout << str << " : " << diff << " ms" << std::endl;
}

void TEST_SECTION(const std::string& desc) {
    std::cout << "\033[1;34m#################### "<<desc<<" ####################"<<"\033[0m\n";
}

void TEST(const std::string& desc) {
    std::cout << "\033[1;33m> \033[0m" << desc << ": ";
}

void TODO() { std::cout << "\033[1;33mTODO\033[0m\n"; }

void OK() { std::cout << "\033[1;32mOK\033[0m\n"; }

void ERR(const std::string& msg) {
    std::cout << "\033[1;31mERROR: \033[0m" << msg << "\n";
}

int randomIndex(int max) {
    srand(time(NULL));
    return rand() % max;
}