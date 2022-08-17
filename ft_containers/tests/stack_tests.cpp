#include "stack_tests.h"


void stack_constructor_tests() {
    TEST_SECTION("STACK CONSTRUCTOR TESTS");

    ft::vector<int> ft_vector(2, 200);
    std::deque<int> std_deque(3, 100);

    TEST("Empty Constructor");
    ft::stack<int> ftEmpty;
    std::stack<int> stdEmpty;
    OK();

    TEST("Stack using ft::vector");
    ft::stack<int> ft_stack_vector(ft_vector);
    std::stack<int, ft::vector<int> > std_stack_vector(ft_vector);
    OK();

    TEST("Stack using std::deque");
    ft::stack<int, std::deque<int> > ft_stack_deque(std_deque);
    std::stack<int> std_stack_deque(std_deque);
    OK();
}

void stack_member_functions_tests() {
    TEST_SECTION("STACK MEMBER FUNCTIONS TESTS");

    ft::stack<int> ft;
    std::stack<int> std;

    TEST("empty()");
    ft.empty() == std.empty() ? OK() : ERR("Error on stack empty return");

    TEST("push()");
    ft.push(42);
    std.push(42);
    ft.top() == std.top() ? OK() : ERR("Error on stack push");

    TEST("top()");
    ft.push(84);
    ft.push(168);
    std.push(84);
    std.push(168);
    ft.top() == std.top() ? OK() : ERR("Error on stack top");

    TEST("size()");
    ft.size() == std.size() ? OK() : ERR("Error on stack size");

    TEST("pop()");
    ft.pop();
    std.pop();
    ft.size() == std.size() && ft.top() == ft.top() ? OK() : ERR("Error on stack pop");
}

void stack_non_member_overloads_tests() {
    TEST_SECTION("STACK NON MEMBER FUNCTION OVERLOAD TESTS");

    ft::vector<int> ft_vector(2, 200);
    ft::vector<int> ft_vector2(6, 100);

    ft::stack<int, ft::vector<int> > ft_stack(ft_vector);
    std::stack<int, ft::vector<int> > std_stack(ft_vector);

    ft::stack<int, ft::vector<int> > ft_stack2(ft_vector2);
    std::stack<int, ft::vector<int> > std_stack2(ft_vector2);

    TEST("Operator ==");
    ((ft_stack == ft_stack2) == (std_stack == std_stack2)) ? OK() : ERR("Difference on operator ==");

    TEST("Operator !=");
    ((ft_stack != ft_stack2) == (std_stack != std_stack2)) ? OK() : ERR("Difference on operator !=");

    TEST("Operator <");
    ((ft_stack < ft_stack2) == (std_stack < std_stack2)) ? OK() : ERR("Difference on operator <");

    TEST("Operator >");
    ((ft_stack > ft_stack2) == (std_stack > std_stack2)) ? OK() : ERR("Difference on operator >");

    TEST("Operator <=");
    ((ft_stack <= ft_stack2) == (std_stack <= std_stack2)) ? OK() : ERR("Difference on operator <=");

    TEST("Operator >=");
    ((ft_stack >= ft_stack2) == (std_stack >= std_stack2)) ? OK() : ERR("Difference on operator >=");
}

void stack_complex_types_tests() {
    TEST_SECTION("STACK COMPLEX TYPES TESTS");

    bool isEqual = true;

    TEST("Stack of complex type");
    ft::stack<std::string> ft_string_stack;
    std::stack<std::string> std_string_stack;

    for (int i = 0; i < 100; i++) {
        std::string tmp_str = random_string();

        ft_string_stack.push(tmp_str);
        std_string_stack.push(tmp_str);
    }

    for (int i = 0; i < 100; i++) {
        std::string ft_str = ft_string_stack.top();
        std::string std_str = std_string_stack.top();

        if (ft_str != std_str) {
            isEqual = false;
            break;
        }

        ft_string_stack.pop();
        std_string_stack.pop();
    }
    isEqual ? OK() : ERR("Stacks has different complex types");
}

void stack_performance_testes() {
    TEST_SECTION("STACK PERFORMANCE TESTS");
    struct timeval start, stop;

    srand(time(NULL));

    ft::stack<int, ft::vector<int> > ft_stack;
    std::stack<int, std::vector<int> > std_stack;

    gettimeofday (&start, NULL);
    for (int i = 0; i < STACK_SIZE; i++) ft_stack.push(rand());
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(FT_STACK).append("Time taken to push to stack."));

    gettimeofday (&start, NULL);
    for (int i = 0; i < STACK_SIZE; i++) std_stack.push(rand());
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(STD_STACK).append("Time taken to push to stack."));

    gettimeofday (&start, NULL);
    for (int i = 0; i < STACK_SIZE; i++) {
        ft_stack.top();
        ft_stack.pop();
    }
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(FT_STACK).append("Time taken to read and pop the stack."));

    gettimeofday (&start, NULL);
    for (int i = 0; i < STACK_SIZE; i++) {
        std_stack.top();
        std_stack.pop();
    }
    gettimeofday (&stop, NULL);
    PRINT_TIME(start, stop, std::string(STD_STACK).append("Time taken to read and pop the stack."));
}