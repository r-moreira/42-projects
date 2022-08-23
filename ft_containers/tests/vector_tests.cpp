#include "vector_tests.h"

void vector_constructor_tests() {
    TEST_SECTION("VECTOR CONSTRUCTOR TESTS");

    int i;

    TEST("Empty Constructor");
    ft::vector<double> ftEmpty;
    std::vector<double> stdEmpty;
    OK();

    TEST("Fill Constructor with default value");
    ft::vector<double> ft(21);
    std::vector<double> std(21);
    i = random_index(21);
    ft[i] == std[i] ? OK() : ERR(ft[i], std[i]);

    TEST("Fill Constructor with specific value");
    ft::vector<int> ft2(21, 42);
    std::vector<int> std2(21, 42);
    i = random_index(21);
    ft2[i] == std2[i] ? OK() : ERR(ft2[i], std2[i]);

    TEST("Range Constructor");
    std::vector<int> tmp (4,100);
    ft::vector<int> ft3(tmp.begin(), tmp.end());
    std::vector<int> std3(tmp.begin(), tmp.end());
    ft::equal(ft3.begin(), ft3.end(), std3.begin()) ? OK() : ERR("The ft and std vectors are not equal");

    TEST("Copy Constructor");
    ft::vector<int> ft4(ft3);
    ft::equal(ft3.begin(), ft3.end(), std3.begin()) ? OK() : ERR("The copy vector are not equal to original vector");
}

void vector_element_access_tests() {
    TEST_SECTION("VECTOR ELEMENT ACCESS TESTS");

    TEST("Operator[]");
    ft::vector<int> ft_vect(42, 21);
    std::vector<int> std_vect(42, 21);

    ft::vector<int>::iterator ft_it;
    std::vector<int>::iterator std_it;

    int ft_element;
    int std_element;

    ft_it = ft_vect.begin() + 17;
    std_it = std_vect.begin() + 17;

    ft_vect.insert(ft_it, 84);
    std_vect.insert(std_it, 84);

    ft_element = ft_vect[17];
    std_element = std_vect[17];

    ft_element == std_element ? OK() : ERR(ft_element, std_element);

    TEST("at()");
    ft_element = ft_vect.at(17);
    std_element = std_vect.at(17);
    if (ft_element != 84) ERR("Invalid ft element");
    else ft_element == std_element ? OK() : ERR(ft_element, std_element);

    TEST("front()");
    ft_vect.insert(ft_vect.begin(), 77);
    std_vect.insert(std_vect.begin(), 77);

    ft_element = ft_vect.front();
    std_element = std_vect.front();
    if (ft_element != 77) ERR("Invalid ft element");
    else ft_element == std_element ? OK() : ERR(ft_element, std_element);

    TEST("back()");
    ft_vect.insert(ft_vect.end(), 22);
    std_vect.insert(std_vect.end(), 22);

    ft_element = ft_vect.back();
    std_element = std_vect.back();
    if (ft_element != 22) ERR("Invalid ft element");
    else ft_element == std_element ? OK() : ERR(ft_element, std_element);
}

void vector_capacity_tests() {
    TEST_SECTION("VECTOR CAPACITY TESTS");

    ft::vector<int> ft_vect(777, 42);
    std::vector<int> std_vect(777, 42);

    TEST("size()");
    ft_vect.size() == std_vect.size() ? OK() : ERR("ft and std vectors has different size");

    TEST("max_size()");
    ft_vect.max_size() == std_vect.max_size() ? OK() : ERR("ft and std vectors has different max_size");

    TEST("capacity()");
    ft_vect.capacity() == std_vect.capacity() ? OK() : ERR("ft and std vectors has different capacity");

    TEST("resize(n)");
    ft_vect.resize(10);
    std_vect.resize(10);
    ft_vect.size() == std_vect.size() ? OK() : ERR("ft and std vectors has different size after resize()");

    TEST("resize(n, val)");
    ft_vect.resize(50, 42);
    std_vect.resize(50, 42);
    if (ft_vect.size() != std_vect.size()) ERR("ft and std vectors has different size after resize");
    else ft_vect.back() == std_vect.back() ? OK() : ERR("ft and std vectors has different values when resizing n > size()");

    TEST("empty()");
    ft::vector<double> ft_empty;
    std::vector<double> std_empty;
    ft_empty.empty() == std_empty.empty() && ft_vect.empty() == std_vect.empty()
        ? OK()
        : ERR("ft and std vectors emptiness is not equal");

    TEST("reserve()");
    ft_vect.reserve(1000);
    std_vect.reserve(1000);
    ft_vect.capacity() == std_vect.capacity() ? OK() : ERR("ft and std vectors has different capacity after reserve()");
}

void vector_modifiers_tests() {
    TEST_SECTION("VECTOR MODIFIERS TESTS");

    ft::vector<float> ft_vect;
    std::vector<float> std_vect;
    ft::vector<float> ft_other_vect;
    std::vector<float> std_other_vect;
    ft::vector<float> ft_tmp (7, 11.1f);
    std::vector<float> std_tmp (7, 11.1f);

    TEST("assign() - fill");
    ft_vect.assign(7, 42.9f);
    std_vect.assign(7, 42.9f);
    ft::equal(ft_vect.begin(), ft_vect.end(), std_vect.begin()) ? OK() : ERR("The vectors fill assignment are not equal");

    TEST("assign() - iterator range");
    ft_other_vect.assign(ft_vect.begin() + 1, ft_vect.end() - 1);
    std_other_vect.assign(std_vect.begin() + 1, std_vect.end() - 1);
    ft::equal(ft_vect.begin(), ft_vect.end(), std_vect.begin()) ? OK() : ERR("The vectors iterator assignment are not equal");

    TEST("push_back()");
    ft_vect.push_back(17.7f);
    std_vect.push_back(17.7f);
    ft::equal(ft_vect.begin(), ft_vect.end(), std_vect.begin()) ? OK() : ERR("The vectors last pushed value are not equal");

    TEST("pop_back()");
    ft_vect.pop_back();
    std_vect.pop_back();
    ft::equal(ft_vect.begin(), ft_vect.end(), std_vect.begin()) ? OK() : ERR("The vectors last popped value are not equal");

    TEST("insert() - single element");
    ft_vect.insert(ft_vect.begin() + 5, 99.9f);
    std_vect.insert(std_vect.begin() + 5, 99.9f);
    ft::equal(ft_vect.begin(), ft_vect.end(), std_vect.begin()) ? OK() : ERR("The vectors inserted value are not equal");

    TEST("insert() - fill");
    ft_vect.insert(ft_vect.begin() + 2, 3, 44.4f);
    std_vect.insert(std_vect.begin() + 2, 3, 44.4f);
    ft::equal(ft_vect.begin(), ft_vect.end(), std_vect.begin()) ? OK() : ERR("The vectors fill inserted values are not equal");

    TEST("insert() - iterator range");
    ft_vect.insert(ft_vect.begin() + 5, ft_tmp.begin(), ft_tmp.end());
    std_vect.insert(std_vect.begin() + 5, std_tmp.begin(), std_tmp.end());
    ft::equal(ft_vect.begin(), ft_vect.end(), std_vect.begin()) ? OK() : ERR("The vectors iterator inserted values are not equal");

    TEST("erase() - single element");
    ft_vect.erase(ft_vect.begin() + 3);
    std_vect.erase(std_vect.begin() + 3);
    ft::equal(ft_vect.begin(), ft_vect.end(), std_vect.begin()) ? OK() : ERR("The vectors were different after erase a single element");

    TEST("erase() - iterator range");
    ft_vect.erase(ft_vect.begin() + 3, ft_vect.begin() + 10);
    std_vect.erase(std_vect.begin() + 3, std_vect.begin() + 10);
    ft::equal(ft_vect.begin(), ft_vect.end(), std_vect.begin()) ? OK() : ERR("The vectors were different after erase a range of elements");

    TEST("swap()");
    ft_vect.swap(ft_tmp);
    std_vect.swap(std_tmp);
    ft::equal(ft_vect.begin(), ft_vect.end(), std_vect.begin()) ? OK() : ERR("The vectors were different after swap values");

    TEST("clear()");
    ft_vect.clear();
    std_vect.clear();
    ft::equal(ft_vect.begin(), ft_vect.end(), std_vect.begin()) ? OK() : ERR("The vectors were different after clear()");

    TEST("get_allocator()");
    ft::vector<int> ft_vect2;
    std::vector<int> std_vect2;
    int *p_ft;
    int *p_std;

    p_ft = ft_vect2.get_allocator().allocate(5);
    p_std = std_vect2.get_allocator().allocate(5);

    for (int i = 0; i < 5; i++) {
        ft_vect2.get_allocator().construct(&p_ft[i], i);
        std_vect2.get_allocator().construct(&p_std[i], i);
    }

    ft::equal(p_ft, p_ft + 5, p_std) ? OK() : ERR("The arrays with vectors allocator were different");

    for (int i = 0; i < 5; i++) {
        ft_vect2.get_allocator().destroy(&p_ft[i]);
        std_vect2.get_allocator().destroy(&p_std[i]);
    }

}

void vector_non_member_overloads_tests() {
    TEST_SECTION("VECTOR NON MEMBER FUNCTIONS OVERLOAD TESTS");

    ft::vector<long> ft_vect(6, 48);
    std::vector<long> std_vect(6, 48);
    ft::vector<long> ft_tmp (12, 24);
    std::vector<long> std_tmp (12, 24);

    TEST("ft::swap()");
    ft::swap(ft_vect, ft_tmp);
    std::swap(std_vect, std_tmp);
    ft::equal(ft_vect.begin(), ft_vect.end(), std_vect.begin()) ? OK() : ERR("The vectors were different after ft/std::swap");

    TEST("Operator ==");
    ((ft_vect == ft_tmp) == (std_vect == std_tmp)) ? OK() : ERR("Difference on operator ==");

    TEST("Operator !=");
    ((ft_vect != ft_tmp) == (std_vect != std_tmp)) ? OK() : ERR("Difference on operator !=");

    TEST("Operator <");
    ((ft_vect < ft_tmp) == (std_vect < std_tmp)) ? OK() : ERR("Difference on operator <");

    TEST("Operator >");
    ((ft_vect > ft_tmp) == (std_vect > std_tmp)) ? OK() : ERR("Difference on operator >");

    TEST("Operator <=");
    ((ft_vect <= ft_tmp) == (std_vect <= std_tmp)) ? OK() : ERR("Difference on operator <=");

    TEST("Operator >=");
    ((ft_vect >= ft_tmp) == (std_vect >= std_tmp)) ? OK() : ERR("Difference on operator >=");
}

void vector_complex_types_tests() {
    TEST_SECTION("VECTOR COMPLEX TYPES TESTS");

    bool isEqual = true;

    TEST("Vector of complex type");
    ft::vector<std::string> ft_string_vector;
    std::vector<std::string> std_string_vector;

    for (int i = 0; i < 100; i++) {
        std::string tmp_str = random_string();

        ft_string_vector.push_back(tmp_str);
        std_string_vector.push_back(tmp_str);
    }

    for (int i = 0; i < 100; i++) {
        std::string ft_str = ft_string_vector.at(i);
        std::string std_str = std_string_vector.at(i);

        if (ft_str != std_str) {
            isEqual = false;
            break;
        }
    }
    isEqual ? OK() : ERR("Vectors has different complex types");
}

void vector_performance_tests() {
    TEST_SECTION("VECTOR PERFORMANCE TESTS");
    int tmp;
    struct timeval start, stop;

    srand(time(NULL));

    ft::vector<int> ft_vector(VECTOR_SIZE);
    std::vector<int> std_vector(VECTOR_SIZE);

    gettimeofday (&start, NULL);
    for (int i = 0; i < VECTOR_SIZE; i++) ft_vector[i] = rand();
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(FT_VECTOR).append("Time taken to write using indices. "));

    gettimeofday (&start, NULL);
    for (int i = 0; i < VECTOR_SIZE; i++) std_vector[i] = rand();
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(STD_VECTOR).append("Time taken to write using indices."));

    gettimeofday (&start, NULL);
    for (int i = 0; i < VECTOR_SIZE; i++) tmp = ft_vector[i];
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(FT_VECTOR).append("Time taken to read using indices, sequentially. "));

    gettimeofday (&start, NULL);
    for (int i = 0; i < VECTOR_SIZE; i++) tmp = std_vector[i];
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(STD_VECTOR).append("Time taken to read using indices, sequentially."));

    gettimeofday (&start, NULL);
    for (int i = 0; i < VECTOR_SIZE; i++) tmp = ft_vector[rand() % VECTOR_SIZE];
    gettimeofday (&stop, NULL);
    PRINT_TIME (start, stop, std::string(FT_VECTOR).append("Time taken to read using indices, randomly. "));

    gettimeofday (&start, NULL);
    for (int i = 0; i < VECTOR_SIZE; i++) tmp = std_vector[rand() % VECTOR_SIZE];
    gettimeofday (&stop, NULL);
    PRINT_TIME (start, stop, std::string(STD_VECTOR).append("Time taken to read using indices, randomly."));

    ft::vector<int> ft_vector2(VECTOR_SIZE);
    std::vector<int> std_vector2(VECTOR_SIZE);

    ft::vector<int>::iterator ft_itr, ft_itr_end;
    std::vector<int>::iterator std_itr, std_itr_end;

    gettimeofday (&start, NULL);
    for (ft_itr = ft_vector2.begin(), ft_itr_end = ft_vector2.end(); ft_itr != ft_itr_end; ft_itr++) *ft_itr = rand();
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(FT_VECTOR).append("Time taken to write using iterators. "));

    gettimeofday (&start, NULL);
    for (std_itr = std_vector2.begin(), std_itr_end = std_vector2.end(); std_itr != std_itr_end; std_itr++) *std_itr = rand();
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(STD_VECTOR).append("Time taken to write using iterators."));

    gettimeofday (&start, NULL);
    for (ft_itr = ft_vector2.begin(), ft_itr_end = ft_vector2.end(); ft_itr != ft_itr_end; ft_itr++) tmp = *ft_itr;
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(FT_VECTOR).append("Time taken to read using iterators. "));

    gettimeofday (&start, NULL);
    for (std_itr = std_vector2.begin(), std_itr_end = std_vector2.end(); std_itr != std_itr_end; std_itr++) tmp = *std_itr;
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(STD_VECTOR).append("Time taken to read using iterators."));

    (void)tmp;
}
