#include <iostream>

int main()
{
    // using uniform init syntax to assign array contents
    // can ONLY be used when we define the array
    // AKA aggregate init using braced initalizer
    int nums[] = {1, 2, 3};
    // = sign is optional
    int numm2[]{1, 2, 3};

    char name[] = "C++";
    auto n = "test"; // const char*
    // n[0] = 'b';  // will give error

    // this works, but has overhead
    // the string literal is stored in read-only part of the executable binary
    // and copied into newly-allocated array at run-time
    name[0] = 'c';

    // name implicitly has zero byte
    std::cout << name << '\n';

    std::cout << "No. of elements: " << std::size(nums) << '\n';
    // std::cout << "Size in bytes: " << std::size_bytes(nums) << '\n';
    std::cout << "Using sizeof(): " << sizeof(nums) << '\n';
}