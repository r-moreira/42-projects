#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"

int main() {

    std::cout << "========= Bureaucrats ==========" << std::endl << std::endl;

    Bureaucrat foo("Foo", 149);
    Bureaucrat bar("Bar", 70);
    Bureaucrat baz("Baz", 20);
    Bureaucrat qux("Qux", 3);
    Bureaucrat grault("Grault", 1);

    std::cout << foo << std::endl;
    std::cout << bar << std::endl;
    std::cout << baz << std::endl;
    std::cout << qux << std::endl;
    std::cout << grault << std::endl;

    std::cout << "========= PresidentialPardonForm Tests ==========" << std::endl << std::endl;

    PresidentialPardonForm presidentialPardonForm("Thud");
    std::cout << presidentialPardonForm << std::endl;

    std::cout << "======= Sign In Tests ========" << std::endl;
    grault.executeForm(presidentialPardonForm);
    try {
        foo.signForm(presidentialPardonForm);
        bar.signForm(presidentialPardonForm);
        baz.signForm(presidentialPardonForm);
        qux.signForm(presidentialPardonForm);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << presidentialPardonForm << std::endl;

    std::cout << "======= Execute Tests ========" << std::endl;
    try {
        baz.executeForm(presidentialPardonForm);
        qux.executeForm(presidentialPardonForm);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "========= RobotomyRequest Form Tests ==========" << std::endl << std::endl;

    RobotomyRequestForm robotomyRequestForm("Thud");
    std::cout << robotomyRequestForm << std::endl;
    std::cout << "======= Sign In Tests ========" << std::endl;

    grault.executeForm(robotomyRequestForm);
    try {
        foo.signForm(robotomyRequestForm);
        bar.signForm(robotomyRequestForm);
        baz.signForm(robotomyRequestForm);
        qux.signForm(robotomyRequestForm);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << robotomyRequestForm << std::endl;

    std::cout << "======= Execute Tests ========" << std::endl;
    try {
        bar.executeForm(robotomyRequestForm);
        baz.executeForm(robotomyRequestForm);
        qux.executeForm(robotomyRequestForm);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}