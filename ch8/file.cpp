#include <iostream>
#include <fstream>

// only safe for text files
int main(int argc, const char *argv[])
{
    // to avoid nullptr dereference if filename isn't provided
    if (argc != 2)
    {
        std::cerr << "Syntax: " << argv[0] << " <text file name>\n";
        return 1;
    }

    std::ifstream infile{argv[1]};

    int c = infile.get(); // this returns int, not char

    // eof is a special marker outside the valid range of char
    // valid range is 0-255 for unsigned and -128 to 127 for signed char
    while (c != std::ifstream::traits_type::eof())
    {
        std::cout << static_cast<char>(c);
        // this works too
        // std::cout.put(c);

        c = infile.get();
    }
    // infile is auto-closed when it goes out of scope

    // using for-loop
    // for (; c != std::ifstream::traits_type::eof(); c = infile.get())
    // {
    //     std::cout << static_cast<char>(c);
    // }
}