#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm()
        : Form("ShrubberyCreationForm", 145, 137) {
    setTarget("Unknown");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &_target)
        : Form("ShrubberyCreationForm", 145, 137) {
    setTarget(_target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm)
        : Form("ShrubberyCreationForm", 145, 137) {
    *this = shrubberyCreationForm;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyCreationForm) {
    setTarget(shrubberyCreationForm.getTarget());
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const {
    try {
        Form::validateExecution(bureaucrat);
    } catch (const GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
        throw GradeTooHighException();
    } catch (const NoSignatureException &e) {
        std::cerr << e.what() << std::endl;
        throw NoSignatureException();
    }

    std::ofstream outf;
    std::string fname = this->getTarget() + "_shrubbery";
    outf.open(fname.c_str(), std::ios::app);

    if (!outf.is_open()) {
        throw FormIOException();
    }
    
    outf
            << "     /\\" << std::endl
            << "     /\\ " << std::endl
            << "    /  \\ " << std::endl
            << "    /~~\\o " << std::endl
            << "   /o   \\ " << std::endl
            << "  /~~*~~~\\ " << std::endl
            << " o/    o \\ " << std::endl
            << " /~~~~~~~~\\ " << std::endl
            << "/__*_______\\ " << std::endl
            << "     || " << std::endl
            << "  / ==== / " << std::endl << std::endl;
    outf.close();
}

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &shrubberyCreationForm) {
    out << "========== FORM ============" << std::endl
        << "Form name:\t" << shrubberyCreationForm.getName() << std::endl
        << "Sign status:\t" << shrubberyCreationForm.isSigned() << std::endl
        << "Sign grade:\t" << shrubberyCreationForm.getSignGrade() << std::endl
        << "Exec grade:\t" << shrubberyCreationForm.getExecutionGrade();
    return (out);
}