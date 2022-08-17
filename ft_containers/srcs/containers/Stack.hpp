#ifndef FT_CONTAINERS_STACK_HPP
#define FT_CONTAINERS_STACK_HPP

#include "Vector.hpp"

//// Stack: https://cplusplus.com/reference/stack/stack/

namespace ft {

    template <class T, class Container = ft::vector<T> >
    class stack {

    public:
        //// Member Types
        typedef T			                                value_type;
        typedef Container	                                container_type;
        typedef size_t		                                size_type;
        typedef typename container_type::reference			reference;
        typedef typename container_type::const_reference	const_reference;

    protected:
        //// Private Attribute
        container_type	container;

    public:
        //// Constructor: https://cplusplus.com/reference/stack/stack/stack/
        explicit stack(const container_type &ctnr = container_type()) : container(ctnr) {}

        ~stack() {}

        //// Member functions

        // https://cplusplus.com/reference/stack/stack/empty/
        bool empty() const { return container.empty(); }

        // https://cplusplus.com/reference/stack/stack/pop/
        void pop() { container.pop_back(); }

        // https://cplusplus.com/reference/stack/stack/push/
        void push(const value_type &val) { container.push_back(val); }

        // https://cplusplus.com/reference/stack/stack/size/
        size_type size() const { return container.size(); }

        // https://cplusplus.com/reference/stack/stack/top/
        value_type &top() { return container.back(); }
        const value_type &top() const { return container.back(); }

        // non-member function overloads: https://cplusplus.com/reference/stack/stack/operators/
        friend bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
            return (lhs.container == rhs.container);
        }

        friend bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
            return (lhs.container != rhs.container);
        }

        friend bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
            return (lhs.container < rhs.container);
        }

        friend bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
            return (lhs.container > rhs.container);
        }

        friend bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
            return (lhs.container <= rhs.container);
        }

        friend bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
            return (lhs.container >= rhs.container);
        }
    };
} // namespace ft

#endif //FT_CONTAINERS_STACK_HPP
