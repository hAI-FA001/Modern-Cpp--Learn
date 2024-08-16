#include <iostream>

// main's return value is passed back to the environment
// main can receive args from the calling environment
// can add const with these
int main(const int argc, const char *const argv[])
{
    // can't use range-for loop as argv[] has no size info (array decay)
    // argv[0] is the name of program, argv[argc] is a null ptr
    for (int i{}; i != argc; ++i)
    {
        std::cout << "Arg " << i << ' is ' << argv[i] << '\n';
    }
}