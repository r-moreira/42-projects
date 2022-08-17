#ifndef FT_CONTAINERS_VECTOR_TESTS_H
#define FT_CONTAINERS_VECTOR_TESTS_H

#include <iostream>
#include "./test_framework.h"
#include "../srcs/containers/Vector.hpp"
#include <vector>
#include <cstdlib>
#include <string>
#include <sys/time.h>

void vector_constructor_tests();
void vector_element_access_tests();
void vector_capacity_tests();
void vector_modifiers_tests();
void vector_non_member_overloads_tests();
void vector_complex_types_tests();
void vector_performance_tests();
#endif //FT_CONTAINERS_VECTOR_TESTS_H
