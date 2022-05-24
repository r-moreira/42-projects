#include "Form.h"

Form::Form() : _name("unknown"), _signGrade(0), _executionGrade(0) {
    _signed = false;
}

Form::Form(const std::string &name, const unsigned int signGrade, const unsigned int executionGrade)
        : _name(name), _signGrade(signGrade), _executionGrade(executionGrade) {
    _signed = false;
    if (signGrade > 150 || executionGrade > 150) {
        throw Form::GradeTooHighException();
    }
    if (signGrade < 1 || executionGrade < 1) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const Form &form) :
        _name(form.getName()),
        _signGrade(form.getSignGrade()),
        _executionGrade(form.getExecutionGrade()) {
    *this = form;
}

Form &Form::operator=(const Form &form) {
    _signed = form.isSigned();
    return (*this);
}

Form::~Form() {}

void Form::beSigned(const Bureaucrat &bureaucrat) throw(GradeTooLowException) {
    if (bureaucrat.getGrade() <= getSignGrade()) {
        _signed = true;
    } else {
        throw Form::GradeTooLowException();
    }
}

const std::string &Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _signed;
}

unsigned int Form::getSignGrade() const {
    return _signGrade;
}

unsigned int Form::getExecutionGrade() const {
    return _executionGrade;
}

std::ostream &operator<<(std::ostream &out, Form &form) {
    out << "========== FORM ============" << std::endl
        << "Form name:\t" << form.getName() << std::endl
        << "Sign status:\t" << form.isSigned() << std::endl
        << "Sign grade:\t" << form.getSignGrade() << std::endl
        << "Exec grade:\t" << form.getExecutionGrade();
    return (out);
}