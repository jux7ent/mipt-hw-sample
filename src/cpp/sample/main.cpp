#include "Matrix.h"

int main() {
    Matrix m1(2, 2);
    Matrix m2(2, 2);
    m1.set();
    m2.set();
    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;

    std::cout << (m1 * m2) << std::endl;
    std::cout << m1[1][1] << std::endl;

    return 0;
}