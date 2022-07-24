#ifndef FT_CONTAINERS_ITERATOR_TRAITS_H

#include <iterator>
#include <cstddef>

//// Iterator Traits: https://m.cplusplus.com/reference/iterator/iterator_traits/

namespace ft {
    template<class Iterator>
    class iterator_traits {
    public:
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::iterator_category iterator_category;
    };

    template<class T>
    class iterator_traits<T *> {
        typedef std::ptrdiff_t difference_type;
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template<class T>
    class iterator_traits<const T *> {
        typedef std::ptrdiff_t difference_type;
        typedef T value_type;
        typedef const T *pointer;
        typedef const T &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
} // namespace ft
#define FT_CONTAINERS_ITERATOR_TRAITS_H

#endif //FT_CONTAINERS_ITERATOR_TRAITS_H
