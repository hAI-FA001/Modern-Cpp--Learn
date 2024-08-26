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
    char data[100];

    // using stream member funcs: read(), gcount(), write()

    infile.read(data, 100);
    // gcount() is set after a read()
    // it returns number of bytes read
    for (auto gc = infile.gcount(); gc != 0; gc = infile.gcount())
    {
        std::cout.write(data, gc);
        infile.read(data, 100);
    }
}