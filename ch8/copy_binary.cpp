#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Syntax: " << argv[0] << " <input file name> <output file name>\n";
        return 1;
    }

    std::ifstream infile{argv[1], std::ios_base::binary};
    std::ofstream outfile{argv[2], std::ios_base ::binary};

    std::string line;
    while (std::getline(infile, line))
    {
        outfile << line;
    }
}