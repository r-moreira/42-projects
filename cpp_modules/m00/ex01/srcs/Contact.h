/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:24:35 by romoreir          #+#    #+#             */
/*   Updated: 2022/05/08 19:24:35 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP00_CONTACT_H
#define CPP00_CONTACT_H

#include <iostream>
#include <string>
#include <iomanip>

class Contact {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    Contact();

    ~Contact();

    void displayPromptInfo(int index) const;

    void displayContactInfo() const;

    void setFirstName(const std::string &firstName);

    void setLastName(const std::string &lastName);

    void setNickname(const std::string &nickname);

    void setPhoneNumber(const std::string &phoneNumber);

    void setDarkestSecret(const std::string &darkestSecret);

private:
    static void formatDisplay(const std::string &info);
};


#endif //CPP00_CONTACT_H
