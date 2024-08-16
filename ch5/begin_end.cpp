#include <iostream>

int main()
{
    // iterating w/o having a special sentinel value at the end of array
    // & w/o loop counter
    // this uses ptrs and compares addresses, this is how range-for operates
    double nums[] = {1.1, 2.5, 3};
    for (auto p = std::begin(nums); p != std::end(nums); ++p)
    {
        std::cout << "> " << *p << '\n';
    }

    // w/o begin() and end()
    std::cout << '\n';
    for (double *p = nums; p != nums + std::size(nums); ++p)
    {
        std::cout << "> " << *p << '\n';
    }

    // begin and end return addresses of first element and "one past the last"
    // variants:
    // cbeing and cend -> return const ptrs, use when referencing arrays that are const
    // contains variants that access a "reversed" array

    std::cout << '\n';
    // inferred as const double*
    for (auto p = std::cbegin(nums); p != std::cend(nums); ++p)
    {
        std::cout << "> " << *p << '\n';
    }

    // for reverse variants, don't decrement p (still ++p)
    // rbegin -> &a[N-1] (last value)
    // rend -> &a[-1] (1 before first value)
    std::cout << '\n';
    for (auto p = std::rbegin(nums); p != std::rend(nums); ++p)
    {
        // this works
        // *p = 1;
        std::cout << "> " << *p << '\n';
    }

    std::cout << '\n';
    for (auto p = std::crbegin(nums); p != std::crend(nums); ++p)
    {
        // error: you cannot assign to a variable that is const
        // *p = 1;
        std::cout << "> " << *p << '\n';
    }

    // printing last element, regardless of size
    std::cout << *std::rbegin(nums) << '\n';
}