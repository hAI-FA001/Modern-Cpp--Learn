#include <iostream>

using namespace std;

// allows compiler to generate and run code at compile-time
// can run at both compile-time and run-time
// can't modify global state (e.g. cout)
constexpr int fact(int n)
{
    // will give error
    // cout << n;
    if (n < 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

// using constexpr function w/ static_assert
static_assert(fact(0) == 1);
static_assert(fact(5) == 120);

int main()
{
    cout << "Enter a number: ";

    int n{};
    cin >> n;

    cout << n << "! = " << fact(n) << '\n';
}