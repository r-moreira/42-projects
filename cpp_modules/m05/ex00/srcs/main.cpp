#include "Bureaucrat.h"

int main() {
    Bureaucrat bureaucrat1("Number One", 149);
    Bureaucrat bureaucrat2("Number Two", 2);
    
    std::cout << "-------- Decrement Test ------------- " << std::endl;
    try {
        std::cout << bureaucrat1 << std::endl;
        bureaucrat1.decrementLevel();
        std::cout << bureaucrat1 << std::endl;
        bureaucrat1.decrementLevel();
        std::cout << bureaucrat1 << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "-------- Increment Test ------------- " << std::endl;
    try {
        std::cout << bureaucrat2 << std::endl;
        bureaucrat2.incrementLevel();
        std::cout << bureaucrat2 << std::endl;
        bureaucrat2.incrementLevel();
        std::cout << bureaucrat2 << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "-------- Bureaucrat State ------------- " << std::endl;
    std::cout << bureaucrat1 << std::endl;
    std::cout << bureaucrat2 << std::endl;
    return 0;
}