#include <print>

using namespace std;

// each translation unit has its own unnamed namespace, so no clashes
// and this file can't access i in the other file's unnamed namespace

extern int i;

int main()
{
    println("i={}", i);
}