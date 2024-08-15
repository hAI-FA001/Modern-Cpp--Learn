#include <print>

using namespace std;

// auto return type is useful when returning > 1 values -> "aggregate" return type
auto get_nums()
{
    float a = 1.1f;
    int b = -100;
    unsigned c = 123U;

    return tuple{a, b, c}; // initalized with uniform initialization
}

auto get_nums(auto &ref1, auto &ref2)
{
    ref1 = 1.1f;
    ref2 = -100;
}

int main()
{
    // unpack aggregate into single variables using "structured binding"
    auto [a, b, c] = get_nums();
    println("Got {}, {} and {}", a, b, c);

    // another way to return results
    auto x = 100.f;
    auto y = 1;
    println("Before modify: {} {}", x, y);
    get_nums(x, y);
    println("After modify: {} {}", x, y);
}