// functors: objects of classes/structs that can masquerade as functions
// we can do this by overloading function call operator()

// useful: functors can have state, it's preserved b/w object-as-function calls

#include <iostream>

int main()
{
    struct Average
    {
        int operator()(int a, int b)
        {
            std::cout << "Calculating avg...\n";
            return (a + b) / 2;
        }

        double operator()(double a, double b)
        {
            std::cout << "Calculating double avg...\n";
            return (a + b) / 2;
        }
    };

    Average a;
    std::cout << "Enter 2 ints: ";

    int x{}, y{};
    std::cin >> x >> y;

    auto avg = a(x, y);
    std::cout << "Avg is: " << avg << '\n';
}