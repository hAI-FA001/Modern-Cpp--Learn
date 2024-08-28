#include <iostream>
#include <cstdio>
#include <memory>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Syntax: " << argv[0] << " <filename>\n";
        return 1;
    }

    // <type of object, type of deleter>
    // can't use make_unique and can't deduce types also
    // fopen, fclose work  on FILE*
    std::unique_ptr<FILE, decltype(&fclose)> fp{fopen(argv[1], "rb"), fclose};

    if (fp)
    {
        int c;
        // use .get() to get the raw ptr
        while ((c = fgetc(fp.get())) != EOF)
        {
            putchar(c);
        }
    }
}