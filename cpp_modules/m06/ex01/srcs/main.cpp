#include <iostream>
#include <stdint.h>
#include "Data.h"

void printData(Data *data) {
    std::cout << "n:\t\t" << data->n << std::endl;
    std::cout << "str:\t\t" << data->str << std::endl;
    std::cout << "address:\t" << &data << std::endl;

}

uintptr_t serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}

int main() {

    Data *unserializedData = new Data();
    Data *deserializedData;
    uintptr_t raw;

    unserializedData->n = 42;
    unserializedData->str = "Forty Two";

    std::cout << "------ Data Structure ------" << std::endl;
    printData(unserializedData);

    raw = serialize(unserializedData);
    std::cout << "------ Serialized Data ------" << std::endl;
    std::cout << raw << std::endl;

    deserializedData = deserialize(raw);
    std::cout << "------ Deserialized Data ------" << std::endl;
    printData(deserializedData);

    delete unserializedData;
    return 0;
}