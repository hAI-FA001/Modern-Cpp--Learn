#include <print>

using namespace std;

int main()
{
    // const can be before or after the type
    auto const A = 1;
    const auto B = 11.567;
    auto some_var = 12.3;
    // constant can be init from a var -> example of constant whose value is not known at compile-time
    // const-correctness = stricter use of const (using it where value shouldn't change or doesn't make sense to change)
    auto const C = some_var;

    println("A={}, B={}, A+B={}", A, B, A + B);
    println("C={}", C);
}