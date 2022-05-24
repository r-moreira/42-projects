#ifndef M05_FORM_H
#define M05_FORM_H

#include <string>
#include <iostream>
#include "Bureaucrat.h"

class Bureaucrat;

class Form {
    class GradeTooHighException : public std::exception {
    public:
        GradeTooHighException() {}

        ~GradeTooHighException() throw() {}

        const char *what() const throw() {
            return ("Grade too high");
        }

    private:
        std::string _msg;
    };

    class GradeTooLowException : public std::exception {
    public:
        GradeTooLowException() {}

        ~GradeTooLowException() throw() {}

        const char *what() const throw() {
            return ("Grade too low");
        }

    private:
        std::string _msg;
    };


private:
    const std::string _name;
    bool _signed;
    const unsigned int _signGrade;
    const unsigned int _executionGrade;

public:
    Form();

    Form(const std::string &name, unsigned int signGrade, unsigned int executionGrade);

    Form(const Form &form);

    ~Form();

    Form &operator=(const Form &form);

    void beSigned(const Bureaucrat &bureaucrat) throw(GradeTooLowException);

    const std::string &getName() const;

    bool isSigned() const;

    unsigned int getSignGrade() const;

    unsigned int getExecutionGrade() const;
};

std::ostream &operator<<(std::ostream &s, Form &form);

#endif //M05_FORM_H
