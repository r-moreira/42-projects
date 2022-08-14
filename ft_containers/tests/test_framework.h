#ifndef FT_CONTAINERS_TEST_FRAMEWORK_H
#define FT_CONTAINERS_TEST_FRAMEWORK_H

#define VECTOR_SIZE 10000000
#define STD_VECTOR  "\033[1;33m>\033[0m \033[1;31m std::vector: \033[0m"
#define FT_VECTOR  "\033[1;33m>\033[0m \033[1;32m ft::vector: \033[0m"

void PRINT_TIME(struct timeval& start, struct timeval& end, std::string str);

void TEST_SECTION(const std::string& desc);

void TEST(const std::string& desc);

void TODO();

void OK();

void ERR(const std::string& msg);

template<typename T, typename  V> void
ERR(T ft, V std) {
    std::cout << "\033[1;31mERROR: The elements are different\033[0m" << std::endl;
    std::cout << "\tft = " << ft <<  std::endl;
    std::cout << "\tstd: " << std << std::endl;
}

int randomIndex(int max);

#endif //FT_CONTAINERS_TEST_FRAMEWORK_H
