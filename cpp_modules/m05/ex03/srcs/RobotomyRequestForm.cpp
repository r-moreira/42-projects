/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:46:14 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:46:14 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm()
        : Form("RobotomyRequestForm", 72, 45) {
    setTarget("Unknown");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &_target)
        : Form("RobotomyRequestForm", 72, 45) {
    setTarget(_target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm)
        : Form("RobotomyRequestForm", 72, 45) {
    *this = robotomyRequestForm;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomyRequestForm) {
    setTarget(robotomyRequestForm.getTarget());
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const {
    try {
        Form::validateExecution(bureaucrat);
    } catch (const GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
        throw GradeTooHighException();
    } catch (const NoSignatureException &e) {
        std::cerr << e.what() << std::endl;
        throw NoSignatureException();
    }

    std::cout << "L O U D   D R I L L I N G   N O I S E S!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;

    srand(time(NULL));
    if (rand() % 2)
        std::cout << getTarget() << " has been robotomized" << std::endl;
    else
        throw RobotomyException();
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &robotomyRequestForm) {
    out << "========== FORM ============" << std::endl
        << "Form name:\t" << robotomyRequestForm.getName() << std::endl
        << "Sign status:\t" << robotomyRequestForm.isSigned() << std::endl
        << "Sign grade:\t" << robotomyRequestForm.getSignGrade() << std::endl
        << "Exec grade:\t" << robotomyRequestForm.getExecutionGrade();
    return (out);
}
