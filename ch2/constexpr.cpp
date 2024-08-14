#include <print>
#include <cmath>

using namespace std;

// stronger form of const
// explicitly causes evaluation at compile-time
// used in metaprogramming (causing code to be generated nad run at compile-time)
const double PI1 = acos(-1.0); // using constexpr gives error ("expression did not evaluate to a constant")
constexpr double PI2 = 22.0 / 7.0;

// static_assert(PI1 > 3.141 && PI1 < 3.143);  // only constexpr entity can be testing in static_assert
static_assert(PI2 > 3.141 && PI2 < 3.143);

int main()
{
    println("PI1={}, PI2={}", PI1, PI2);
}