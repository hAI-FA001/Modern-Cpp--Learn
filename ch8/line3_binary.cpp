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

    std::ifstream infile{argv[1], std::ios_base::binary};
    std::string s;

    // binary files often contain NUL-byte
    while (!infile.eof())
    {
        std::getline(infile, s, '\0');
        std::cout << s;
    }
}