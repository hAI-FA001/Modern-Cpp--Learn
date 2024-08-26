#include <print>
#include <string>

using namespace std;

int main()
{
    string s{"Formatted"};
    auto d{10.0 / 3.0};
    auto i{20000};

    // pad s to 20 chars
    // {2:8} -> use 3rd argument with 8 width
    // .11 -> use 11 decimal places/precision
    // format string and its specifiers are evaluated at compile-time (so format string must be string literal, not string)
    println("{0:20}:{2:8}, {1:12.11}", s, d, i);

    println("{:a>10}", s);
    println("{:+#}", d);
    println("{:04.2}", d);
    // println("{L}", i);
    println("{:x}", i);
}