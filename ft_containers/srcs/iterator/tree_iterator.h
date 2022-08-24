#ifndef FT_CONTAINERS_TREE_ITERATOR_H
#define FT_CONTAINERS_TREE_ITERATOR_H

#include <cstdlib>
#include <cstddef>
#include "../tree/red_black_tree.h"

namespace ft {

    template <class T> class tree_iterator {

    public:
        typedef T	                                *node;
        node	                                    node_pointer;
        node	                                    node_null;
        typedef ::std::bidirectional_iterator_tag	iterator_category;
        typedef typename T::value_type	            value_type;
        typedef value_type&	        	            reference;
        typedef value_type*		                    pointer;
        typedef const value_type&	                const_reference;
        typedef const value_type*	                const_pointer;
        typedef ptrdiff_t		                    difference_type;

    private:
        node node_root;

    public:
        tree_iterator() : node_pointer(NULL), node_null(NULL), node_root(NULL) {}

        tree_iterator(node root, node ptr, node nil) : node_pointer(ptr), node_null(nil), node_root(root) {}

        tree_iterator(const tree_iterator &t) {
            node_pointer = t.node_pointer;
            node_null = t.node_null;
            node_root = t.node_root;
        }

        tree_iterator &operator=(const tree_iterator &rhs) {
            if (this == &rhs) return *this;

            node_pointer = rhs.node_pointer;
            node_null = rhs.node_null;
            node_root = rhs.node_root;

            return *this;
        }

        ~tree_iterator() {}

        operator tree_iterator<T const>() const { return tree_iterator<T const>(node_root, node_pointer, node_null); }

        reference operator*() { return node_pointer->value; }

        const_reference operator*() const { return node_pointer->value; }

        pointer operator->() { return &(operator*()); }

        const_pointer operator->() const { return &(operator*()); }

        bool operator==(const tree_iterator &rhs) const { return (node_pointer == rhs.node_pointer); }

        bool operator!=(const tree_iterator &rhs) const { return (node_pointer != rhs.node_pointer); }

        tree_iterator& operator++() {
            if (node_pointer != node_null) node_pointer = _next_node(node_pointer);
            return *this;
        }

        tree_iterator operator++(int) {
            tree_iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        tree_iterator& operator--() {
            if (node_pointer != node_null)
                node_pointer = _previous_node(node_pointer);
            else {
                node ptr = node_root;
                while (ptr->right != node_null)
                    ptr = ptr->right;
                node_pointer = ptr;
            }
            return *this;
        }

        tree_iterator operator--(int) {
            tree_iterator tmp(*this);
            --(*this);
            return tmp;
        }

    private:
        node _next_node(node ptr) const {
            if (ptr->right != node_null) {
                ptr = ptr->right;
                while (ptr->left != node_null)
                    ptr = ptr->left;
                return ptr;
            }

            while (ptr->parent != node_null && ptr == ptr->parent->right)
                ptr = ptr->parent;
            return ptr->parent;
        }

        node _previous_node(node ptr) const {
            if (ptr->left != node_null) {
                ptr = ptr->left;
                while (ptr->right != node_null)
                    ptr = ptr->right;
                return ptr;
            }

            while (ptr->parent != node_null && ptr == ptr->parent->left)
                ptr = ptr->parent;
            return ptr->parent;
        }
    };
} // namespace ft

#endif //FT_CONTAINERS_TREE_ITERATOR_H
