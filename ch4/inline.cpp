#include <print>

inline void swap(int &x, int &y);

int main()
{
    int a = 1, b = 2;
    std::println("a={}, b={}", a, b);
    swap(a, b);
    std::println("a={}, b={}", a, b);
}

inline void swap(int &x, int &y)
{
    auto z = x;
    x = y;
    y = z;
}