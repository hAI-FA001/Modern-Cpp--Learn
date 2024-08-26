#include <print>
#include <format>
#include <string>
#include <iostream>
#include <iterator>
#include <array>
#include <cmath>

int main()
{
    std::string world{"World"};

    std::print(std::cout, "Hello, {}!\n", world);
    // prints to C stdout, not cout
    // mixing stream and stdout can cause issues sometimes
    std::println("{1} or {0}", false, true);

    constexpr const char *fmt = "Approx of pi = {:.12g}";
    // 8-bit format string
    std::string s = std::format(fmt, asin(1.0) * 2);
    std::cout << s << "\n";

    constexpr const wchar_t *wfmt = L"Approx of pi = {:.12g}";
    // wide-character format string
    std::wstring ws = std::format(wfmt, asin(1.0) * 2);
    std::wcout << ws << L'\n';

    std::format_to(std::ostream_iterator<char>(std::cout), "Hello, {}!\n", world);

    std::wstring ww{L"World"};
    std::array<wchar_t, 9> wa;
    // 1st param is (writable) iterator pointing to start of array
    // 2nd param is max chars to write
    auto iter = std::format_to_n(wa.begin(), 8, L"Hello, {}!\n", ww);
    // return value has .out member which points to next char to write
    // set it to null so we can use .data() in cout
    *(iter.out) = L'\0';
    std::wcout << wa.data() << L'\n';
}
