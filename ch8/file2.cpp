#include <iostream>
#include <fstream>

// put() and get() member funcs are not extensible
// e.g. difficulty if want to read double or string using only these
// stream extraction/insertion ops are overloaded to help with this

// serialize = save state of program, deserialize = load it back
// no guarantee the the system loading it is same as the system which saved it
// this leads to issues like endian-ness (big vs little) and address width (32 vs 64 bit)
// 1 way around this is to use plain text solely, which is what is done here
int main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Syntax: " << argv[0] << " <text file name>\n";
        return 1;
    }

    // this doesn't require the check against ifstream::traits_type::eof()
    std::ifstream infile{argv[1]};
    char c;
    // prevent skipping of whitespace e.g. tabs
    infile >> std::noskipws;
    while (!infile.eof()) // returns boolean
    {
        infile >> c;
        std::cout << c;
    }

    // using for-loop
    // for (; !infile.eof(); infile >> c, std::cout << c)
    // {
    // }
}