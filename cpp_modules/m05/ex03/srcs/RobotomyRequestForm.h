/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:46:17 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:46:17 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M05_ROBOTOMYREQUESTFORM_H
#define M05_ROBOTOMYREQUESTFORM_H

#include <cstdlib>
#include <string>
#include "Bureaucrat.h"

class RobotomyRequestForm : public Form {
private:
    class RobotomyException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("Robotomy failed");
        }
    };

public:

    RobotomyRequestForm();

    RobotomyRequestForm(const std::string &_target);

    RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm);

    ~RobotomyRequestForm();

    RobotomyRequestForm &operator=(const RobotomyRequestForm &robotomyRequestForm);

    void execute(Bureaucrat const &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &robotomyRequestForm);

#endif //M05_ROBOTOMYREQUESTFORM_H
