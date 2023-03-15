#include "../includes/webserv.h"
#include "../includes/io/Multiplexer.h"


int main(int argc, char **argv, char **env) {
    signal(SIGPIPE, SIG_IGN);

    if (argc != 2) {
        std::cout << "Usage :  ./webserv {PATH TO CONFIGURATION FILE}" << std::endl;
        return (EXIT_FAILURE);
    }

    Multiplexer multiplexer;
    std::cout << "Hello World" << std::endl;
    return EXIT_SUCCESS;
}
