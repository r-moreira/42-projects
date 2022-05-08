/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:28:39 by romoreir          #+#    #+#             */
/*   Updated: 2022/05/08 19:28:39 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int exitError(const char *reason) {
    std::cout << "Error: " << reason << std::endl;
    exit(EXIT_FAILURE);
}

std::string handleInput(char *argv[]) {
    std::string buffer;
    std::string line;
    std::fstream inputFile;

    inputFile.open(argv[1], std::ios::in);
    if (!inputFile.is_open()) {
        exitError("Failed to opening input file.");
    }

    while (getline(inputFile, line)) {
        buffer.append(line).append("\n");
    }

    inputFile.close();
    return buffer;
}

void handleOutput(char *argv[], std::string buffer) {
    std::fstream outputFile;
    size_t pos = 0;

    outputFile.open(std::string(argv[1]).append(".replace").data(), std::ios::out);
    if (!outputFile.is_open()) {
        exitError("Failed to opening output file.");
    }

    while ((pos = buffer.find(argv[2], pos)) != std::string::npos) {
        buffer.erase(pos, std::string(argv[2]).length());
        buffer.insert(pos, argv[3]);
        pos++;
    }
    outputFile << buffer;
    outputFile.close();
}

int main(int argc, char *argv[]) {
    std::string buffer;

    if (argc != 4) {
        return (exitError("Invalid number of parameters."));
    }

    buffer = handleInput(argv);
    handleOutput(argv, buffer);

    return (EXIT_SUCCESS);
}
