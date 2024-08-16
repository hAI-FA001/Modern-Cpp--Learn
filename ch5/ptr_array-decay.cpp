#include <iostream>

int main()
{
    int i{-1}, j{};
    // * is optional when using auto, deduced as int*
    // ptr is 64b on most machines
    auto p = &i;

    std::cout << "p=" << p << ",*p=" << *p << ", i=" << i << '\n';

    std::cout << "Enter number: ";
    std::cin >> j;

    *p = j;
    std::cout << "p=" << p << ",*p=" << *p << ", i=" << i << '\n';

    // defining ptr on same line & not using 3rd var "j"
    int a{-1}, *ap = &a;

    std::cout << "ap=" << ap << ",*ap=" << *ap << ", a=" << a << '\n';

    std::cout << "Enter number: ";
    std::cin >> *ap;

    std::cout << "ap=" << ap << ",*ap=" << *ap << ", a=" << a << '\n';

    char str[20];
    std::cout << "Enter a string up to " << std::size(str) - 1 << " characters: ";
    // reads input into the memory location up to a max count (incl zero terminator)
    // \n is not stored, extra input is saved for future calls to cin

    // moved this before cin: still compiles/works as we're assigning addresses
    const char *sp = str; // we don't want to modify the array

    // to consume the \n entered by previous input
    std::cin.getline(str, std::size(str));
    std::cin.getline(str, std::size(str));
    // array decay: size attribute is lost when we assign array to ptr (also when calling function using array as argument to either array or ptr parameters)
    while (*sp)
    {
        // *sp++ -> uses sp in expression *sp then increments sp
        std::cout << "- " << *sp++ << '\n';
    }
}