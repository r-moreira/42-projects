/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:24:50 by romoreir          #+#    #+#             */
/*   Updated: 2022/05/08 19:24:50 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

PhoneBook::PhoneBook() {
    _size = 0;
    _maxContacts = 8;
    _oldest = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::execute() {
    std::string command;
    int index;

    do {
        command = getCommand();

        if (command == "ADD") {
            addContact();
        }
        if (command == "SEARCH") {
            displayContacts();
            index = getEntry();
            displayEntry(index);
        }
    } while (command != "EXIT");
}

void PhoneBook::displayEntry(int index) const {
    if (index == -1) {
        return;
    }
    _contacts[--index].displayContactInfo();
}

int PhoneBook::getEntry() {
    int index;
    std::cout << "Please give the index of the contact to display" << std::endl;

    std::cin >> index;

    if (index < 1 || index > 8) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index. Choose from 1 to 8." << std::endl;
        index = -1;
    }

    return index;
}

void PhoneBook::displayContacts() const {
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;

    for (int i = 0; i < _size; i++) {
        _contacts[i].displayPromptInfo(i + 1);
    }
}

void PhoneBook::addContact() {

    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
    int index;

    std::cout << "Please give the following contact information." << std::endl;
    std::cout << "1 - Fist Name" << std::endl;
    std::cin >> firstName;
    std::cout << "2 - Last Name" << std::endl;
    std::cin >> lastName;
    std::cout << "3 - Nickname" << std::endl;
    std::cin >> nickName;
    std::cout << "4 - Phone Number" << std::endl;
    std::cin >> phoneNumber;
    std::cout << "5 - Darkest Secret" << std::endl;
    std::cin >> darkestSecret;

    if (firstName.empty() || lastName.empty() || nickName.empty() || phoneNumber.empty() || darkestSecret.empty()) {
        std::cout << "All contact information must be filled. Please try again" << std::endl;
    } else {
        _size == _maxContacts ? index = _oldest++ : index = _size;

        _contacts[index].setFirstName(firstName);
        _contacts[index].setLastName(lastName);
        _contacts[index].setNickname(nickName);
        _contacts[index].setPhoneNumber(phoneNumber);
        _contacts[index].setDarkestSecret(darkestSecret);

        _size < _maxContacts ? _size++ : _size;
        _oldest == _maxContacts ? _oldest = 0 : _oldest;
    }
}


std::string PhoneBook::getCommand() {
    std::string command;

    std::cout << "Please choose one of the following commands: ADD, SEARCH or EXIT" << std::endl;
    std::cin >> command;

    return command;
}
