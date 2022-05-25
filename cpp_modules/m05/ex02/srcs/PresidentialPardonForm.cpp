#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm()
        : Form("PresidentialPardonForm", 25, 5) {
    setTarget("Unknown");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
        : Form("PresidentialPardonForm", 25, 5) {
    setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm)
        : Form("PresidentialPardonForm", 25, 5) {
    *this = presidentialPardonForm;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const {
    try {
        Form::validateExecution(bureaucrat);
    } catch (const GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
        throw GradeTooHighException();
    } catch (const NoSignatureException &e) {
        std::cerr << e.what() << std::endl;
        throw NoSignatureException();
    }
    std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &presidentialPardonForm) {
    setTarget(presidentialPardonForm.getTarget());
    return *this;
}


std::ostream &operator<<(std::ostream &out, PresidentialPardonForm const &presidentialPardonForm) {
    out << "========== FORM ============" << std::endl
        << "Form name:\t" << presidentialPardonForm.getName() << std::endl
        << "Sign status:\t" << presidentialPardonForm.isSigned() << std::endl
        << "Sign grade:\t" << presidentialPardonForm.getSignGrade() << std::endl
        << "Exec grade:\t" << presidentialPardonForm.getExecutionGrade();
    return (out);
}