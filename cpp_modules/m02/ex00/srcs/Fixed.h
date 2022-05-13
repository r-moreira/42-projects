#ifndef M02_FIXED_H
#define M02_FIXED_H

#include <iostream>

class Fixed {
public:
    Fixed();

    ~Fixed();

    Fixed(const Fixed &origin);

    int getRawBits() const;

    void setRawBits(int raw);

    Fixed &operator=(const Fixed &origin);

private:
    int value{};
    static const int n_bits = 8;
};

#endif //M02_FIXED_H
