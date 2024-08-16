#include <iostream>
#include <string_view>

struct Point
{
    int x{}, y{};
};

enum class Color
{
    none,
    red,
    green,
    blue
};

// composition, other option is inheritance
// "Pixel has-a point"
struct Pixel
{
    // point will be default init as its members are default init
    Point pt;
    Color col{};
};

// using inheritance
// "Pixel is-a point"
struct Pixel2 : Point
{
    Color col{};
};

// can't do this as Color is not a class or struct (it's an enum)
// struct PixelBoth : Point, Color
// {
// };

// string or const char* would work too
// the data referred by string_view is guaranteed to outlive its function's scope as they are read-only literals
// (no copy is ever made)
std::string_view get_color(Color c)
{
    switch (c)
    {
    case Color::red:
        return "red";
    case Color::green:
        return "green";
    case Color::blue:
        return "blue";
    default:
        return "<no color>";
    }
}

std::string get_px_info(Pixel p)
{
    std::string_view col = get_color(p.col);
    return std::string("p has color ").append(col);
}

std::string get_px_info(Pixel2 p)
{
    std::string_view col = get_color(p.col);
    return std::string("p has color ").append(col);
}

int main()
{
    Pixel p1;
    Pixel p2{{-1, 2}, Color::blue};

    std::cout << get_px_info(p1) << '\n';
    std::cout << get_px_info(p2) << '\n';
    std::cout << get_px_info(Pixel{{1, 2}, Color::green}) << '\n';

    Pixel2 p1_inh;
    Pixel2 p2_inh{{-1, 2}, Color::blue};
    std::cout << get_px_info(p1_inh) << '\n';
    std::cout << get_px_info(p2_inh) << '\n';
    std::cout << get_px_info(Pixel2{{1, 2}, Color::green}) << '\n';

    // need to access pt
    std::cout << "p1 coords: " << p1.pt.x << ", " << p1.pt.y << '\n';
    // can directly access x and y
    std::cout << "p1_inh coords: " << p1_inh.x << ", " << p1_inh.y << '\n';
}