// import std;  // gives errors on println("{}", i)
#include <windows.h>
#include <print>

using namespace std;
// using namespace std::literals;

int main()
{
    // uniform initialization
    int i{};
    float j{};
    println("i is {}, j is {} / literal braces: {{}}", i, j); // using {} in print

    i = 2.5; // narrowing cast, int can't represent decimal
    j = 1;   // widening cast
    println("i={}, j={}", i, j);
}