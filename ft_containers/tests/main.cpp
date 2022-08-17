#include "vector_tests.h"
#include "stack_tests.h"
#include "map_tests.h"

static void vector_tests() {
    vector_constructor_tests();
    vector_element_access_tests();
    vector_capacity_tests();
    vector_modifiers_tests();
    vector_non_member_overloads_tests();
    vector_complex_types_tests();
    vector_performance_tests();
}

static void stack_tests() {
    stack_constructor_tests();
    stack_member_functions_tests();
    stack_non_member_overloads_tests();
    stack_complex_types_tests();
    stack_performance_testes();
}

static void map_tests() {
    map_constructor_tests();
}

int main() {
    vector_tests();
    stack_tests();
    map_tests();
    return 0;
}