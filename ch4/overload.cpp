#include <iostream>

using namespace std;

// works due to function name mangling at linker level where it augments function name with its parameter list

void overloaded(int i);
void overloaded(double i);

// this doesn't work (C linkage which doesn't perform name mangling)
extern "C"
{
    void wont_overloaded(int i);
    // void wont_overloaded(double i);
}

int main()
{
    overloaded(1);
    overloaded(1.1);

    // "best-match" performed for these
    overloaded(1.1f);
    overloaded('a');
}

void overloaded(int i)
{
    cout << "overloaded(int i) called \n";
}

void overloaded(double i)
{
    cout << "overloaded(double i) called \n";
}