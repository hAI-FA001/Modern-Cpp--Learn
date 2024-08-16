#include <iostream>

int main()
{
    int gifts{0};

    // sequencing operator (comma) sneaks in 2 expressions where 1 is allowed
    // ++i, --j -> 2 expressions where 1 is allowed
    // another use is in ternary expressions
    for (int i{1}, j{12}; i <= 12; ++i, --j)
    {
        gifts += i * j;
    }
    std::cout << gifts << " gifts in total\n";

    gifts = 0;
    // w/o "j"
    for (int i{1}; i <= 12; ++i)
    {
        gifts += i * (13 - i);
    }
    std::cout << gifts << " gifts in total\n";
}