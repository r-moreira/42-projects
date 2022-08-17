#ifndef FT_CONTAINERS_PAIR_H
#define FT_CONTAINERS_PAIR_H

//// PAIR: https://cplusplus.com/reference/utility/pair/

#include <ostream>

namespace ft {

    template <class T1, class T2>
    class pair {

    public:
        typedef T1 first_type;
        typedef T2 second_type;

        first_type first;
        second_type	second;

        //// Constructors: https://cplusplus.com/reference/utility/pair/pair/
        pair() : first(first_type()), second(second_type()) {}

        template<class U, class V>
        pair(const pair<U, V> &rhs) {
            if (this != &rhs) {
                first = rhs.first;
                second = rhs.second;
            }
        }

        pair(first_type a, second_type b) {
            first = a;
            second = b;
        }

        ~pair() {}

        pair &operator=(const pair &p) {
            if (this != &p) {
                first = p.first;
                second = p.second;
            }
            return *this;
        }
    };

    //// Functions: https://cplusplus.com/reference/utility/make_pair/
    template <class T1, class T2>
    pair<T1, T2> make_pair(T1 x, T2 y) { return pair<T1, T2>(x, y); }

    //// Relation Operators: https://cplusplus.com/reference/utility/pair/operators/
    template <class T1, class T2>
    bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return (lhs.first == rhs.first) && (lhs.second == rhs.second);
    }

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return !(lhs == rhs); }

    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return (lhs.first < rhs.first) || (!(rhs.first < lhs.first) && (lhs.second < rhs.second));
    }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return rhs < lhs; }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return !(rhs < lhs); }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return !(lhs < rhs); }

    template <typename T, typename U>
    std::ostream &operator<<(std::ostream &o, pair<T, U> const &rhs) {
        return o << rhs.first << " - " << rhs.second;
    }

} // namespace ft
#endif //FT_CONTAINERS_PAIR_H
