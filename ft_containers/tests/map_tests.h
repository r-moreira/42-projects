#ifndef FT_CONTAINERS_MAP_TESTS_H
#define FT_CONTAINERS_MAP_TESTS_H

#include <cstdlib>
#include <string>
#include <sys/time.h>
#include <iostream>
#include "./test_framework.h"
#include <map>
#include "../srcs/containers/Map.hpp"

void map_constructor_tests();
void map_element_access_tests();
void map_capacity_tests();
void map_modifiers_tests();
void map_observers_tests();
void map_operations_tests();
void map_non_member_overloads_tests();
void map_complex_types_tests();
void map_performance_tests();

#endif //FT_CONTAINERS_MAP_TESTS_H
