#ifndef FT_CONTAINERS_LEXICOGRAPHICAL_COMPARE_H
#define FT_CONTAINERS_LEXICOGRAPHICAL_COMPARE_H

//// Lexicographical Compare: https://m.cplusplus.com/reference/algorithm/lexicographical_compare/

namespace ft {
    template<class InputIterator, class InputIterator2>
    bool lexicographical_compare(InputIterator start,
                                 InputIterator end,
                                 InputIterator2 start2,
                                 InputIterator2 end2) {
        for (; start != end; ++start, ++start2) {
            if (start2 == end2 || *start2 < *start) return false;
            else if (*start < *start2) return true;
        }
        return start2 != end2;
    }

    template<class InputIterator, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator start,
                                 InputIterator end,
                                 InputIterator2 start2,
                                 InputIterator2 end2,
                                 Compare comp) {
        for (; (start != end) && (start2 != end2); ++start, ++start2) {
            if (comp(*start, *start2)) return true;
            if (comp(*start2, *start)) return false;
        }
        return (start == end) && (start2 != end2);
    }
} // namespace ft

#endif //FT_CONTAINERS_LEXICOGRAPHICAL_COMPARE_H
