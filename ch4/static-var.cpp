#include <print>

using namespace std;

// file-static variable
static int s{1};
void f()
{
    // static local variable AKA function-static variable
    // these are actually global variable, so their value is preserved b/w function calls
    // but they are only visible to this function
    // they are deprecated as they aren't thread-safe
    static int s{1};
    println("{}", s);
    s++;
}

void g()
{
    // visibility: within function
    // initialized: when new thread created
    thread_local int t{100};
    println("{}", t);
    s++;
}

void h()
{
    // thread local (created when new thread)
    // static (accessible within this translation unit)
    // local variable
    thread_local static int u{2000};
    println("{}", u);
    u++;
}

// static function -> visible within this translation unit
static void i()
{
    static int s{500};
    println("{}", s);
    s++;
}

int main()
{
    f();
    s = -1; // doesn't affect the function-static variable
    f();
    f();

    g();
    g();
    g();

    h();
    h();
    h();

    i();
    i();
    i();
}