#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <memory>
#include <cstddef>

namespace ft {

    template<class T, class Alloc = std::allocator<T> >
    class vector {

    public:
        typedef T												value_type;
        typedef	Alloc											allocator_type;
        typedef value_type&										reference;
        typedef const value_type&								const_reference;
        typedef value_type*										pointer;
        typedef const value_type*								const_pointer;
        typedef ptrdiff_t										difference_type;
        typedef size_t											size_type;
//        typedef RandomAccessIterator<T, T*, T&>					iterator;
//        typedef RandomAccessIterator<T, const T*, const T&>		const_iterator;
//        typedef ReverseRAI<iterator>							reverse_iterator;
//        typedef ReverseRAI<const_iterator >						const_reverse_iterator;

    /* Non-member function overloads */
    private:
        pointer			_array;
        size_type		_size;
        size_type		_capacity;
        allocator_type	_alloc;

    public:
        explicit vector (const allocator_type& alloc = allocator_type()) : _array(0), _size(0), _capacity(0), _alloc(alloc) {
        }

    };
}

#endif //FT_CONTAINERS_VECTOR_HPP
