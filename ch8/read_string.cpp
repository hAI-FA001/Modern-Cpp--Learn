#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter name: \n";
    std::string fname, sname;
    // space before/after input string is ignored
    // space in the middle makes cin only use text on left of the space
    // using std::noskipws only includes preceding whitespace
    // if we just press enter w/o any input, it'll keep "asking" until we enter a string
    std::cin >> fname >> sname;
    std::cout << "Hi, \'" << fname << ' ' << sname << "\', nice to meet you\n";
}