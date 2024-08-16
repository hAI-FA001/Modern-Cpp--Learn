#include <iostream>

int main()
{
    // works for any type that supports std::begin() and std::end()
    // initializer statemtn; for-loop variable def : range expression
    // first part is optional
    // auto can have const, & (ref) or && (universal ref)
    for (int i = 0; auto c : "Something")
    {
        // the last zero-byte is output too -> unwanted
        // 2 ways to fix: check i < std::size(myArray)-1 OR check if c == 0
        if (c == 0)
            continue;
        std::cout << "i=" << i << ", c=" << c << ", ascii=" << static_cast<int>(c) << '\n';
    }

    std::cout << '\n';
    // now it outputs ascii
    for (int i = 0; int c : "Something")
    {
        std::cout << "i=" << i << ", c=" << c << ", ascii=" << static_cast<int>(c) << '\n';
    }

    // check other literals
    // std::cout << '\n';
    // u8"Something"," u"Something" and U"Something" don't compile
    // for (int i = 0; auto c : u"Something")
    // {
    //     std::cout << "i=" << i << ", c=" << c << ", ascii=" << static_cast<int>(c) << '\n';
    // }

    char arr[]{"Something"};
    for (auto &c : arr)
    {
        c = 'a';
    }
    std::cout << arr;
}