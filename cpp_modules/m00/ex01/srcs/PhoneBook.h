/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:24:57 by romoreir          #+#    #+#             */
/*   Updated: 2022/05/08 19:24:57 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP00_PHONEBOOK_H
#define CPP00_PHONEBOOK_H

#include "Contact.h"
#include <limits>
#include <iostream>
#include <iomanip>

class PhoneBook {
private:
    Contact _contacts[8];
    int _size;
    int _maxContacts;
    int _oldest;

public:
    PhoneBook();

    ~PhoneBook();

    void execute();

private:
    static std::string getCommand();

    void displayContacts() const;

    static int getEntry();

    void displayEntry(int) const;

    void addContact();
};

#endif //CPP00_PHONEBOOK_H
