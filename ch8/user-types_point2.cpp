#include <iostream>

struct Point
{
    int x{}, y{};
};

std::istream &operator>>(std::istream &is, Point &p)
{
    char a{}, b{}, c{};
    int px, py;
    is >> a >> px >> b >> py >> c;

    if (is.good())
    {
        if (a == '(' and b == ',' and c == ')')
        {
            p.x = px;
            p.y = py;
        }
        else
        {
            // need to take care to set this for invalid inputs
            is.setstate(std::ios_base::failbit);
        }
    }

    return is;
}

int main()
{
    std::cout << "Enter a point in the form \'(2,-3)\'\n";

    Point p;
    while (!std::cin.eof())
    {
        std::cin >> p;
        // note: this user feedback is in the *calling* func, not the overloaded operator>>
        if (std::cin.good())
        {
            std::cout << "Point read successfully\n";
        }
        else
        {
            std::cout << "Error in input\n";
            // also need to take care to reset any stream flags and params
            std::cin.clear();
        }
    }
}
