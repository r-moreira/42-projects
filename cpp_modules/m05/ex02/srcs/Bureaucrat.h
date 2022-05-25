#ifndef M05_BUREAUCRAT_H
#define M05_BUREAUCRAT_H

#include <string>
#include <iostream>
#include "Form.h"

class Form;

class Bureaucrat {

private:
    const std::string _name;
    unsigned int _grade;

public:

    class GradeTooHighException : public std::exception {
    public:
        GradeTooHighException() {}

        ~GradeTooHighException() throw() {}

        const char *what() const throw() {
            return ("Grade must not exceed level 1");
        }

    private:
        std::string _msg;
    };

    class GradeTooLowException : public std::exception {
    public:
        GradeTooLowException() {}

        ~GradeTooLowException() throw() {}

        const char *what() const throw() {
            return ("Grade must not going below level 150");
        }

    private:
        std::string _msg;
    };

public:
    Bureaucrat();

    Bureaucrat(const std::string &name, int grade);

    Bureaucrat(Bureaucrat const &bureaucrat);

    ~Bureaucrat();

    Bureaucrat &operator=(Bureaucrat const &bureaucrat);

    const std::string &getName() const;

    unsigned int getGrade() const;

    void incrementLevel() throw(GradeTooHighException);

    void decrementLevel() throw(GradeTooLowException);

    void signForm(Form &form);

    void executeForm(Form const &form);
};

std::ostream &operator<<(std::ostream &s, Bureaucrat &bureaucrat);


#endif //M05_BUREAUCRAT_H
