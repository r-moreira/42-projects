#ifndef FT_CONTAINERS_EQUAL_H
#define FT_CONTAINERS_EQUAL_H

//// Equal: https://m.cplusplus.com/reference/algorithm/equal/

namespace ft {
    template <class InputIterator, class InputIterator2>
    bool equal(InputIterator start, InputIterator end, InputIterator2 start2) {
        for (; start != end; start++, start2++)
            if (*start != *start2) return false;
        return true;
    }

    template <class InputIterator, class InputIterator2, class BinaryPred>
    bool equal(InputIterator start, InputIterator end, InputIterator2 start2, BinaryPred biPred) {
        for (; start != end; start++, start2++)
            if (!biPred(*start, *start2)) return false;
        return true;
    }
} // namespace ft

#endif //FT_CONTAINERS_EQUAL_H
