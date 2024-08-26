#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Syntax: " << argv[1] << " <text file name>\n";
        return 1;
    }

    std::ifstream infile{argv[1]};
    std::string s;
    // 3rd arg is the char which terminates the input (default is \n)
    // if file contains no NUL-byte, then this can read an entire file at once
    std::getline(infile, s, '\0'); // works w/ whitespace and control chars like \a
    std::cout << s;
}