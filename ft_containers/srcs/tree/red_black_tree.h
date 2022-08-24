#ifndef FT_CONTAINERS_RED_BLACK_TREE_H
#define FT_CONTAINERS_RED_BLACK_TREE_H

#include "../iterator/tree_iterator.h"
#include "../iterator/reverse_iterator.h"
#include "../utils/pair.h"
#include "../utils/type_traits.h"

namespace ft {
    typedef enum color { BLACK, RED } e_color;

    template <class T> class node {

    public:
        typedef T	value_type;
        T           value;
        node        *parent;
        node        *left;
        node        *right;
        e_color     color;

        explicit node(T const &val) : value(val) {}
    };

    template <class T,
            class Compare,
            class Alloc = std::allocator<node<T> > >

    class red_black_tree {

    public:
        //// Member Types
        typedef T                                       value_type;
        typedef Compare                                 key_compare;
        typedef Alloc                                   allocator_type;
        typedef node<T>                                 node_type;
        typedef node<T>                                 &reference;
        typedef node<T>                                 *pointer;
        typedef const node<T>                           const_node_type;
        typedef const node<T>                           &const_reference;
        typedef const node<T>                           *const_pointer;
        typedef ft::tree_iterator<node_type>            iterator;
        typedef ft::reverse_iterator<iterator>          reverse_iterator;
        typedef ft::tree_iterator<node_type>            const_iterator;
        typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;
        typedef std::ptrdiff_t                          difference_type;
        typedef std::size_t                             size_type;

    private:
        //// Private Attributes

        allocator_type  _alloc;
        key_compare     _compare;
        pointer         _ptr_root;
        pointer         _ptr_null;
        size_type       _size;

    public:

        //// Constructors

        explicit red_black_tree(allocator_type alloc = allocator_type()) :
                _alloc(alloc),
                _compare(key_compare()),
                _ptr_root(NULL),
                _ptr_null(NULL),
                _size(0) {
            _reserve_empty_node();
        }

        red_black_tree(const red_black_tree &x) :
            _alloc(x._alloc),
            _ptr_root(NULL),
            _ptr_null(NULL),
            _size(0) {
            _reserve_empty_node();
            _copy_rbtree(x._ptr_root, x._ptr_null);
        }

        red_black_tree &operator=(const red_black_tree &rhs) {
            if (this == &rhs) return *this;

            clear();
            _clear_empty_node();
            _alloc = rhs._alloc;
            _reserve_empty_node();
            _copy_rbtree(rhs._ptr_root, rhs._ptr_null);

            return *this;
        }

        //// Destructor

        ~red_black_tree() {
            clear();
            _clear_empty_node();
        }

        //// Iterators

        iterator begin() { return iterator(_ptr_root, _min_node(_ptr_root), _ptr_null); }

        iterator end() { return iterator(_ptr_root, _ptr_null, _ptr_null); }

        reverse_iterator rbegin() { return reverse_iterator(end()); }

        reverse_iterator rend() { return reverse_iterator(begin()); }

        const_iterator begin() const { return const_iterator(_ptr_root, _min_node(_ptr_root), _ptr_null); }

        const_iterator end() const { return const_iterator(_ptr_root, _ptr_null, _ptr_null); }

        const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

        const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

        //// Capacity

        bool empty() const { return (_size == 0); }

        size_type size() const { return _size; }

        size_type max_size() const { return _alloc.max_size(); }

        //// Modifiers

        void clear() {
            _clear_nodes(_ptr_root);
            _ptr_root = _ptr_null;
            _size = 0;
        }

        void erase(iterator pos) { if (pos != end()) _remove_node(pos.node_pointer); }

        size_type erase(const value_type &k) {
            pointer node = _find_node(k);
            if (!node) return 0;

            _remove_node(node);
            return 1;
        }

        void erase(iterator first, iterator last) {
            while (first != last)
                erase(first++);
        }

        ft::pair<iterator, bool> insert(const value_type &val) { return _insert_node(val); }

        iterator insert(iterator pos, const value_type &val) {
            (void) pos;
            return insert(val).first;
        }

        template<class InputIterator>
        void insert(InputIterator first, InputIterator last,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL) {
            for (; first != last; ++first)
                _insert_node(*first);
        }

        void swap(red_black_tree &rhs) {
            std::swap(_alloc, rhs._alloc);
            std::swap(_compare, rhs._compare);
            std::swap(_ptr_root, rhs._ptr_root);
            std::swap(_ptr_null, rhs._ptr_null);
            std::swap(_size, rhs._size);
        }

        //// Operations

        ft::pair<iterator, iterator> equal_range(const value_type &k) {
            iterator first = lower_bound(k);
            iterator last = upper_bound(k);

            return ft::make_pair(first, last);
        }

        ft::pair<const_iterator, const_iterator> equal_range(const value_type &k) const {
            const_iterator first = lower_bound(k);
            const_iterator last = upper_bound(k);

            return ft::make_pair(first, last);
        }

        iterator find(const value_type &value) {
            pointer tmp = _find_node(value);

            if (tmp) return iterator(_ptr_root, tmp, _ptr_null);
            return end();
        }

        const_iterator find(const value_type &value) const {
            pointer tmp = _find_node(value);

            if (tmp) return const_iterator(_ptr_root, tmp, _ptr_null);
            return end();
        }

        iterator lower_bound(const value_type &value) {
            for (iterator it = begin(); it != end(); ++it)
                if (_compare(it.node_pointer->value, value) == false)
                    return it;
            return end();
        }

        const_iterator lower_bound(const value_type &value) const {
            for (const_iterator it = begin(); it != end(); ++it)
                if (_compare(it.node_pointer->value, value) == false)
                    return it;
            return end();
        }

        iterator upper_bound(const value_type &value) {
            for (iterator it = begin(); it != end(); ++it)
                if (_compare(value, it.node_pointer->value))
                    return it;
            return end();
        }

        const_iterator upper_bound(const value_type &value) const {
            for (const_iterator it = begin(); it != end(); ++it)
                if (_compare(value, it.node_pointer->value))
                    return it;
            return end();
        }

    private:
        //// Private Methods

        void _reserve_empty_node() {
            _ptr_null = _alloc.allocate(1);
            _ptr_null->parent = _ptr_null;
            _ptr_null->left = _ptr_null;
            _ptr_null->right = _ptr_null;
            _ptr_root = _ptr_null;
            _ptr_null->color = BLACK;
        }

        pointer _reserve_node(const value_type &val) {
            pointer node = _alloc.allocate(1);
            node->left = _ptr_null;
            node->right = _ptr_null;
            node->parent = _ptr_null;
            node->value = val;
            node->color = RED;
            ++_size;
            return node;
        }

        void _clear_empty_node() {
            if (_ptr_null == NULL) return;

            _alloc.destroy(_ptr_null);
            _alloc.deallocate(_ptr_null, 1);
            _ptr_null = NULL;
        }

        void _clear_node(pointer node) {
            _alloc.destroy(node);
            _alloc.deallocate(node, 1);
            --_size;
        }

        void _clear_nodes(pointer node) {
            if (node == NULL || node == _ptr_null) return;

            _clear_nodes(node->left);
            _clear_nodes(node->right);
            _clear_node(node);
        }

        void _rotate_left(pointer node) {
            pointer tmp = node->right;

            node->right = tmp->left;
            if (tmp->left != _ptr_null)
                tmp->left->parent = node;

            tmp->parent = node->parent;
            if (node->parent == _ptr_null)
                _ptr_root = tmp;
            else if (node == node->parent->left)
                node->parent->left = tmp;
            else
                node->parent->right = tmp;
            tmp->left = node;
            node->parent = tmp;
        }

        void _rotate_right(pointer node) {
            pointer tmp = node->left;

            node->left = tmp->right;
            if (tmp->right != _ptr_null)
                tmp->right->parent = node;

            tmp->parent = node->parent;
            if (node->parent == _ptr_null)
                _ptr_root = tmp;
            else if (node == node->parent->right)
                node->parent->right = tmp;
            else
                node->parent->left = tmp;
            tmp->right = node;
            node->parent = tmp;
        }

        void _swap_pointers(pointer u, pointer v) {
            if (u->parent == _ptr_null)
                _ptr_root = v;
            else if (u == u->parent->left)
                u->parent->left = v;
            else
                u->parent->right = v;
            v->parent = u->parent;
        }

        pointer _find_node(const value_type &data) const {
            pointer node = _ptr_root;

            while (node != _ptr_null) {
                if (_compare(data, node->value))
                    node = node->left;
                else if (_compare(node->value, data))
                    node = node->right;
                else
                    return node;
            }
            return NULL;
        }

        pointer _min_node(pointer node) const {
            while (node->left != _ptr_null)
                node = node->left;
            return node;
        }

        void _copy_rbtree(pointer node, pointer null) {
            if (node == _ptr_null || node == null)
                return;
            _copy_rbtree(node->left, null);
            _insert_node(node->value);
            _copy_rbtree(node->right, null);
        }

        ft::pair<iterator, bool> _insert_node(const value_type &val) {
            pointer exist = _find_node(val);
            if (exist) return ft::make_pair(iterator(_ptr_root, exist, _ptr_null), false);

            pointer node = _reserve_node(val);
            pointer root = _ptr_root;
            pointer p = _ptr_null;

            while (root != _ptr_null) {
                p = root;
                if (_compare(val, root->value))
                    root = root->left;
                else
                    root = root->right;
            }
            node->parent = p;

            if (p == _ptr_null)
                _ptr_root = node;
            else if (_compare(node->value, p->value))
                p->left = node;
            else
                p->right = node;

            if (node->parent == _ptr_null) {
                node->color = BLACK;
                return ft::make_pair(iterator(_ptr_root, node, _ptr_null), true);
            }

            if (node->parent->parent == _ptr_null)
                return ft::make_pair(iterator(_ptr_root, node, _ptr_null), true);

            _balance_insert(node);

            return ft::make_pair(iterator(_ptr_root, node, _ptr_null), true);
        }

        void _remove_node(pointer node) {
            if (node == NULL || node == _ptr_null) return;

            pointer root = _ptr_root;
            pointer z = _ptr_null;

            while (root != _ptr_null) {
                if (_compare(node->value, root->value) == 0)
                    z = root;

                if (_compare(node->value, root->value) > 0)
                    root = root->left;
                else
                    root = root->right;
            }

            if (z == _ptr_null)
                return;

            pointer x;
            pointer y = z;
            color y_orig_color = y->color;

            if (z->left == _ptr_null) {
                x = z->right;
                _swap_pointers(z, z->right);
            } else if (z->right == _ptr_null) {
                x = z->left;
                _swap_pointers(z, z->left);
            } else {
                y = _min_node(z->right);
                y_orig_color = y->color;
                x = y->right;
                if (y->parent == z) {
                    x->parent = y;
                } else {
                    _swap_pointers(y, y->right);
                    y->right = z->right;
                    y->right->parent = y;
                }
                _swap_pointers(z, y);
                y->left = z->left;
                y->left->parent = y;
                y->color = z->color;
            }
            _clear_node(z);
            if (y_orig_color == BLACK)
                _balance_delete(x);
        }

        void _balance_insert(pointer node) {
            pointer u;

            while (node->parent->color == RED) {
                if (node->parent == node->parent->parent->right) {
                    u = node->parent->parent->left;
                    if (u->color == RED) {
                        u->color = BLACK;
                        node->parent->color = BLACK;
                        node->parent->parent->color = RED;
                        node = node->parent->parent;
                    } else {
                        if (node == node->parent->left) {
                            node = node->parent;
                            _rotate_right(node);
                        }
                        node->parent->color = BLACK;
                        node->parent->parent->color = RED;
                        _rotate_left(node->parent->parent);
                    }
                } else {
                    u = node->parent->parent->right;
                    if (u->color == RED) {
                        u->color = BLACK;
                        node->parent->color = BLACK;
                        node->parent->parent->color = RED;
                        node = node->parent->parent;
                    } else {
                        if (node == node->parent->right) {
                            node = node->parent;
                            _rotate_left(node);
                        }
                        node->parent->color = BLACK;
                        node->parent->parent->color = RED;
                        _rotate_right(node->parent->parent);
                    }
                }
                if (node == _ptr_root)
                    break;
            }
            _ptr_root->color = BLACK;
        }

        void _balance_delete(pointer node) {
            pointer s;

            while (node != _ptr_root && node->color == BLACK) {
                if (node == node->parent->left) {
                    s = node->parent->right;
                    if (s->color == 1) {
                        s->color = BLACK;
                        node->parent->color = RED;
                        _rotate_left(node->parent);
                        s = node->parent->right;
                    }
                    if (s->left->color == BLACK && s->right->color == BLACK) {
                        s->color = RED;
                        node = node->parent;
                    } else {
                        if (s->right->color == BLACK) {
                            s->left->color = BLACK;
                            s->color = RED;
                            _rotate_right(s);
                            s = node->parent->right;
                        }
                        s->color = node->parent->color;
                        node->parent->color = BLACK;
                        s->right->color = BLACK;
                        _rotate_left(node->parent);
                        node = _ptr_root;
                    }
                } else {
                    s = node->parent->left;
                    if (s->color == 1) {
                        s->color = BLACK;
                        node->parent->color = RED;
                        _rotate_right(node->parent);
                        s = node->parent->left;
                    }
                    if (s->right->color == BLACK && s->right->color == BLACK) {
                        s->color = RED;
                        node = node->parent;
                    } else {
                        if (s->left->color == BLACK) {
                            s->right->color = BLACK;
                            s->color = RED;
                            _rotate_left(s);
                            s = node->parent->left;
                        }
                        s->color = node->parent->color;
                        node->parent->color = BLACK;
                        s->left->color = BLACK;
                        _rotate_right(node->parent);
                        node = _ptr_root;
                    }
                }
            }
            node->color = BLACK;
        }

    };

} // namespace ft

#endif //FT_CONTAINERS_RED_BLACK_TREE_H
