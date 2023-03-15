#include <iostream>
#include "../includes/webserv.h"
#include "../includes/config/Configuration.h"
#include "../includes/network/Network.h"
#include "../includes/parser/Parser.h"


int main(int argc, char **argv, char **env) {
    std::cout << MESSAGE << std::endl;

    Configuration serverConfiguration;
    Network serverNetwork;
    Parser serverParser;

    serverConfiguration.echo();
    serverNetwork.echo();
    serverParser.echo();

    return 0;
}
