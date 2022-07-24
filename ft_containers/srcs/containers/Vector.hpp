#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <memory>
#include <cstddef>

namespace ft {

    template<class T, class Alloc = std::allocator<T> >

    class vector {

        ////////////////////// TYPEDEFS //////////////////////
        typedef T												value_type;
        typedef	Alloc											allocator_type;
        typedef value_type&										reference;
        typedef const value_type&								const_reference;
        typedef value_type*										pointer;
        typedef const value_type*								const_pointer;
        typedef ptrdiff_t										difference_type;
        typedef size_t											size_type;

        /* TODO: Random Access Iterators for Member Types
        typedef RandomAccessIterator<T, T*, T&>					iterator;
        typedef RandomAccessIterator<T, const T*, const T&>		const_iterator;
        typedef ReverseRandomAccessIterator<iterator>			reverse_iterator;
        typedef ReverseRandomAccessIterator<const_iterator >	const_reverse_iterator;
        */

    /* Non-member function overloads */
    private:
        pointer			_array;
        size_type		_size;
        size_type		_capacity;
        allocator_type	_alloc;

    public:

        ////////////////////// CONSTRUCTORS - RULE OF THREE //////////////////////
        explicit vector(const allocator_type& alloc = allocator_type()) : _array(0), _size(0), _capacity(0), _alloc(alloc) {}

        explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc) {
            this->_array = new value_type[n]();
            for (size_type i = 0; i < n; i++) this->_array[i] = val;
        }

        vector(const vector& v) : _array(0), _size(0), _capacity(0), _alloc(v._alloc) { *this = v; }

        // TODO: Create Constructor for Iterators

        /* TODO: Waiting for Iterators and Modifiers
        vector&	operator=(const vector& v) {
            delete[] this->_array;
            this->_array = new value_type[v._capacity];
            this->_capacity = v._capacity;
            this->_size = 0;
            this->assign(v.begin(), v.end());
            return *this;
        }
        */

        ~vector() { delete[] this->_array; }

        ////////////////////// ELEMENT ACCESS //////////////////////
        reference operator[](size_type n) { return this->_array[n]; }

        const_reference	operator[](size_type n) const { return this->_array[n]; }

        reference at(size_type n) {
            if (n >= this->_size) throw std::out_of_range("out of range");
            return this->_array[n];
        }

        const_reference	at(size_type n) const {
            if (n >= this->_size) throw std::out_of_range("out of range");
            return this->_array[n];
        }

        reference front() { return this->_array[0]; }

        const_reference	front() const { return this->_array[0]; }

        reference back() { return this->_array[this->_size - 1]; }

        const_reference	back() const { return this->_array[this->_size - 1]; }
    };
}

#endif //FT_CONTAINERS_VECTOR_HPP
