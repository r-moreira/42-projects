#include "Bureaucrat.h"
#include "Form.h"

int main() {
    Bureaucrat foo("Foo", 100);
    Bureaucrat bar("Bar", 21);
    Form form("Random Bureaucrat Things", 42, 21);

    std::cout << foo << std::endl;
    std::cout << bar << std::endl;
    std::cout << form << std::endl;

    std::cout << "-------- Form Grade Too Low Test -------------" << std::endl;
    try {
        foo.signForm(form);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-------- Success signing the form ------------" << std::endl;
    try {
        bar.signForm(form);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << form << std::endl;

    return 0;
}