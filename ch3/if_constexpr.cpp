#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // expressions in if are evaluated at run-time
    // but we can have it be evaluated at compile-time using constexpr

    // must use constexpr or const to declare this
    constexpr auto int_size = sizeof(int);
    if constexpr (int_size == 4)
    {
        cout << "32 bits\n";
    }
    else if constexpr (int_size == 8)
    {
        cout << "64 bits\n";
    }
    else
    {
        cout << "Some other bits: " << int_size << '\n';
    }

    constexpr double PI2 = 22.0 / 7.0;
    static_assert(PI2 > 3.141 && PI2 < 3.143); // old
    if constexpr (PI2 > 3.141 and PI2 < 3.143) // using constexpr
    {
        cout << "PI2 satisfies condition\n";
    }
    else
    {
        cout << "PI2 does not satisfy condition\n";
    }
}