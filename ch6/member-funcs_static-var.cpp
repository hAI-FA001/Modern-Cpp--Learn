#include <iostream>

// prev struct point has "zero encapsulation"
// we want to separate implementation from interface
struct Point
{
    // these getters/setters are defined inline (written in full b/w the braces)
    // compiler will inline them so no function call overhead
    void setX(int nx)
    {
        // don't need this->x as member vars are in scope for all member funcs
        super_x = within(nx, 0, screenX); // could use std::clamp in <algorithm>
    }

    void setY(int ny)
    {
        y = within(ny, 0, screenY);
    }

    void setXY(int nx, int ny)
    {
        setX(nx);
        setY(ny);
    }

    void moveByX(int dx)
    {
        super_x += dx;
    }

    void moveByY(int dy)
    {
        y += dy;
    }

    // const means the member function doesn't modify the member vars
    auto getXY() const
    {
        // error says it's accessed through a const object
        // x = 1;
        return std::tuple{super_x + 0, y * 1}; // can return a modified x/y
    }

    static int within(int val, int min, int max)
    {
        if (val < min)
        {
            return min;
        }
        else if (val > max)
        {
            return max;
        }
        else
        {
            return val;
        }
    }

    // these are per-class as opposed to per-object
    // these aren't private but it's fine cuz they're read-only (using const)
    static const int screenX{639}, screenY{479};

private:
    // another advantage of encaps: renaming vars only affects this class
    // (don't need to change anything in main)
    // => separated implementation from interface
    int super_x{}, y{};
};

int main()
{
    // can't do p{1, 2} as x & y are private
    // this is default init
    Point p;
    int user_x{}, user_y{};

    // access static vars using ::, not dot
    std::cout << "Screen is " << Point::screenX + 1 << " by " << Point::screenY + 1 << '\n';
    std::cout << "Enter x and y: ";
    std::cin >> user_x >> user_y;

    p.setXY(user_x, user_y);

    // aggregate init -> works on both pair and tuple -> general
    auto [px, py] = p.getXY();
    std::cout << "px=" << px << ", py=" << py << '\n';
}