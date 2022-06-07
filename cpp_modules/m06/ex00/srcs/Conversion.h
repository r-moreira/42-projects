#ifndef CONVERSION_H
#define CONVERSION_H

#include <string>
#include <iostream>
#include <cstdlib>

class Conversion {

private:
    std::string _input;

public:
    Conversion(const std::string& input);

    Conversion(Conversion const &conversion);

    ~Conversion();

    Conversion &operator=(Conversion const &conversion);

    bool validateInput();

    void display();
private:
   bool isInt();

   bool isFloat();

   bool isDouble();

   bool isChar();

   void toChar();

   void toInt();

   void toFloat();

   void toDouble();
};


#endif //CONVERSION_H
