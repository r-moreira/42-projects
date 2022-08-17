#ifndef FT_CONTAINERS_STACK_TESTS_H
#define FT_CONTAINERS_STACK_TESTS_H

#include <cstdlib>
#include <string>
#include <sys/time.h>
#include <iostream>
#include "./test_framework.h"
#include "../srcs/containers/Vector.hpp"
#include <stack>
#include <vector>
#include "../srcs/containers/Stack.hpp"

void stack_constructor_tests();
void stack_member_functions_tests();
void stack_non_member_overloads_tests();
void stack_complex_types_tests();
void stack_performance_testes();
#endif //FT_CONTAINERS_STACK_TESTS_H
