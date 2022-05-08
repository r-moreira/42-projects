/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:24:16 by romoreir          #+#    #+#             */
/*   Updated: 2022/05/08 19:24:16 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

Contact::Contact() {};

Contact::~Contact() {};

void Contact::displayContactInfo() const {
    std::cout << "First name     : " << _firstName << std::endl;
    std::cout << "Last name      : " << _lastName << std::endl;
    std::cout << "Nickname       : " << _nickname << std::endl;
    std::cout << "Phone number   : " << _phoneNumber << std::endl;
    std::cout << "Darkest secret : " << _darkestSecret << std::endl;
}

void Contact::formatDisplay(const std::string &info) {
    if (info.length() > 10)
        std::cout << std::setw(10) << info.substr(0, 9).append(".") << "|";
    else
        std::cout << std::right << std::setfill(' ') << std::setw(10) << info << "|";
}

void Contact::displayPromptInfo(int index) const {
    std::cout << std::setw(10) << index << "|";
    formatDisplay(_firstName);
    formatDisplay(_lastName);
    formatDisplay(_nickname);
    std::cout << std::endl;
}

void Contact::setFirstName(const std::string &firstName) {
    Contact::_firstName = firstName;
}

void Contact::setLastName(const std::string &lastName) {
    Contact::_lastName = lastName;
}

void Contact::setNickname(const std::string &nickname) {
    Contact::_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) {
    Contact::_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret) {
    Contact::_darkestSecret = darkestSecret;
}
