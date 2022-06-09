#ifndef M07_WHATEVER_H
#define M07_WHATEVER_H

template<typename T>
void swap(T &a, T &b) {
    T c = a;
    a = b;
    b = c;
}

template<typename T>
T const &min(T const &a, T const &b) {
    return a == b ? b : a < b ? a : b;
}

template<typename T>
T const &max(T const &a, T const &b) {
    return a == b ? b : a > b ? a : b;
}

#endif //M07_WHATEVER_H
