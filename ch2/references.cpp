#include <print>

using namespace std;

auto alice_age{9};
int main()
{
    // 2 types: l-value & r-value references (since C++11) AKA forwarding references AKA universal references
    // here, only l-value discussed

    println("Alice's age: {}", alice_age);

    auto &alice_age_ref = alice_age;
    alice_age_ref = 10; // will give error if original variable was const
    println("Alice's age: {}", alice_age);

    const auto a{10};
    auto b = a; // can re-assign b
    const auto c = a;
    const auto d{11};
    auto e{12};        // can re-assign e
    const auto &f{12}; // const reference to a literal
    const auto &g = d;
    auto &h = e; // can re-assign h
    const auto &i = e;
    // inferred as const
    auto &j = d;
    auto &k = f;

    // commented out give "cannot assign to a variable that is const" error
    // a = 1;
    b = 1;
    // c = 1;
    // d = 1;
    e = 1;
    // f = 1;
    // g = d;
    h = 1;
    // i = 1;
    // j = d;
    // k = f;

    println("{} {} {} {} {} {} {} {} {} {} {}", a, b, c, d, e, f, g, h, i, j, k);
}