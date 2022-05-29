#ifndef M05_FORM_H
#define M05_FORM_H

#include <string>
#include <iostream>
#include "Bureaucrat.h"

class Bureaucrat;

class Form {

protected:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("Grade too high");
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("Grade too low");
        }
    };

    class NoSignatureException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("No signature to execute this operation");
        }
    };


private:
    const std::string _name;
    bool _signed;
    const unsigned int _signGrade;
    const unsigned int _executionGrade;
    std::string _target;

public:
    Form();

    Form(const std::string &name, unsigned int signGrade, unsigned int executionGrade);

    Form(const Form &form);

    virtual ~Form();

    Form &operator=(const Form &form);

    void beSigned(const Bureaucrat &bureaucrat) throw(GradeTooLowException);

    const std::string &getName() const;

    bool isSigned() const;

    unsigned int getSignGrade() const;

    unsigned int getExecutionGrade() const;

    const std::string &getTarget() const;

    void setTarget(const std::string &target);

    void validateExecution(Bureaucrat const &bureaucrat) const throw(GradeTooLowException, NoSignatureException);

    virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &s, Form &form);

#endif //M05_FORM_H
