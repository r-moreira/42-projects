#ifndef M06_DATATRANSFEROBJECT_H
#define M06_DATATRANSFEROBJECT_H

#include <string>
#include <stdint.h>


typedef struct s_Data {
    int n;
    std::string str;
} Data;

uintptr_t serialize(Data *ptr);

Data *deserialize(uintptr_t raw);

#endif //M06_DATATRANSFEROBJECT_H
