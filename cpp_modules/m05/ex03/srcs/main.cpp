/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:46:02 by romoreir          #+#    #+#             */
/*   Updated: 2022/06/11 23:46:03 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include "Intern.h"

void testForms(Form *form) {
    Bureaucrat foo("Foo", 149);
    Bureaucrat bar("Bar", 70);
    Bureaucrat baz("Baz", 20);
    Bureaucrat qux("Qux", 3);
    Bureaucrat grault("Grault", 1);

    std::cout << foo << std::endl;
    std::cout << bar << std::endl;
    std::cout << baz << std::endl;
    std::cout << qux << std::endl;
    std::cout << grault << std::endl;
    std::cout << *form << std::endl;

    std::cout << "======= Sign In Tests ========" << std::endl;
    grault.executeForm(*form);
    try {
        foo.signForm(*form);
        bar.signForm(*form);
        baz.signForm(*form);
        qux.signForm(*form);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << *form << std::endl;

    std::cout << "======= Execute Tests ========" << std::endl;
    try {
        foo.executeForm(*form);
        bar.executeForm(*form);
        baz.executeForm(*form);
        qux.executeForm(*form);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

int main() {

    Intern intern;
    Form *form;

    std::cout << "========= PresidentialPardonForm Tests ==========" << std::endl << std::endl;

    try {
        form = intern.makeForm("presidential pardon", "thud");
        testForms(form);
        delete form;
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "========= RobotomyRequest Form Tests ==========" << std::endl << std::endl;

    try {
        form = intern.makeForm("presidential pardon", "thud2");
        testForms(form);
        delete form;
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "========= ShrubberyCreation Form Tests ==========" << std::endl << std::endl;

    try {
        form = intern.makeForm("shrubbery creation", "thud3");
        testForms(form);
        delete form;
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "========= Intern Not Found Form Test ==========" << std::endl << std::endl;
    try {
        form = intern.makeForm("Unknown Form", "thud4");
        testForms(form);
        delete form;
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
