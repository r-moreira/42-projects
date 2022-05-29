#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"

void testForms(Form *form) {
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
    std::cout << *form << std::endl;

    std::cout << "======= Sign In Tests ========" << std::endl;
    grault.executeForm(*form);
    try {
        foo.signForm(*form);
        bar.signForm(*form);
        baz.signForm(*form);
        qux.signForm(*form);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << *form << std::endl;

    std::cout << "======= Execute Tests ========" << std::endl;
    try {
        foo.executeForm(*form);
        bar.executeForm(*form);
        baz.executeForm(*form);
        qux.executeForm(*form);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

int main() {

    std::cout << "========= PresidentialPardonForm Tests ==========" << std::endl << std::endl;

    PresidentialPardonForm presidentialPardonForm("Thud");
    Form *form = &presidentialPardonForm;
    testForms(form);

    std::cout << std::endl << "========= RobotomyRequest Form Tests ==========" << std::endl << std::endl;

    RobotomyRequestForm robotomyRequestForm("Thud");
    Form *form2 = &robotomyRequestForm;
    testForms(form2);

    return 0;
}