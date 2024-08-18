#include <iostream>
#include <iomanip>
#include <string>

using namespace std::literals;
using std::string_view, std::cout;

// if this was string -> gives error if string view is passed
// if this was const char[] -> gives error due to array decay
void print_reversed(string_view sv)
{
    for (auto iter = std::crbegin(sv); iter != std::crend(sv); ++iter)
    {
        cout << *iter;
    }
    cout << '\n';
}

std::string reversed(std::string_view sv)
{
    std::string reversed_str{};
    for (auto iter = sv.crbegin(); iter != sv.crend(); ++iter)
    {
        if (*iter != '\0')
        {
            reversed_str.append(""s + *iter);
        }
    }
    return reversed_str;
}

int main()
{
    // string_view is more cheap to construct and pass around
    // has a subset of features of string
    // (no in-place modif or concatenation)
    // it doesn't "own" the referenced resource, so need to make sure it doesn't outlive

    // safe when used as function param (where const string& or const char* would be used)
    // sometimes safe as return type (instead of const char*)

    // used const char*
    string_view v1{"Something"};
    // used "s" suffix
    // string_view v2{"Some other thing"s};
    // used "sv" suffix
    auto v3{"Something else"sv};

    cout << v1 << '\n';
    // cout << (int)v2[0] << '\n';
    // cout << v2[0] << '\n';
    cout << v3.data() << '\n';

    // these all give errors
    // v3[0] = 'C';
    // v3.data()[0] = 'C';
    // auto v4 = v1 + v3;

    // all these are passed to function which expects string_view
    // these are implicitly convertible to string_view
    const char *s1 = "Elf";
    char s2[] = "Dwarf";
    std::string s3 = "Hobbit"s;
    string_view s4 = "Orc"sv;

    print_reversed(s1);
    print_reversed(s2);
    print_reversed(s3);
    print_reversed(s4); // gives error if parameter type was string
    print_reversed("Man");

    // need to store these in temp otherwise returned string will be destroyed after function call and they will become dangling references
    std::string temp_s1 = reversed(s1);
    s1 = temp_s1.c_str();

    // s3 is a string itself so no issue
    s3 = reversed(s3);

    std::string temp_s4 = reversed(s4);
    s4 = temp_s4;

    cout << "\nReversed: \n";
    cout << s1 << '\n';
    cout << reversed(s2) << '\n';
    cout << s3 << '\n';
    cout << s4 << '\n';
    cout << reversed("Man") << '\n';
}