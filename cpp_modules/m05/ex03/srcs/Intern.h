#ifndef INC_42_PROJECTS_INTERN_H
#define INC_42_PROJECTS_INTERN_H

#include <string>
#include "Form.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

class Intern {
private:
    class FormNotFoundException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("Form not found");
        }
    };

public:
    Intern();

    Intern(Intern const &intern);

    ~Intern();

    Intern &operator=(Intern const &intern);

    Form *makeForm(std::string name, std::string target);

private:
    Form *makePresidentialForm(std::string target);

    Form *makeRobotomyForm(std::string target);

    Form *makeShrubberyForm(std::string target);
};


#endif //INC_42_PROJECTS_INTERN_H
