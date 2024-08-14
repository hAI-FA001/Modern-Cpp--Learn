#include <print>

using namespace std;

// both files use static int i => main must have its own i
// both files don't use static => error (i already defined)
// only 1 file uses static => main is able to access the non-static i
extern int i;
int main()
{
    println("i is {}", i);
}