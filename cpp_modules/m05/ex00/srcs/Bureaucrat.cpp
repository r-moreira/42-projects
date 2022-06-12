/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:44:19 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:44:19 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat) {
    out << "Bureaucrat - name: " << bureaucrat.getName() << ", grade: " << bureaucrat.getGrade();
    return (out);
}

