// smart ptrs:
// bind heap objs to scoped lifetimes
// all paths/subscopes are covered (incl exception)

#include <iostream>
#include <string>
#include <string_view>
#include <memory>

class Simple
{
    std::string str;

public:
    Simple(std::string_view s) : str{s}
    {
        std::cout << "Simple(): " << str << '\n';
    }
    ~Simple()
    {
        std::cout << "~Simple(): " << str << '\n';
    }
};

int main()
{
    // simplest smart ptr is std::unique_ptr
    // gives exclusive ownership

    // init w/ ptr to heap obj
    // ptr type <Simple> is needed in case it points to a different base class type
    // as with Stack objs, will be destroyed in reverse order in which they're created
    std::unique_ptr<Simple> p1{new Simple("p1")};
    Simple *p2 = new Simple("p2");

    try
    {
        // another way to make unique ptr
        // is preferred, due to exception safety
        auto p3 = std::make_unique<Simple>("p3");
        delete p2;
        p2 = nullptr;
        throw std::exception{"Threw an exception to check ~Simple()"};
    }
    catch (...)
    {
    }
}