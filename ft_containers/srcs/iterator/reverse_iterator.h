#ifndef FT_CONTAINERS_REVERSE_ITERATOR_H
#define FT_CONTAINERS_REVERSE_ITERATOR_H

#include "iterator_traits.h"

//// Reverse Iterator: https://m.cplusplus.com/reference/iterator/reverse_iterator/

namespace ft {
    template<class It>
    class reverse_iterator {
    public:
        typedef It iterator_type;
        typedef typename ft::iterator_traits<It>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<It>::value_type value_type;
        typedef typename ft::iterator_traits<It>::difference_type difference_type;
        typedef typename ft::iterator_traits<It>::pointer pointer;
        typedef typename ft::iterator_traits<It>::reference reference;

    private:
        iterator_type _p;

    public:
        reverse_iterator() : _p(iterator_type()) {}

        explicit reverse_iterator(iterator_type it) : _p(it) {}

        explicit reverse_iterator(pointer p) : _p(p) {}

        template<class Iter>
        reverse_iterator(const reverse_iterator<Iter> &rev_it) { _p = rev_it.getPointer(); }

        virtual ~reverse_iterator() {}

        iterator_type getPointer() const { return _p; }

        reference operator*() const {
            iterator_type tmp = _p;
            return *(--tmp);
        }

        pointer operator->() const { return &(operator*()); }

        reverse_iterator &operator++(void) {
            --_p;
            return *this;
        }

        reverse_iterator operator++(int) {
            reverse_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        reverse_iterator &operator--(void) {
            ++_p;
            return *this;
        }

        reverse_iterator operator--(int) {
            reverse_iterator tmp = *this;
            --(*_p);
            return tmp;
        }

        reverse_iterator operator+(difference_type n) const { return reverse_iterator(_p - n); }

        reverse_iterator operator-(difference_type n) const { return reverse_iterator(_p + n); }

        reverse_iterator &operator+=(difference_type n) {
            _p -= n;
            return *this;
        }

        reverse_iterator &operator-=(difference_type n) {
            _p += n;
            return *this;
        }

        reference operator[](difference_type n) const { return getPointer()[-n - 1]; }
    };

    template<class Iterator>
    bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
        return (lhs.getPointer() == rhs.getPointer());
    }

    template<class Iterator>
    bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
        return (lhs.getPointer() != rhs.getPointer());
    }

    template<class IteratorA, class IteratorB>
    bool operator!=(const reverse_iterator<IteratorA> &lhs, const reverse_iterator<IteratorB> &rhs) {
        return (lhs.getPointer() != rhs.getPointer());
    }

    template<class Iterator>
    bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
        return (lhs.getPointer() > rhs.getPointer());
    }

    template<class Iterator>
    bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
        return (lhs.getPointer() >= rhs.getPointer());
    }

    template<class Iterator>
    bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
        return (lhs.getPointer() < rhs.getPointer());
    }

    template<class Iterator>
    bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
        return (lhs.getPointer() <= rhs.getPointer());
    }

    template<class Iterator>
    reverse_iterator<Iterator>
    operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it) {
        return (rev_it + n);
    }

    template<class Iterator>
    typename reverse_iterator<Iterator>::difference_type
    operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
        return (rhs.getPointer() - lhs.getPointer());
    }

} // namespace ft
#endif //FT_CONTAINERS_REVERSE_ITERATOR_H
