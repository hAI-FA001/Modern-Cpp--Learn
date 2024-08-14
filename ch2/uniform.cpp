#include <print>

using namespace std;

int main()
{
    int k = {1};
    // int k{1};  // braces are optional
    // int l = {2.5}; // using uniform initialization, compiler will give error on narrowing cast
    int l = {static_cast<int>(2.5)}; // this works, cuz we explicitly cast
    // k = {2.5};  // also gives error
    // {1} is not same as array {1,} -> array would have a comma
    float m = {2.5};
    float n = {static_cast<int>(2.5)};
    double o = {1LL};

    println("k={}, l={}, m={}, n={}, o={}", k, l, m, n, o);
}