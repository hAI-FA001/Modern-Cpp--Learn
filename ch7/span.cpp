#include <iostream>
#include <algorithm>
#include <span>
#include <array>
#include <vector>
#include <string_view>

using namespace std;

// can optionally specify size as 2nd template arg
void print_ints(span<int> s)
{
    sort(begin(s), end(s));

    // won't output sep if it's first element
    for (auto sep{""sv}; auto &e : s)
    {
        cout << sep << e;
        // the trick of reassigning the separator gets around the limitation of std::copy()
        sep = ", "sv;
    }
    cout << '\n';
}

int main()
{
    // span is like string_view for containers
    // but span can modify elements too

    int c_array[] = {5, 1, 2, 3};
    vector vec = {2, 6, 4, 3};
    // 2nd template arg is optional, it's fixed at compile-time which allows it to be on the stack
    // not many cases where std::array is useful
    // as begin() & end() can be used with built-in arrays
    std::array std_array = {7, 6, 5};

    // like how string_view can accept multiple different types
    // span can accept these
    print_ints(c_array);
    print_ints(vec);
    print_ints(std_array);

    // this doesn't work
    // no conversion from std::initializer_list to std::span
    // this is 1 usecase for std::array
    // print_ints({9, 8, 7, 6});

    cout << "Printing in main(): \n";
    // these are also sorted (after sorting in the function)
    for (auto sep{""sv}; auto &e : vec)
    {
        cout << sep << e;
        // the trick of reassigning the separator gets around the limitation of std::copy()
        sep = ", "sv;
    }
    cout << '\n';

    for (auto sep{""sv}; auto &e : std_array)
    {
        cout << sep << e;
        // the trick of reassigning the separator gets around the limitation of std::copy()
        sep = ", "sv;
    }
    cout << '\n';

    for (auto sep{""sv}; auto &e : c_array)
    {
        cout << sep << e;
        // the trick of reassigning the separator gets around the limitation of std::copy()
        sep = ", "sv;
    }
    cout << '\n';
}