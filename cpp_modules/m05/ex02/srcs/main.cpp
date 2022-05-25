#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"

int main() {

    std::cout << "========= PresidentialPardonForm Tests ==========" << std::endl << std::endl;

    Bureaucrat foo("Foo", 149);
    Bureaucrat bar("Bar", 70);
    Bureaucrat baz("Baz", 20);
    Bureaucrat qux("Qux", 3);
    Bureaucrat grault("Grault", 1);

    PresidentialPardonForm presidentialPardonForm("Thud");

    std::cout << foo << std::endl;
    std::cout << bar << std::endl;
    std::cout << baz << std::endl;
    std::cout << qux << std::endl;
    std::cout << grault << std::endl;
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

    std::cout << "===================================" << std::endl;
    return 0;
}