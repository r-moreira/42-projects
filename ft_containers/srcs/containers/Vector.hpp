#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <memory>
#include <cstddef>
#include <sstream>
#include "../iterator/iterator_traits.h"
#include "../iterator/random_access_iterator.h"
#include "../iterator/reverse_iterator.h"
#include "../utils/type_traits.h"
#include "../utils/equal.h"
#include "../utils/lexicographical_compare.h"

//// Vector: https://m.cplusplus.com/reference/vector/vector/

namespace ft {

    template<class T, class Alloc = std::allocator<T> >

    class vector {

    public:
        ////Member Types
        typedef T												            value_type;
        typedef	Alloc											            allocator_type;
        typedef typename allocator_type::value_type&			            reference;
        typedef typename allocator_type::const_reference                    const_reference;
        typedef typename allocator_type::pointer                            pointer;
        typedef typename allocator_type::const_pointer                      const_pointer;
        typedef ft::random_access_iterator<value_type>                      iterator;
        typedef ft::random_access_iterator<const value_type>                const_iterator;
        typedef ft::reverse_iterator<iterator>                              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                        const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type     difference_type;
        typedef typename allocator_type::size_type                          size_type;

    private:
        //// Private Attributes
        allocator_type	_alloc;
        pointer	    	_p;
        size_type	    _size;
        size_type	    _capacity;

    public:
        //// Constructors: https://m.cplusplus.com/reference/vector/vector/vector/
        explicit vector(const allocator_type &alloc = allocator_type())
                : _alloc(alloc), _p(NULL), _size(0), _capacity(0) {}

        explicit vector(size_type n,
                        const value_type &val = value_type(),
                        const allocator_type &alloc = allocator_type()) :
                _alloc(alloc),
                _p(NULL),
                _size(n),
                _capacity(n) {
            _p = _alloc.allocate(n);
            for (size_t i = 0; i < n; i++)
                _alloc.construct(_p + i, val);
        }

        template <class InputIterator>
        vector(InputIterator start, InputIterator end,
               const allocator_type &alloc = allocator_type(),
               typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL) :
                    _alloc(alloc),
                    _p(NULL),
                    _size(0),
                    _capacity(0) {
            size_type n = end - start;
            reserve(n);
            for (size_type i = 0; i < n; i++)
                _alloc.construct(_p + i, *(start + i));
            _size = n;
        }

        vector(const vector &v) :
            _alloc(v._alloc),
            _size(v._size),
            _capacity(v._capacity) {
            _p = _alloc.allocate(v.capacity());
            for (size_type i = 0; i < _size; i++)
                _alloc.construct(_p + i, v._p[i]);
        }

        //// Destructor: https://m.cplusplus.com/reference/vector/vector/~vector/
        ~vector() { _alloc.deallocate(_p, size()); }

        //// Assigment operator overloading: https://m.cplusplus.com/reference/vector/vector/operator=/
        vector &operator=(const vector &v) {
            clear();
            if (_capacity < v._size) reserve(v._capacity);
            _size = v._size;
            for (size_t i = 0; i < v._size; i++)
                _alloc.construct(_p + i, v._p[i]);
            return *this;
        }

        //// Iterator: https://m.cplusplus.com/reference/iterator/iterator/

        // https://m.cplusplus.com/reference/vector/vector/begin/
        iterator begin() { return iterator(_p); }
        const_iterator begin() const { return const_iterator(_p); }

        // https://m.cplusplus.com/reference/vector/vector/end/
        iterator end() { return iterator(_p + _size); }
        const_iterator end() const { return const_iterator(_p + _size); }

        // https://m.cplusplus.com/reference/vector/vector/rbegin/
        reverse_iterator rbegin() { return reverse_iterator(end()); }
        const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

        // https://m.cplusplus.com/reference/vector/vector/rend/
        reverse_iterator rend() { return reverse_iterator(begin()); }
        const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

        //// Element access

        // https://m.cplusplus.com/reference/vector/vector/operator[]/
        reference operator[](size_type n) { return _p[n]; }
        const_reference operator[](size_type n) const { return _p[n]; }

        // https://m.cplusplus.com/reference/vector/vector/at/
        reference at(size_type n) { _range_validator(n); return _p[n]; }
        const_reference at(size_type n) const { _range_validator(n); return _p[n]; }

        // https://m.cplusplus.com/reference/vector/vector/back/
        reference back() { return _p[_size - 1]; }
        const_reference back() const { return _p[_size - 1]; }

        // https://m.cplusplus.com/reference/vector/vector/front/
        reference front() { return _p[0]; }
        const_reference front() const { return _p[0]; }

        //// Capacity

        // https://m.cplusplus.com/reference/vector/vector/capacity/
        size_type capacity() const { return _capacity; }

        // https://m.cplusplus.com/reference/vector/vector/empty/
        bool empty() const { return (_size == 0); }

        // https://m.cplusplus.com/reference/vector/vector/max_size/
        size_type max_size() const { return _alloc.max_size(); }

        // https://m.cplusplus.com/reference/vector/vector/reserve/
        void reserve(size_type n) {
            if (n > max_size()) throw std::length_error("Allocator has no size available");
            if (n < _capacity) return;

            pointer tmp = _alloc.allocate(n);
            for (size_t i = 0; i < _size; i++) {
                _alloc.construct(tmp + i, _p[i]);
                _alloc.destroy(_p + i);
            }
            _alloc.deallocate(_p, _capacity);
            _p = tmp;
            _capacity = n;
        }

        // https://m.cplusplus.com/reference/vector/vector/resize/
        void resize(size_type n, value_type val = value_type()) {
            if (n < _size) {
                for (size_type i = n; i < _size; i++)
                    _alloc.destroy(_p + i);
            } else if (n > _size) {
                reserve(n);
                for (size_type i = _size; i < n; i++)
                    _alloc.construct(_p + i, val);
            }
            _size = n;
        }

        // https://m.cplusplus.com/reference/vector/vector/size/
        size_type size() const { return _size; }

        //// Modifiers

        // https://m.cplusplus.com/reference/vector/vector/assign/
        template <class InputIterator>
        void assign(InputIterator start,
                    InputIterator end,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
            size_type n = end - start;
            reserve(n);
            for (size_type i = 0; i < n; i++, start++) {
                _alloc.destroy(_p + i);
                _alloc.construct(_p + i, *start);
            }
            _size = n;
        }
        void assign(size_type n, const value_type &val) {
            reserve(n);
            for (size_type i = 0; i < n; i++) {
                _alloc.destroy(_p + i);
                _alloc.construct(_p + i, val);
            }
            _size = n;
        }

        // https://m.cplusplus.com/reference/vector/vector/clear/
        void clear() {
            if (_p) {
                for (size_t i = 0; i < _size; i++)
                    _alloc.destroy(_p + i);
            }
            _size = 0;
        }

        // https://m.cplusplus.com/reference/vector/vector/erase/
        iterator erase(iterator position) {
            size_type pos = position - begin();

            _alloc.destroy(_p + pos);
            _move_left(pos, 1);
            _size--;
            return iterator(_p + pos);
        }
        iterator erase(iterator start, iterator end) {
            size_type diff = end - start;
            size_type n = start - begin();
            size_type i = end - begin();

            while (*start != *end) {
                _alloc.destroy(&(*start));
                ++start;
            }
            _move_left(n, i - n);
            _size -= diff;
            return iterator(_p + n);
        }

        // https://m.cplusplus.com/reference/vector/vector/insert/
        iterator insert(iterator position, const value_type &val) {
            size_type pos = position - begin();

            if (_size + 1 > _capacity) reserve(_increase_size());
            _move_right(pos, 1);
            _alloc.construct(_p + pos, val);
            ++_size;
            return iterator(_p);
        }
        void insert(iterator position, size_type n, const value_type &val) {
            size_type pos = position - begin();

            if (_size + n > _capacity)
                reserve(_capacity + n);
            _move_right(pos, n);
            for (size_type i = 0; i < n; i++)
                _alloc.construct(&_p[pos + i], val);
            _size += n;
        }
        template <class InputIterator>
        void insert(iterator position, InputIterator start, InputIterator end,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
            size_type pos = position - begin();
            size_type n = end - start;

            reserve(_size + n);
            _move_right(pos, n);
            for (size_type i = 0; i < n; i++, start++)
                _alloc.construct(_p + pos + i, *start);
            _size += n;
        }

        // https://m.cplusplus.com/reference/vector/vector/pop_back/
        void pop_back() { _alloc.destroy(_p + _size--); }

        // https://m.cplusplus.com/reference/vector/vector/push_back/
        void push_back(const value_type &val) {
            size_type new_cap;

            _size == 0 ? new_cap = 1 : new_cap = _size * 2;
            if (_size == _capacity) reserve(new_cap);
            _alloc.construct(_p + _size++, val);
        }

        // https://m.cplusplus.com/reference/vector/vector/swap/
        void swap(vector &x) {
            std::swap(_alloc, x._alloc);
            std::swap(_p, x._p);
            std::swap(_size, x._size);
            std::swap(_capacity, x._capacity);
        }

        // Allocator: https://m.cplusplus.com/reference/vector/vector/get_allocator/
        allocator_type	get_allocator() const { return this->_alloc; }

    private:
        //// Private Methods

        size_type _increase_size() { return _size == 0 ? 1 : _size * 2; }

        void _move_left(size_type pos, size_type n) {
            for (; pos < _size && pos + n < _capacity; pos++) {
                _alloc.construct(_p + pos, _p[pos + n]);
                _alloc.destroy(_p + pos + n);
            }
        }
        
        void _move_right(size_type pos, size_type n) {
            for (size_type i = _size - 1; i >= pos; i--) {
                _alloc.construct(_p + i + n, _p[i]);
                _alloc.destroy(_p + i);
                if (i == 0) break;
            }
        }

        void _range_validator(size_type n) { if (n >= _size) throw std::out_of_range("Invalid range"); }
    };

    //// Non-member function overloads

    // Swap: https://m.cplusplus.com/reference/vector/vector/swap-free/
    template <class T, class Alloc>
    void swap(vector<T, Alloc> &lhs, vector<T, Alloc> &rhs) { lhs.swap(rhs); }

    // Relational Operators: : https://m.cplusplus.com/reference/vector/vector/operators/
    template <class T, class Alloc>
    bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
        if (lhs.size() != rhs.size()) return false;
        return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    template <class T, class Alloc>
    bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return !(lhs == rhs); }

    template <class T, class Alloc>
    bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return !(rhs < lhs); }

    template <class T, class Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return (rhs < lhs); }

    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return !(lhs < rhs); }

} // namespace ft

#endif //FT_CONTAINERS_VECTOR_HPP
