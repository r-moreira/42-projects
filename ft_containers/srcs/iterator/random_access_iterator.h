#ifndef FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_H
#define FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_H

#include <iterator>

//// Random Access Iterator: https://cplusplus.com/reference/iterator/RandomAccessIterator/

namespace ft {
    template<class T>
    class random_access_iterator {
    public:
        typedef std::random_access_iterator_tag iterator_category;
        typedef T                               value_type;
        typedef std::ptrdiff_t                  difference_type;
        typedef T                               *pointer;
        typedef T                               &reference;

    private:
        pointer _p;

    public:
        random_access_iterator() : _p(NULL) {}

        explicit random_access_iterator(pointer p) : _p(p) {}

        random_access_iterator(const random_access_iterator &x) : _p(x._p) {}

        random_access_iterator &operator=(const random_access_iterator &p) {
            _p = p._p;
            return *this;
        }

        ~random_access_iterator() {}

        pointer getPointer() { return _p; }

        operator random_access_iterator<T const>() const { return random_access_iterator<T const>(_p); }

        bool operator==(const random_access_iterator &rhs) const { return (_p == rhs._p); }

        bool operator!=(const random_access_iterator &rhs) const { return (_p != rhs._p); }

        reference operator*() const { return *_p; }

        pointer operator->() const { return _p; }

        random_access_iterator &operator++() {
            ++_p;
            return *this;
        }

        random_access_iterator operator++(int) {
            random_access_iterator tmp = *this;
            ++_p;
            return tmp;
        }

        random_access_iterator &operator--() {
            --_p;
            return *this;
        }

        random_access_iterator operator--(int) {
            random_access_iterator tmp = *this;
            --_p;
            return tmp;
        }

        random_access_iterator operator+(const difference_type &n) const { return random_access_iterator(_p + n); }

        difference_type operator+(const random_access_iterator &rhs) const { return (_p + rhs._p); }

        random_access_iterator operator-(const difference_type &n) const { return random_access_iterator(_p - n); }

        difference_type operator-(const random_access_iterator &rhs) const { return (_p - rhs._p); }

        bool operator<(const random_access_iterator &rhs) const { return (_p < rhs._p); }

        bool operator>(const random_access_iterator &rhs) const { return (_p > rhs._p); }

        bool operator<=(const random_access_iterator &rhs) const { return (_p <= rhs._p); }

        bool operator>=(const random_access_iterator &rhs) const { return (_p >= rhs._p); }

        random_access_iterator &operator+=(const difference_type &n) const {
            _p += n;
            return *this;
        }

        random_access_iterator &operator-=(const difference_type &n) const {
            _p -= n;
            return *this;
        }

        value_type &operator[](size_t n) const { return *(_p + n); }
    };
} // namespace ft
#endif //FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_H
