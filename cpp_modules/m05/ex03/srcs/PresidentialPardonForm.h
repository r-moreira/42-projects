/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:46:09 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:46:09 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M05_PRESIDENTIALPARDONFORM_H
#define M05_PRESIDENTIALPARDONFORM_H

#include <string>
#include "Bureaucrat.h"

class PresidentialPardonForm : public Form {
public:
    PresidentialPardonForm();

    PresidentialPardonForm(const std::string &_target);

    PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm);

    ~PresidentialPardonForm();

    PresidentialPardonForm &operator=(PresidentialPardonForm const &presidentialPardonForm);

    void execute(Bureaucrat const &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm const &presidentialPardonForm);

#endif //M05_PRESIDENTIALPARDONFORM_H
