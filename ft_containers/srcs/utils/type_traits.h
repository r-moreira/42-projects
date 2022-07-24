#ifndef FT_CONTAINERS_TYPE_TRAITS_H
#define FT_CONTAINERS_TYPE_TRAITS_H

//// Type Traits: https://cplusplus.com/reference/type_traits/?kw=type_traits

namespace ft {

    //// Enable If: https://m.cplusplus.com/reference/type_traits/enable_if/
    template<bool B, class T = void> struct enable_if {};
    template<class T> struct enable_if<true, T> { typedef T type; };

    //// Is Integral: https://m.cplusplus.com/reference/type_traits/is_integral/
    template <class T> struct is_integral { static const bool value = false; };
    template<> struct is_integral<bool> { static const bool value = true; };
    template<> struct is_integral<char> { static const bool value = true; };
    template<> struct is_integral<wchar_t> { static const bool value = true; };
    template<> struct is_integral<signed char> { static const bool value = true; };
    template<> struct is_integral<short int> { static const bool value = true; };
    template<> struct is_integral<int> { static const bool value = true; };
    template<> struct is_integral<long int> { static const bool value = true; };
    template<> struct is_integral<long long int> { static const bool value = true; };
    template<> struct is_integral<unsigned char> { static const bool value = true; };
    template<> struct is_integral<unsigned short int> { static const bool value = true; };
    template<> struct is_integral<unsigned int> { static const bool value = true; };
    template<> struct is_integral<unsigned long int> { static const bool value = true; };
    template<> struct is_integral<unsigned long long int> { static const bool value = true; };
} // namespace ft

#endif //FT_CONTAINERS_TYPE_TRAITS_H
