// advantages over files/stream objects directly
//   performance (when caching lines of output/input in mem when writing to/reading from disk or network socket)
//   flags or manipulators don't affect global cin/cout/cerr/ifstream/ofstream states
//   for output, bugger grows dynamically
//   for input, backtracking/error recovery can be quicker/easier cuz they set fail-bit or bad-it

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <string>

int main()
{
    std::ostringstream oss{};
    oss.precision(3);
    oss << std::fixed << 1 << '+' << 3.2 << " = " << 1 + 3.2;
    // chained method call avoids defining an intermediate string variable
    puts(oss.str().c_str());

    std::string s;
    double a, b;
    char op;
    for (;;)
    {
        std::cout << "Enter a calc (x op y): ";
        std::getline(std::cin, s);
        if (s.empty())
        {
            break;
        }

        std::istringstream iss{s};
        iss >> a >> op >> b;
        // entering a letter instead of number causes fail() to return true
        // extra input at the end causes eof() to return false
        if (iss.fail() || !iss.eof())
        {
            std::cout << "Bad input\n";
        }
        else
        {
            std::cout << "Input read successfully\n";
        }
    }
}