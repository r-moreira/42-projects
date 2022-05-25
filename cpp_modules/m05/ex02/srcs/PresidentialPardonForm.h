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
