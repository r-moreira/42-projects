#include "map_tests.h"

template <typename T1, typename T2>
static bool map_compare(ft::map<T1, T2> ft, std::map<T1, T2> std) {
    typename ft::map<T1, T2>::iterator ft_it_start = ft.begin();
    typename ft::map<T1, T2>::iterator ft_it_end = ft.end();
    typename std::map<T1, T2>::iterator std_it_start = std.begin();

    for (; ft_it_start != ft_it_end; ft_it_start++, std_it_start++)
        if (*ft_it_start != ft::make_pair(std_it_start->first, std_it_start->second))
            return false;
    return true;
}

struct my_compare {
    bool operator() (const char& lhs, const char& rhs) const { return lhs < rhs ; }
};

void map_constructor_tests() {
    TEST_SECTION("MAP CONSTRUCTOR TESTS");

    TEST("Empty Constructor");
    ft::map<int, char> ft_map;
    std::map<int, char> std_map;
    OK();

    TEST("Constructor with Compare");
    ft::map<double, std::string, my_compare> ft_map2;
    std::map<double, std::string, my_compare> std_map2;
    OK();

    TEST("Range constructor");
    ft_map[0] = 'a';
    ft_map[1] = 'b';
    ft_map[2] = 'c';
    std_map[0] = 'a';
    std_map[1] = 'b';
    std_map[2] = 'c';

    ft::map<int, char> ft_map3(ft_map.begin(), ft_map.end());
    std::map<int, char> std_map3(std_map.begin(), std_map.end());

    map_compare(ft_map3, std_map3)
        ? OK()
        : ERR("The ft and std map content is different");

    TEST("Copy constructor");
    ft::map<int, char> ft_map4(ft_map3);
    std::map<int, char> std_map4(std_map3);

    ft_map4[3] = 'd';
    std_map4[3] = 'd';

    map_compare(ft_map4, std_map4)
    ? OK()
    : ERR("The ft and std map content is different");

}
