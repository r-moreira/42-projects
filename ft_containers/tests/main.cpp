#include "vector_tests.h"

int main() {
    vector_constructor_tests();
    vector_element_access_tests();
    vector_capacity_tests();
    vector_modifiers_tests();
    vector_non_member_fcnt_overloads_tests();
    vector_complex_types_tests();
    vector_performance_tests();

    return 0;
}