#include <iostream>

int main()
{
    std::cout << "Enter name: \n";

    char line[5];
    // this can handle blank lines (when we just press enter, no text)
    std::cin.getline(line, std::size(line));

    std::cout << "You entered: \'" << line << "\'\n";
    // this is 1 if we enter a longer string than the given size
    // fail bit is set, so further calls return empty string
    std::cout << "cin.fail(): " << std::cin.fail() << '\n';
    // this can be used to ignore 1 or more characters
    // if we enter a string less than size, then this waits for a character to be entered
    std::cin.ignore();
    std::cout << "After ignore(): " << std::cin.fail() << '\n';
    // unsets the fail bit
    std::cin.clear();
    std::cout << "After clear(): " << std::cin.fail() << '\n';
}