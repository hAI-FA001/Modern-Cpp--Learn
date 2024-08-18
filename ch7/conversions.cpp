#include <iostream>
#include <string>

// need this if want to use suffix "s" for string literals
using namespace std::literals;

void string_to_upper(std::string &s)
{
    for (int i = 0; i != s.size(); ++i)
    {
        // implementing string_to_upper w/ data() & ptr arithmetic
        *(s.data() + i) = toupper(*(s.data() + i));
    }

    // and using begin(), end()
    for (auto i = s.begin(); i != s.end(); ++i)
    {
        *i = toupper(*i);
    }
}

int main()
{
    auto n1 = 1.23;
    auto n2 = 45;

    auto s1 = std::to_string(n1);
    auto s2 = std::to_string(n2);

    std::cout << s1 << ' ' << s2 << '\n';
    std::cout << n1 << ' ' << n2 << '\n';

    // convention: sto"x", where x is i, l, ul, ll, ull, f, d, ld
    // str, ptr to size_t, base
    // base is only for integral ones
    // ptr stores index of first unused character
    n1 = std::stod(s1);
    n2 = std::stoi(s2, nullptr, 16);
    std::cout << n1 << ' ' << n2 << '\n';

    // evaluated at runtime normally,  unless use constexpr
    auto h1{"not const char*"s};
    // can concat empty string literal with any number of string/char literals
    auto alpha = ""s + "ABCDEF" + ' ' + "abcde" + 'f';
    std::cout << h1 << '\n';
    std::cout << alpha << '\n';

    // c_str() guarantees there is a null byte
    // data() may or may not have it (depends on contents of string & library implementation)
    auto underlying_char = h1.c_str(); // can't write
    auto using_data = h1.data();       // is writable

    std::cout << underlying_char << '\n';
    std::cout << using_data << '\n';

    string_to_upper(h1);
    std::cout << h1 << '\n';
    std::cout << underlying_char << '\n';
    std::cout << using_data << '\n';
}