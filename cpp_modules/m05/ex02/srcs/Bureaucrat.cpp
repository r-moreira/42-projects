#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
    if (grade > 150) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }

    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) :
        _name(bureaucrat.getName()),
        _grade(bureaucrat.getGrade()) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
    _grade = bureaucrat.getGrade();
    return *this;
}

const std::string &Bureaucrat::getName() const {
    return _name;
}

unsigned int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementLevel() throw(GradeTooHighException) {
    if (_grade == 1) {
        throw GradeTooHighException();
    } else {
        _grade--;
    }
}

void Bureaucrat::decrementLevel() throw(GradeTooLowException) {
    if (_grade == 150) {
        throw GradeTooLowException();
    } else {
        _grade++;
    }
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
    } catch (const std::exception &e) {
        std::cerr << _name
                  << " cannot sign "
                  << form.getName()
                  << " because: "
                  << e.what()
                  << std::endl;
        return;
    }
    std::cout << _name
              << " signed "
              << form.getName()
              << std::endl;
}

void Bureaucrat::executeForm(const Form &form) {
    try {
        form.execute(*this);
    }
    catch (const std::exception &e) {
        std::cerr << _name
                  << " cannot execute "
                  << form.getName()
                  << " because "
                  << e.what()
                  << std::endl;
        return;
    }
    std::cout << _name
              << " executed "
              << form.getName()
              << std::endl;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat) {
    out << "======== Bureaucrat ========" << std::endl
        << "Name:\t" << bureaucrat.getName() << std::endl
        << "Grade:\t" << bureaucrat.getGrade();
    return (out);
}

