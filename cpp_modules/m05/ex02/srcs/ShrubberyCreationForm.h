/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:45:32 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:45:32 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M05_SHRUBBERYCREATIONFORM_H
#define M05_SHRUBBERYCREATIONFORM_H


#include "Bureaucrat.h"
#include <fstream>

class ShrubberyCreationForm : public Form {
private:
    class FormIOException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("Failed to opening the file");
        }
    };

public:
    ShrubberyCreationForm();

    ShrubberyCreationForm(const std::string &_target);

    ShrubberyCreationForm(ShrubberyCreationForm const &shrubberyCreationForm);

    ~ShrubberyCreationForm();

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shrubberyCreationForm);

    void execute(Bureaucrat const &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &shrubberyCreationForm);

#endif //M05_SHRUBBERYCREATIONFORM_H
