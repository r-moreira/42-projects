#ifndef M07_ITER_H
#define M07_ITER_H

#include <iostream>

template<typename T>
void iter(T const *array, unsigned int len, void (*f)(T)) {
    for (unsigned int i = 0; i < len; i++) {
        (*f)(array[i]);
    }
}

#endif //M07_ITER_H