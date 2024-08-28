#include <iostream>
#include <memory>
#include <string>

class Test
{
    std::string s;

public:
    Test(std::string_view s) : s(s)
    {
        std::cout << "Test() of " << s << '\n';
    };
    ~Test()
    {
        std::cout << "~Test() of " << s << '\n';
    }

    const std::string &getS() const { return s; }
};

void f(std::unique_ptr<Test> p)
{
    std::cout << "Inside f(): " << p->getS() << '\n';
};

auto factory()
{
    return std::make_unique<Test>("T3");
}

int main()
{
    auto p = std::make_unique<Test>("T1");

    // change object owned by ptr
    p.reset(new Test{"T2"});

    // unique_ptr can't be copied cuz it makes no semantic sense:
    //   deep copy can't be initiated by ptr to object
    //   shallow copy means either shared ownership or dangling ptrs
    // f(p);

    // w/ std::move(), it works
    f(std::move(p));
    // release and destroy early
    p.reset(nullptr);

    // unique_ptrs are very useful for factory funcs
    auto p3 = factory();
}