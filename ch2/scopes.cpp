#include <print>

using namespace std;

auto a{1.5f};              // will have name clashes in unrelated parts of code
static int b = {10};       // local to translation unit (each file, AKA file static)
thread_local int c = {50}; // local to each new thread, adds semi-hidden time & space costs due to initialization when new thread is created
int main()
{
    // :: is global scope resolution operator
    println("{}", ::a);

    unsigned int a{2U};
    println("{}", ::a);

    {
        auto a{2.5};
        println("{}", ::a);
    }
    println("{} {}", b, c);
}