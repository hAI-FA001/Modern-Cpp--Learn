#include <iostream>

int main()
{
    auto l = [](auto a, auto b)
    {
        std::cout << "Calculating avg...\n";
        return (a + b) / 2.0;
    };

    std::cout << "Enter 2 integers: ";

    int x{}, y{};
    std::cin >> x >> y;

    auto avg = l(x, y);

    std::cout << "Avg is: " << avg << '\n';
}