#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter name: \n";

    std::string s;
    // no restriction on the size
    // cuz it takes both args as reference, so it can modify them
    // reads chars up to \n, the \n isn't stored
    std::getline(std::cin, s);
    std::cout << "You entered: \'" << s << "\'\n";
}