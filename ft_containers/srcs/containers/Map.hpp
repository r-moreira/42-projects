#ifndef FT_CONTAINERS_MAP_HPP
#define FT_CONTAINERS_MAP_HPP


////  https://m.cplusplus.com/reference/map/map


#include "../utils/pair.h"
#include "../utils/type_traits.h"
#include "../tree/red_black_tree.h"
#include "../utils/equal.h"
#include "../utils/lexicographical_compare.h"
#include <cstddef>

namespace ft {

    template <
            class Key,
            class T,
            class Compare = ::std::less<Key>,
            class Alloc = ::std::allocator<ft::pair<Key, T> > >
    class map {

    public:
        ////Member Types
        typedef Key		                                    key_type;
        typedef T		                                    mapped_type;
        typedef Compare	                                    key_compare;
        typedef Alloc	                                    allocator_type;
        typedef ft::pair<key_type, mapped_type>             value_type;
        typedef typename allocator_type::reference			reference;
        typedef typename allocator_type::const_reference	const_reference;
        typedef typename allocator_type::pointer			pointer;
        typedef typename allocator_type::const_pointer		const_pointer;

        class value_compare {
        public:
            bool operator()(const value_type &a, const value_type &b) const { return (key_compare()(a.first, b.first)); }
        };

        typedef typename ft::red_black_tree<value_type, value_compare>::iterator                iterator;
        typedef typename ft::red_black_tree<value_type, value_compare>::const_iterator          const_iterator;
        typedef typename ft::red_black_tree<value_type, value_compare>::reverse_iterator        reverse_iterator;
        typedef typename ft::red_black_tree<value_type, value_compare>::const_reverse_iterator  const_reverse_iterator;
        typedef ptrdiff_t	                                                                    difference_type;
        typedef size_t	                                                                    	size_type;

    private:
        //// Private Attributes
        allocator_type			                    _alloc;
        key_compare				                    _key_compare;
        value_compare			                    _value_compare;
        red_black_tree<value_type, value_compare>	_rbtree;

    public:
        //// Constructors: https://cplusplus.com/reference/map/map/map/
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) :
            _alloc(alloc),
            _key_compare(comp),
            _value_compare(value_compare()),
            _rbtree(_alloc) {}

        template <class InputIterator>
        map(InputIterator first,
            InputIterator last,
            const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type(),
            typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL) :
                _alloc(alloc),
                _key_compare(comp),
                _value_compare(value_compare()),
                _rbtree(_alloc) {
            insert(first, last);
        }

        map(const map &m) :
            _alloc(m._alloc),
            _key_compare(m._key_compare),
            _value_compare(m._value_compare),
            _rbtree(m._rbtree) {}

        //// Destructor:
        ~map() {}

        //// Assigment operator overloading: https://cplusplus.com/reference/map/map/operator=/
        map	&operator=(const map &m) {
            _alloc = m._alloc;
            _key_compare = m._key_compare;
            _value_compare = m._value_compare;
            _rbtree = m._rbtree;
            return *this;
        }

        //// Iterator: https://m.cplusplus.com/reference/iterator/iterator/

        // https://cplusplus.com/reference/map/map/begin/
        iterator begin() { return _rbtree.begin(); }
        const_iterator begin() const { return _rbtree.begin(); }

        // https://cplusplus.com/reference/map/map/end/
        iterator end() { return _rbtree.end(); }
        const_iterator end() const { return _rbtree.end(); }

        // https://cplusplus.com/reference/map/map/rbegin/
        reverse_iterator rbegin() { return _rbtree.rbegin(); }
        const_reverse_iterator rbegin() const { return _rbtree.rbegin(); }

        // https://cplusplus.com/reference/map/map/rend/
        reverse_iterator rend() { return _rbtree.rend(); }
        const_reverse_iterator rend() const { return _rbtree.rend(); }

        //// Element access

        // https://cplusplus.com/reference/map/map/operator[]/
        mapped_type &operator[](const key_type &key) {
            iterator ret = _rbtree.find(ft::make_pair(key, mapped_type()));

            if (ret != end()) return ret._ptr->value.second;

            ft::pair<iterator, bool> tmp = insert(ft::make_pair(key, mapped_type()));
            return tmp.first._ptr->value.second;
        }

        //// Capacity

        // https://cplusplus.com/reference/map/map/empty/
        bool empty() const { return _rbtree.empty(); }

        // https://cplusplus.com/reference/map/map/max_size/
        size_type max_size() const { return _rbtree.max_size(); }

        // https://cplusplus.com/reference/map/map/size/
        size_type size() const { return _rbtree.size(); }

        //// Modifiers

        // https://cplusplus.com/reference/map/map/clear/
        void clear() { _rbtree.clear(); }

        // https://cplusplus.com/reference/map/map/erase/
        void erase(iterator position) { _rbtree.erase(position); }
        size_type erase(const key_type &k) { return _rbtree.erase(ft::make_pair(k, mapped_type())); }
        void erase(iterator first, iterator last) { _rbtree.erase(first, last); }

        // https://cplusplus.com/reference/map/map/insert/
        ft::pair<iterator, bool> insert(const value_type &val) { return _rbtree.insert(val); }
        iterator insert(iterator position, const value_type &val) { return _rbtree.insert(position, val); }
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL) {
            _rbtree.insert(first, last);
        }

        // https://cplusplus.com/reference/map/map/swap/
        void swap(map &m) {
            std::swap(_alloc, m._alloc);
            std::swap(_key_compare, m._key_compare);
            std::swap(_value_compare, m._value_compare);
            _rbtree.swap(m._rbtree);
        }

        //// Observers

        // https://cplusplus.com/reference/map/map/key_comp/
        key_compare key_comp() const { return _key_compare; }

        // https://cplusplus.com/reference/map/map/value_comp/
        value_compare value_comp() const { return _value_compare; }

        //// Operations

        // https://cplusplus.com/reference/map/map/count/
        size_type count(const key_type &k) const {
            iterator it = find(k);
            return (it == end() ? 0 : 1);
        }

        // https://cplusplus.com/reference/map/map/equal_range/
        ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const {
            return _rbtree.equal_range(ft::make_pair(k, mapped_type()));
        }
        ft::pair<iterator, iterator> equal_range(const key_type &k) {
            return _rbtree.equal_range(ft::make_pair(k, mapped_type()));
        }

        // https://cplusplus.com/reference/map/map/find/
        iterator find(const key_type &k) { return _rbtree.find(ft::make_pair(k, mapped_type())); }
        const_iterator find(const key_type &k) const { return _rbtree.find(ft::make_pair(k, mapped_type())); }

        // https://cplusplus.com/reference/map/map/get_allocator/
        allocator_type get_allocator() const { return _alloc; }

        // https://cplusplus.com/reference/map/map/lower_bound/
        iterator lower_bound(const key_type &k) { return _rbtree.lower_bound(ft::make_pair(k, mapped_type())); }
        const_iterator lower_bound(const key_type &k) const { return _rbtree.lower_bound(ft::make_pair(k, mapped_type())); }

        // https://cplusplus.com/reference/map/map/upper_bound/
        iterator upper_bound(const key_type &k) { return _rbtree.upper_bound(ft::make_pair(k, mapped_type())); }
        const_iterator upper_bound(const key_type &k) const { return _rbtree.upper_bound(ft::make_pair(k, mapped_type())); }

    };

    //// Non-member function overloads
    // https://cplusplus.com/reference/map/map/swap-free/
    template< class Key, class T, class Compare, class Alloc >
    void swap(ft::map<Key, T, Compare, Alloc>& lhs, ft::map<Key, T, Compare, Alloc>& rhs) {
        lhs.swap(rhs);
    }

    // https://cplusplus.com/reference/map/map/operators/
    template<class Key, class T, class Compare, class Alloc>
    bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
        if (lhs.size() != rhs.size()) return false;
        return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
        return !(lhs == rhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
        return rhs < lhs;
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
        return !(rhs < lhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
        return !(lhs < rhs);
    }

} // namespace ft

#endif //FT_CONTAINERS_MAP_HPP
