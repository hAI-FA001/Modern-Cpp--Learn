#include <iostream>
#include <string>
#include <vector>

// a/c to type theory:
// polymorphism "is a concept wherein a name may denote instances
// of many different classes as long as they are related by
// some common super class"
// in practice, this means obj of derived class can be manipulated through ptr or ref of base class
// is imp in order to classify C++ as object-*oriented* as opposed to object-*based*
// member func selection is resolved at run-time
// these are called "virtual functions"

// an abstract base class
class Virtual
{
public:
    // f() can optionally be redefined in derived class
    virtual void f();

    // g() is a "pure-virtual function" of an abstract base class
    // it's *never* defined in this class
    // *must* be defined in derived class
    // this class can't be instantiated now
    virtual void g() = 0;

    // h() redefines a previous definition
    // sign must match exactly, incl const and noexcept qualifiers
    // this itself can be redefined in derived classes
    // virtual void h() override;

    // same as h() but can't be redefined in subsequent derived classes
    // virtual void k() override final;
};

class Shape
{
public:
    struct Point;

    Shape(int sides) : sides{sides} {};
    Shape(int sides, Point center) : sides{sides}, center{center} {};

    virtual void draw(std::ostream &os) const = 0;
    virtual std::string getSides() const { return std::to_string(sides); }

    virtual double getArea() const = 0;

    void moveBy(int dx, int dy)
    {
        center.x += dx;
        center.y += dy;
    }
    const Point &getCenter() const { return center; }

    virtual ~Shape()
    {
        std::cerr << "~Shape()\n";
    }

    // local struct
    struct Point
    {
        int x{}, y{};
    };

private:
    int sides;
    Point center;
};

// to reduce code duplication
std::ostream &operator<<(std::ostream &os, const Shape::Point &pt)
{
    return os << '(' << pt.x << ',' << pt.y << ')';
}

// no class can derive from Triangle as it is "final"
class Triangle final : public Shape
{
public:
    Triangle(int side) : Shape{3}, side{side} {}
    Triangle(int x, int y, int side) : Shape{3, {x, y}}, side{side} {}

    virtual void draw(std::ostream &os) const override
    {
        // first few chars output:
        //  /\
        // /__\

        os << " /\\\n/__\\\nSide: " << side << '\n';
    }

    virtual double getArea() const override
    {
        return sqrt(3) * pow(side, 2) / 4;
    }

    virtual ~Triangle()
    {
        std::cerr << "~Triangle()\n";
    }

private:
    int side;
};

class Circle : public Shape
{
public:
    Circle(int radius) : Shape{0}, radius(radius) {}
    Circle(int x, int y, int radius) : Shape{0, {x, y}}, radius{radius} {}

    virtual void draw(std::ostream &os) const override final
    {
        os << " _\n(_)\nRadius: " << radius << '\n';
    }

    virtual double getArea() const override final
    {
        return pow(radius, 2) * 22 / 7;
    }

    virtual ~Circle()
    {
        std::cerr << "~Circle()\n";
    }

    // removing "const" gives error
    // says it doesn't override a func
    // which means sign needs to match *exactly*
    // also means this function must never modify member vars, even in derived classes
    virtual std::string getSides() const override final { return "infinite"; }

private:
    int radius;
};

class Rectangle : public Shape
{
public:
    Rectangle(int side_x, int side_y) : Shape{4}, side_x{side_x}, side_y{side_y} {}
    Rectangle(int x, int y, int side_x, int side_y) : Shape{4, {x, y}}, side_x{side_x}, side_y{side_y} {}

    virtual void draw(std::ostream &os) const override
    {
        os << " ___\n|___|\nSize: " << side_x << 'x' << side_y << '\n';
    }

    virtual double getArea() const override
    {
        return side_x * side_y;
    }

    virtual ~Rectangle()
    {
        std::cerr << "~Rectangle()\n";
    }

protected:
    int side_x, side_y;
};

class Square final : public Rectangle
{
public:
    // Rectangle's ctors call Shape's ctors
    // so no need to call them directly here
    Square(int side) : Rectangle{side, side} {}
    Square(int x, int y, int side) : Rectangle(x, y, side, side) {}

    virtual void draw(std::ostream &os) const override final
    {
        // accesses protected members
        os << " _\n|_|\nSide: " << side_x << '\n';
    }

    virtual ~Square()
    {
        std::cerr << "~Square()\n";
    }
};

std::ostream &operator<<(std::ostream &os, const Shape &s)
{
    // we can access draw() and getSides()
    // as they're public in *all* base and derived classes
    s.draw(std::cout);
    std::cout << "At: " << s.getCenter() << '\n';
    std::cout << "Sides: " << s.getSides() << '\n';
    std::cout << "Area: " << s.getArea() << '\n';

    return os;
}

// error: final class can't be used as a base class
// class Empty : Square
// {
// };

class CircleDerived : Circle
{
    // can't overload final function
    // virtual void draw(std::ostream &os) const override final
    // {
    //     os << "Overloaded Draw():\n _\n(_)\nRadius: " << radius << '\n';
    // }
};

int main()
{
    // raw ptrs
    // Shape is an abstract type, so we can't do "vector<Shape>" (not ptr)
    // cuz these would need to be able to be default-init for the container to be created
    std::vector<Shape *> shapes;
    shapes.push_back(new Circle{10});
    shapes.push_back(new Triangle{10, 20, 15});
    shapes.push_back(new Rectangle{10, 5});
    shapes.push_back(new Square{25, 100, 50});

    shapes[0]->moveBy(20, 50);

    for (auto &s : shapes)
    {
        std::cout << *s;
        delete s;
        // prevent dangling ptr
        s = nullptr;
    }

    // error: Shape is abstract class
    // Shape a{1};
}