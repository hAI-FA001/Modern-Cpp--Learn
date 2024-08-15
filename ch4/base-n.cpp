#include <iostream>

using namespace std;

void print_base_n(signed long long, unsigned name_need_not_match = 10); // default value
bool narrowing_cast_allowed_in_funcs(short a);
unsigned func1(unsigned a);

int main()
{
    long long n{};
    int b{};
    cout << "Enter a number: ";
    cin >> n;

    cout << "Enter base: ";
    cin >> b;

    print_base_n(n, b);
    cout << '\n';

    cout << "In default base: ";
    print_base_n(n); // substitues default value at compile-time
    cout << '\n';

    cout << "Literal 0x14: ";
    print_base_n(0x14);
    cout << '\n';

    cout << "Literal 017: ";
    print_base_n(017);
    cout << '\n';

    cout << "Literal 0b1010: ";
    print_base_n(0b1010);
    cout << '\n';

    cout << "-14: ";
    print_base_n(-14, 2);
    cout << '\n';

    // these work (no errors)
    cout << "Narrowing cast works in function arguments: " << narrowing_cast_allowed_in_funcs(2141.234) << '\n';
    cout << "Passing -ve: " << func1(-124) << '\n';
    cout << "Passing float: " << func1(1.214) << '\n';
}

void print_base_n(signed long long num, unsigned base)
{
    auto is_neg = num < 0;
    if (is_neg)
    {
        cout << "-";
        num = -num;
    }

    if (num >= base)
    {
        // in Modern C++, recursive funcs can be used w/o a prototype being seen
        print_base_n(num / base, base);
    }
    // indexes the string based on value of `num % base`
    cout << "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ+/"[num % base];
}

bool narrowing_cast_allowed_in_funcs(short a)
{
    return true;
}

unsigned func1(unsigned a)
{
    return a;
}