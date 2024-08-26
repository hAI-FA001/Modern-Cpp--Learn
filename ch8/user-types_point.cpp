#include <iostream>
#include <string>

struct Point
{
    int x{}, y{};
};

struct Pixel : Point
{
    std::string color{};
};

// custom stream output funcs are *always* global funcs
// 2nd arg (the object being output) must be passed as const-ref
// this func will need to access internals/private members, so this func should either be a friend func or rely on getters
std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << '(' << p.x << ',' << p.y << ')';
    // this allows chaining like cout << a << b << c
    return os;
}

std::ostream &operator<<(std::ostream &os, const Pixel &px)
{
    os << px.color << '@' << static_cast<const Point &>(px);

    return os;
}

int main()
{
    Point p{1, 2};
    Pixel px{5, 6, "red"};
    std::cout << p << '\n';
    std::cout << Point{3, 4} << '\n';
    std::cout << px << '\n';
}