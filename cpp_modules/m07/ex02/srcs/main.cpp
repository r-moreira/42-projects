/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:47:58 by romoreir          #+#    #+#             */
/*   Updated: 2022/07/03 04:20:43 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.tpp"
#include <cstdlib>
#include <ctime>

class ComplexType {
private: 
  int _number; 
  std::string _string;
public: 
  void setNumber(int number) { _number = number; } 
  int getNumber() { return _number; } 
  void setString(std::string string) { _string = string; } 
  std::string getString() { return _string; } 
}; 

void testComplexTypeArray(void) {
    std::cout << std::endl << "===== Complex type array test ====" << std::endl;

    Array<ComplexType> complexArray = Array<class ComplexType>(5);	

	for(int i = 0; i < 5; i++) {
		std::string result = "";
    	char alpha[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
							'h', 'i', 'j', 'k', 'l', 'm', 'n',
							'o', 'p', 'q', 'r', 's', 't', 'u',
							'v', 'w', 'x', 'y', 'z' };
			
		for (int i = 0; i < 22; i++) result = result + alpha[rand() % 26];
     	
		complexArray[i].setNumber(i); 
		complexArray[i].setString(result);
	} 
	
	for(int i = 0; i < 5; i++) {
		std::cout 
			    << "complexArray[" << i << "] -> getNumber(): "
				<< complexArray[i].getNumber() 
				<< " | getString(): " 
				<< complexArray[i].getString()
				<< std::endl; 	
	}
}

void testArrayIndexOperatorValues(const int &len) {

    Array<int> myArray(len);
    int *cppArray = new int[len];

    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        const int value = rand();
        myArray[i] = value;
        cppArray[i] = value;
    }

    for (int i = 0; i < len; i++) {
        if (myArray[i] != cppArray[i]) {
            std::cerr << "Error: Arrays have different values for same index" << std::endl;
            exit(1);
        }
    }

    std::cout << "Success: Both arrays have same vales for the same index" << std::endl;
}

void testArrayException() {
    Array<int> array(5);

    try {
        array[6] = 0;
    } catch (const std::exception &e) {
        std::cout << "Success: Array throw an exception" << std::endl;
    }
}

void testSizeFunction() {
    Array<char> array(42);

    if (array.size() == 42) {
        std::cout << "Success: Array has correct size" << std::endl;
    } else {
        std::cerr << "Error: Array has an invalid size" << std::endl;
    }
}

void testChangeSpecficIndexValue() {
    Array<float> array(3);

    array[2] = 42.0f;

    if (array[2] == 42.0f) {
        std::cout << "Success: Array index has correct value" << std::endl;
    } else {
        std::cerr << "Error: Array has an incorrect value" << std::endl;
    }
}

void testArrayCopy() {
    Array<int> array = Array<int>(5);
    Array<int> arrayCopy(array);;

    array[2] = 42;
    if (arrayCopy[2] != 42) {
        std::cout << "Success: Array copy not changed" << std::endl;
    } else {
        std::cerr << "Error: Array has changed" << std::endl;
    }
}

void testEmptyConstructor() {
    Array<std::string> array = Array<std::string>();

    if (array.size() == 0) {
        std::cout << "Success: Empty constructor has initialized an empty array" << std::endl;
    } else {
        std::cerr << "Error: Empty constructor has not initialized an empty array" << std::endl;
    }
}

int main(int, char **) {
    std::cout << std::endl << "===== Test array features ====" << std::endl;
    testArrayIndexOperatorValues(1000);
    testArrayException();
    testSizeFunction();
    testChangeSpecficIndexValue();
    testArrayCopy();
    testEmptyConstructor();

	testComplexTypeArray();
    return 0;
}
