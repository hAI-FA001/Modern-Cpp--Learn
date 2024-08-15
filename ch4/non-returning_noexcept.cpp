#include <iostream>

using namespace std;

// non-returning funcs, e.g. infinite loop, abnormal exit, etc
// these should have void type (cuz they don't return, so doesn't make sense)
[[noreturn]] void report_fatal_error(int e)
{
    cerr << "Fatal error code: " << e << '\n';
    // gives warning (noreturn has a return statemtnt)
    if (e > 0)
    {
        return;
    }

    // other options: abort(), exit(), quick_exit()
    // but they don't deallocate all global objects correctly
    // could throw too
    terminate();
}

// if a noexcept func calls non-noexcept func, then func is also implicitly noexcept
// so this guarantee (not throwing error) is preserved over func calls
// reason for noexcept: compiler & runtime don't have to support stack unwinding used by `throw`
// gives significant time & space advantage
void throw_if_zero(int i) noexcept
{
    if (!i)
    {
        // this will terminate()
        throw runtime_error("Got zero."); // gives warning
    }
    cout << "called throw_if_zero() with " << i << '\n';
}

int main()
{
    cout << "Calling...\n";
    // report_fatal_error(-1);
    // cout << "Exiting main()\n"; // will give unreachable code warning

    try
    {
        throw_if_zero(1);
        throw_if_zero(0); // will terminate() the program
    }
    catch (exception &e)
    {
        cout << "Caught: " << e.what() << '\n';
    }
}