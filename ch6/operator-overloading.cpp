#include <iostream>

struct Point
{
    int x{}, y{};

    Point &operator+=(const Point &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this; // one of the rare uses of `this`
    }
};

// `operator` is defined as global/free/non-member funcs as they don't access private member vars

// return type is const to prevent accidental operations
const Point operator+(const Point &lhs, const Point &rhs)
{
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

const Point operator-(const Point &lhs, const Point &rhs)
{
    return {lhs.x - rhs.x, lhs.y - rhs.y};
}

// using encapsulation ver
struct Point2
{
    void setX(int nx)
    {
        x = nx;
    }
    void setY(int ny)
    {
        y = ny;
    }
    auto getXY() const // need const if want to use it with const Point&
    {
        return std::pair(x, y);
    }

    Point2 &operator+=(const Point2 &rhs)
    {
        setX(x + rhs.x);
        setY(y + rhs.y);
    }

private:
    int x{}, y{};
};

const Point2 operator+(const Point2 &lhs, const Point2 &rhs)
{
    // w/o using +=
    Point2 result{lhs};
    const auto [x, y] = result.getXY();
    const auto [x_rhs, y_rhs] = rhs.getXY();
    result.setX(x + x_rhs);
    result.setY(y + y_rhs);
    return result;
}

int main()
{
    Point p1{100, 200}, p2{200, -50}, p3, p4;

    p3 = p1 + p2;
    p4 = p1 - p2;
    p1 += p1;

    std::cout << "p3 = " << p3.x << ", " << p3.y << '\n';
    std::cout << "p4 = " << p4.x << ", " << p4.y << '\n';
    std::cout << "p1 = " << p1.x << ", " << p1.y << '\n';

    Point2 p1_2, p2_2, p3_2;

    p1_2.setX(100);
    p1_2.setY(200);
    p2_2.setX(200);
    p2_2.setY(-50);

    p3_2 = p1_2 + p2_2;

    const auto [x, y] = p3_2.getXY();
    std::cout << "p3_2 = " << x << ", " << y << '\n';
}