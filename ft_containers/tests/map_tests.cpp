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

void map_element_access_tests() {
    TEST_SECTION("MAP ELEMENT ACCESS TESTS");

    TEST("Operator []");
    ft::map<int, double> ft;
    std::map<int, double> std;
    ft[0] = 0.0;
    ft[1] = 1.1;
    ft[2] = 2.2;
    std[0] = 0.0;
    std[1] = 1.1;
    std[2] = 2.2;

    double ft_element = ft[1];
    double std_element = std[1];

    ft_element == std_element ? OK() : ERR(ft_element, std_element);
}

void map_capacity_tests() {
    TEST_SECTION("MAP CAPACITY TESTS");

    TEST("size()");
    ft::map<char, int> ft;
    std::map<char, int> std;

    ft['a'] = 0;
    ft['b'] = 1;
    ft['c'] = 2;
    std['a'] = 0;
    std['b'] = 1;
    std['c'] = 2;

    ft.size() == std.size() ? OK() : ERR("std and ft maps has different size");

    TEST("empty()");
    ft::map<int, std::string> ft_empty;
    std::map<int, std::string> std_empty;

    ft_empty.empty() == std_empty.empty() && ft.empty() == std.empty() ? OK() : ERR("std and ft maps emptiness are different");

    TEST("max_size()");
    ft.max_size() == std.max_size() && ft_empty.max_size() == std_empty.max_size() ? OK() : ERR("std and ft maps has different max size");
}

void map_modifiers_tests() {
    TEST_SECTION("MAP MODIFIERS TESTS");

    TEST("insert() - single element");
    ft::map<char, int> ft;
    std::map<char, int> std;

    ft::pair<ft::map<char, int>::iterator, bool> ft_ret, ft_ret2;
    std::pair<std::map<char, int>::iterator, bool> std_ret, std_ret2;

    ft_ret = ft.insert(ft::pair<char, int>('a', 0));
    std_ret = std.insert(std::pair<char, int>('a', 0));
    ft_ret2 = ft.insert(ft::pair<char, int>('a', 0));
    std_ret2 = std.insert(std::pair<char, int>('a', 0));

    ft_ret.second == std_ret.second && ft_ret2.second == std_ret2.second && map_compare(ft, std)
        ? OK()
        : ERR("ft and std maps has different single element insert behavior");

    TEST("insert() - with hint");
    ft::map<char, int>::iterator ft_it = ft.begin();
    std::map<char, int>::iterator std_it = std.begin();

    ft.insert(ft_it, ft::pair<char, int>('b', 1));
    ft.insert(ft_it, ft::pair<char, int>('c', 2));
    ft.insert(ft_it, ft::pair<char, int>('d', 3));
    std.insert(std_it, std::pair<char, int>('b', 1));
    std.insert(std_it, std::pair<char, int>('c', 2));
    std.insert(std_it, std::pair<char, int>('d', 3));
    map_compare(ft, std) ? OK() : ERR("ft and std maps has different insert with hint behavior");

    TEST("insert() - range");
    ft::map<char, int> ft2;
    std::map<char, int> std2;

    ft2.insert(ft.begin(), ft.end());
    std2.insert(std.begin(), std.end());
    map_compare(ft, std) ? OK() : ERR("ft and std maps has different range insert behavior");

    TEST("erase() - iterator position");
    ft_it = ft.begin();
    std_it = std.begin();

    ft.erase(ft_it);
    std.erase(std_it);
    map_compare(ft, std) ? OK() : ERR("ft and std maps has different erase iterator position behavior");

    TEST("erase() - key");
    ft.erase('d');
    std.erase('d');
    map_compare(ft, std) ? OK() : ERR("ft and std maps has different erase by key behavior");

    TEST("erase() - range");
    ft_it = ft.begin();
    std_it = std.begin();

    ft.erase(ft_it, ft.end());
    std.erase(std_it, std.end());
    map_compare(ft, std) ? OK() : ERR("ft and std maps has different range erase behavior");

    TEST("swap()");
    ft::map<char, int> ft_new;
    std::map<char, int> std_new;

    ft_new['x'] = 100;
    ft_new['y'] = 101;
    ft_new['z'] = 102;
    std_new['x'] = 100;
    std_new['y'] = 101;
    std_new['z'] = 102;

    ft.swap(ft_new);
    std.swap(std_new);
    map_compare(ft, std) && map_compare(ft_new, std_new) ? OK() : ERR("ft and std maps has different swap behavior");

    TEST("clear()");
    ft.clear();
    std.clear();
    map_compare(ft, std) ? OK() : ERR("ft and std maps has different clear behavior");
}

void map_observers_tests() {
    TEST_SECTION("MAP OBSERVERS TESTS");

    ft::map<long, float> ft;
    std::map<long, float> std;

    ft[0L] = 0.0f;
    ft[1L] = 1.1f;
    ft[2L] = 2.2f;
    std[0L] = 0.0f;
    std[1L] = 1.1f;
    std[2L] = 2.2f;

    ft::map<long, float>::iterator ft_it_start = ft.begin();
    std::map<long, float>::iterator std_it_start = std.begin();
    ft::map<long, float>::iterator ft_it_end = ft.end();
    std::map<long, float>::iterator std_it_end = std.end();

    TEST("key_comp()");
    ft::map<long, float>::key_compare ft_kcmp = ft.key_comp();
    std::map<long, float>::key_compare std_kcmp = std.key_comp();

    ft_kcmp(ft_it_start->first, ft_it_end->first) && std_kcmp(std_it_start->first, std_it_end->first)
        ? OK()
        : ERR("ft and std maps key compare has different behavior");

    TEST("value_comp()");
    ft::map<long, float>::value_compare ft_vcmp = ft.value_comp();
    std::map<long, float>::value_compare std_vcmp = std.value_comp();

    ft::pair<long, float> ft_pair_start = *ft.begin();
    ft::pair<long, float> ft_pair_end = *ft.end();
    std::pair<long, float> std_pair_start = *std.begin();
    std::pair<long, float> std_pair_end = *std.end();

    ft_vcmp(ft_pair_start, ft_pair_end) && std_vcmp(std_pair_start, std_pair_end)
        ? OK()
        : ERR("ft and std maps key compare has different behavior");
}

void map_operations_tests() {
    TEST_SECTION("MAP OPERATIONS TESTS");

    TEST("find()");
    ft::map<char, int> ft;
    std::map<char, int> std;

    ft::map<char, int>::iterator ft_it;
    std::map<char, int>::iterator std_it;

    ft::map<char, int>::const_iterator ft_it2;
    std::map<char, int>::const_iterator std_it2;

    ft['x'] = 100;
    ft['y'] = 101;
    ft['z'] = 102;
    std['x'] = 100;
    std['y'] = 101;
    std['z'] = 102;

    ft_it = ft.find('x');
    std_it = std.find('x');
    ft_it2 = ft.find('w');
    std_it2 = std.find('w');

    ft_it->second == std_it->second && ((ft_it2 == ft.end()) == (std_it2 == std.end()))
        ? OK()
        : ERR("ft and std maps find has different behavior");

    TEST("count()");
    ft.count('x') == std.count('x') && ft.count('w') == std.count('w')
        ? OK()
        : ERR("ft and std maps count has different behavior");

    TEST("lower_bound()");
    ft_it = ft.lower_bound('x');
    std_it = std.lower_bound('x');
    ft_it2 = ft.lower_bound('w');
    std_it2 = std.lower_bound('w');

    ft_it->second == std_it->second && ((ft_it2 == ft.end()) == (std_it2 == std.end()))
        ? OK()
        : ERR("ft and std maps lower_bound has different behavior");

    TEST("upper_bound()");
    ft_it = ft.upper_bound('x');
    std_it = std.upper_bound('x');
    ft_it2 = ft.upper_bound('w');
    std_it2 = std.upper_bound('w');

    ft_it->second == std_it->second && ((ft_it2 == ft.end()) == (std_it2 == std.end()))
        ? OK()
        : ERR("ft and std maps upper_bound has different behavior");

    TEST("equal_range()");
    ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ft_ret, ft_ret2;
    std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> std_ret, std_ret2;

    ft_ret = ft.equal_range('x');
    std_ret = std.equal_range('x');
    ft_ret2 = ft.equal_range('w');
    std_ret2 = std.equal_range('w');

    ft_ret.first->first == std_ret.first->first && ft_ret.first->second == std_ret.first->second
        && ft_ret.second->first == std_ret.second->first && ft_ret.second->second == std_ret.second->second
        && ft_ret2.first->first == std_ret2.first->first && ft_ret2.first->second == std_ret2.first->second
        && ft_ret2.second->first == std_ret2.second->first && ft_ret2.second->second == std_ret2.second->second
            ? OK()
            : ERR("ft and std maps equal_range has different behavior");

    TEST("get_allocator()");
    ft::map<char, int> ft2;
    std::map<char, int> std2;

    ft::pair<char, int> *p_ft;
    std::pair<char, int> *p_std;

    p_ft = reinterpret_cast<ft::pair<char, int> *>(ft2.get_allocator().allocate(5));
    p_std = reinterpret_cast<std::pair<char, int> *>(std2.get_allocator().allocate(5));

    for (int i = 0; i < 5; i++) {
        ft2
            .get_allocator()
            .construct(&p_ft[i], ft::pair<char, int>(i + '0', i));
        std2
            .get_allocator()
            .construct(reinterpret_cast<std::pair<const char, int> *>(&p_std[i]), std::pair<char, int>(i + '0', i));
    }

    bool is_ok = true;
    for (int i = 0; i < 5; i++) {
        if (p_ft[i].first != p_std[i].first || p_ft[i].second != p_std[i].second) {
            is_ok = false;
            break;
        }
    }

    is_ok  ? OK() : ERR("ft and std maps get_allocator has different behavior");

    for (int i = 0; i < 5; i++) {
        ft2.get_allocator().destroy(&p_ft[i]);
        std2.get_allocator().destroy(reinterpret_cast<std::pair<const char, int> *>(&p_std[i]));
    }
}

void map_non_member_overloads_tests() {
    TEST_SECTION("MAP NON MEMBER FUNCTIONS OVERLOAD TESTS");

    ft::map<char, int> ft, ft2;
    std::map<char, int> std, std2;

    ft['a'] = 0;
    ft['b'] = 1;
    ft['c'] = 2;
    std['a'] = 0;
    std['b'] = 1;
    std['c'] = 2;

    ft2['x'] = 100;
    ft2['y'] = 101;
    ft2['z'] = 102;
    std2['x'] = 100;
    std2['y'] = 101;
    std2['z'] = 102;

    TEST("ft::swap()");
    ft::swap(ft, ft2);
    std::swap(std, std2);
    map_compare(ft, std) && map_compare(ft2, std2) ? OK() : ERR("The maps were different after ft/std::swap");

    TEST("Operator ==");
    ((ft == ft2) == (std == std2)) ? OK() : ERR("Difference on operator ==");

    TEST("Operator !=");
    ((ft != ft2) == (std != std2)) ? OK() : ERR("Difference on operator !=");

    TEST("Operator <");
    ((ft < ft2) == (std < std2)) ? OK() : ERR("Difference on operator <");

    TEST("Operator >");
    ((ft > ft2) == (std > std2)) ? OK() : ERR("Difference on operator >");

    TEST("Operator <=");
    ((ft <= ft2) == (std <= std2)) ? OK() : ERR("Difference on operator <=");

    TEST("Operator >=");
    ((ft >= ft2) == (std >= std2)) ? OK() : ERR("Difference on operator >=");
}

void map_complex_types_tests() {
    TEST_SECTION("MAP COMPLEX TYPES TESTS");

    TEST("Map of complex type");
    ft::map<int, ft::pair<double, const char *> > ft;
    std::map<int, std::pair<double, const char *> > std;

    std::string str = random_string();

    for (int i = 0; i < 100; i++) {
        ft[i] = ft::make_pair((double) i, str.c_str());
        std[i] = std::make_pair((double) i, str.c_str());
    }

    bool is_equal = true;
    for (int i = 0; i < 100; i++) {
        double ft_dbl = ft[i].first;
        double std_dbl = std[i].first;
        const char * ft_str = ft[i].second;
        const char * std_str = std[i].second;

        if (ft_dbl != std_dbl || ft_str != std_str) {
            is_equal = false;
            break;
        }
    }

    is_equal ? OK() : ERR("Map has different complex types");
}

void map_performance_tests() {
    TEST_SECTION("MAP PERFORMANCE TESTS");
    struct timeval start, stop;

    srand(time(NULL));

    ft::map<int, int> ft_map;
    std::map<int, int> std_map;
    int tmp;

    gettimeofday (&start, NULL);
    for (int i = 0; i < MAP_SIZE; i++) ft_map[i] = rand();
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(FT_MAP).append("Time taken to write using indices. "));

    gettimeofday (&start, NULL);
    for (int i = 0; i < MAP_SIZE; i++) ft_map[i] = rand();
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(STD_MAP).append("Time taken to write using indices. "));

    gettimeofday (&start, NULL);
    for (int i = 0; i < MAP_SIZE; i++) tmp = ft_map[i];
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(FT_MAP).append("Time taken to read using indices, sequentially. "));

    gettimeofday (&start, NULL);
    for (int i = 0; i < MAP_SIZE; i++) tmp = std_map[i];
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(STD_MAP).append("Time taken to read using indices, sequentially."));

    gettimeofday (&start, NULL);
    for (int i = 0; i < MAP_SIZE; i++) tmp = ft_map[rand() % MAP_SIZE];
    gettimeofday (&stop, NULL);
    PRINT_TIME (start, stop, std::string(FT_MAP).append("Time taken to read using indices, randomly. "));

    gettimeofday (&start, NULL);
    for (int i = 0; i < MAP_SIZE; i++) tmp = std_map[rand() % MAP_SIZE];
    gettimeofday (&stop, NULL);
    PRINT_TIME (start, stop, std::string(STD_MAP).append("Time taken to read using indices, randomly."));

    ft::map<int, int> ft_map2;
    std::map<int, int> std_map2;

    ft::map<int, int>::iterator ft_itr;
    std::map<int, int>::iterator std_itr;

    gettimeofday (&start, NULL);
    ft_map2.insert(ft_map.begin(), ft_map.end());
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(FT_MAP).append("Time taken to write using iterators. "));

    gettimeofday (&start, NULL);
    std_map2.insert(std_map.begin(), std_map.end());
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(STD_MAP).append("Time taken to write using iterators."));

    gettimeofday (&start, NULL);
    for (int i = 0; i < MAP_SIZE; i++) ft_itr = ft_map2.find(i);
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(FT_MAP).append("Time taken to read using find(), sequentially. "));

    gettimeofday (&start, NULL);
    for (int i = 0; i < MAP_SIZE; i++) std_itr = std_map2.find(i);
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(STD_MAP).append("Time taken to read using find(), sequentially."));

    gettimeofday (&start, NULL);
    for (int i = 0; i < MAP_SIZE; i++) ft_itr = ft_map2.find(rand() % MAP_SIZE);
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(FT_MAP).append("Time taken to read using find(), randomly. "));

    gettimeofday (&start, NULL);
    for (int i = 0; i < MAP_SIZE; i++) std_itr = std_map2.find(rand() % MAP_SIZE);
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(STD_MAP).append("Time taken to read using find(), randomly."));

    (void)tmp;
}