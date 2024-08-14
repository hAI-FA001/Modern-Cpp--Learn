#include <windows.h>
#include <print>

using namespace std;

int main()
{
    // some literals
    signed char l_a = '\x20';
    unsigned char l_b = '\xa0';
    int l_c = 0x7fff;
    unsigned l_d = 0xffffU;
    long l_e = 0x7fffffffL;
    unsigned long l_f = 0xbbbfUL;
    long long l_g = 1000ULL;
    SSIZE_T l_h = 0; // 0Z;  // these literals don't seem to work on Windows, same for ssize_t (need to use SSIZE_T in windows.h)
    size_t l_i = 0;  // 0uz;
    float l_j = 0.f;
    long double l_k = 100000000.5L;

    println("c={}, uc={}, i={}, ui={}, l={}, ul={}, ll={}, ss={}, s={}, f={}, ld={}", l_a, l_b, l_c, l_d, l_e, l_f, l_g, l_h, l_i, l_j, l_k);

    // auto keyword
    auto p{1.0}; // inferred as double

    std::byte b{254}; // can be 0 to 255, only bit operations are allowed
    // auto z = b + (std::byte)1;
    auto q = b & (std::byte)1;
    auto r = to_integer<int>(b);

    // can't print byte either
    println("q={}, r={}", to_integer<int>(q), r);

    // literal prefixes and suffixes
    auto one_mil = 1'000'000;     // can group using apostrophe
    auto binary = 0b1010;         // or 0B1010
    auto hex = 0x12;              // or 0X12
    auto hex_float = 0x3fp12;     // hex float, "p" or "P" separates radix
    auto expo_float = 12e3;       // e or E separates exponent
    auto string_literal = "abc"s; // s is also used for seconds if you use <chrono>, s is string if use <string>

    println("{} {} {} {} {} {}", one_mil, binary, hex, hex_float, expo_float, string_literal);
}