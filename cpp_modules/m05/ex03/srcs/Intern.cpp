#include "Intern.h"

Intern::Intern() {}

Intern::Intern(const Intern &intern) {
    *this = intern;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &intern) {
    (void) intern;
    return *this;
}

Form *Intern::makePresidentialForm(std::string target) {
    return new PresidentialPardonForm(target);
}

Form *Intern::makeRobotomyForm(std::string target) {
    return new RobotomyRequestForm(target);
}

Form *Intern::makeShrubberyForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

Form *Intern::makeForm(std::string name, std::string target) {
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    Form *(Intern::*f[3])(std::string target) = {
            &Intern::makeShrubberyForm,
            &Intern::makeRobotomyForm,
            &Intern::makePresidentialForm
    };

    for (int i = 0; i < 3; i++) {
        if (name == forms[i]) {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*f[i])(target);
        }
    }
    throw FormNotFoundException();
}
