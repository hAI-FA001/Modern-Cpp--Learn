
#include <memory>
#include <iostream>

class Simple
{
    std::string s;

public:
    Simple(std::string_view s) : s(s)
    {
        std::cout << "Simple(): " << s << '\n';
    }

    ~Simple()
    {
        std::cout << "~Simple(): " << s << '\n';
    }
};

void f(auto p) {};

int main()
{
    // with shared_ptr, object becomes reference-counted
    // it's dtor is called when ref count is 0

    std::cout << "main(): 1\n";

    std::shared_ptr<Simple> p1{new Simple("p1")};
    std::cout << "main(): 2\n";

    {
        std::cout << "main(): 3\n";
        auto p2 = std::make_shared<Simple>("p2");
        std::cout << "main(): 4\n";

        // Simple("p1") will be deleted
        // as ref count becomes 0 (no ptr points to it)
        // and scope of Simple(p2) is extended from sub-scope to main()'s scope
        p1 = p2;

        std::cout << "main(): 5\n";
    }
    std::cout << "main(): 6\n";
    // at this point, p1 and p2 are destroyed in same order as they were initialize
    // unlike in unique_ptr, where they are always destroyed in reverse order

    // shared_ptr can be passed by value
    // which means a copy of shared_ptr is made
    // and ownership is shared
    f(p1);
}