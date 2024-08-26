// stream manips are put to stream object with << or >>
// we can set/unset stream flags with setf(), unsetf()
// stream params are set using member funcs like width(), precision()

// for performance-critical code, C++ streams and manips may not be practical/desirable
// providing localization to user's language and other settings can be difficult when using interleaved manips & messages
// print() and format() is recommended in these cases

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct Entry
{
    std::string product;
    size_t quantity;
    double unit_price;

    // static member
    // declared inline so it can have non-const value and need not to be defined outside struct
    // (struct and class defs can be found in headers and must not violate One Definition Rule)
    inline static double total{};
    inline static size_t lines{};
};

// factory function
Entry add_entry(const std::string &input) // pass as const string& to save overhead of copying string
{
    Entry e;
    std::istringstream iss{input};

    iss >> e.product >> e.quantity >> e.unit_price;
    // validation using iss
    if (iss.fail())
    {
        std::cerr << "Bad entry.\n";
        e.quantity = 0; // so total is unchanged
    }
    else
    {
        Entry::total += e.quantity * e.unit_price;
        Entry::lines++;
    }

    return e;
}

int main()
{
    std::vector<Entry> sales;

    std::cout << "Enter: PRODUCT QT PRICE (e.g. \'Apple 6 0.50\')\n";

    std::string s;
    std::getline(std::cin, s);

    while (!s.empty())
    {
        // used emplace_back() cuz the returned Entry is temporary and not a named variable
        // compiler should support Return Value Optimization and move semantics
        // i.e. a copy operation should not be needed
        sales.emplace_back(add_entry(s));

        std::cout << "Enter: PRODUCT QT PRICE (blank line to finish)\n";
        std::getline(std::cin, s);
    }

    std::cout << "======================\n";
    // saves all the flags of cout
    // save old value of p while setting it to 2
    // this is done cuz changing cout has a global effect
    // this is good practice, to restore to original values
    auto f = std::cout.flags();
    auto p = std::cout.precision(2);

    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    for (const auto &line : sales)
    {
        if (line.quantity)
        {
            std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
            // width() and setw() only modify the immediate output field
            std::cout.width(11);

            std::cout << line.product;

            std::cout.unsetf(std::ios_base::adjustfield);
            std::cout.width(3);

            std::cout << line.quantity;

            std::cout.width(6);
            std::cout << line.unit_price << '\n';
        }
    }

    std::cout << "======================\n";
    std::cout << "Total:";
    std::cout.width(14);
    std::cout << Entry::total << '\n';
    std::cout << "Total Lines Sold:";
    std::cout.width(14);
    std::cout << Entry::lines << '\n';

    std::cout.flags(f);
    std::cout.precision(p);

    // others
    std::vector<std::vector<std::string>> common_manips{
        {"s", "<<", "setbase(b)"},
        {"s", "<<", "setfill(c)"},
        {"s", "<<", "setprecision(p)"},
        {"s", "<<", "setw(n)"},
        {"s", "<<", "showbase"},
        {"s", "<<", "noshowbase"},
        {"s", "<<", "showpoint"},
        {"s", "<<", "noshowpoint"},
        {"s", "<<", "showpos"},
        {"s", "<<", "noshowpos"},
        {"s", "<<", "uppercase"},
        {"s", "<<", "nouppercase"},
        {"s", "<<", "unitbuf"},
        {"s", "<<", "nounitbuf"},
        {"s", "<<", "internal"},
        {"s", "<<", "left"},
        {"s", "<<", "right"},
        {"s", "<<", "dec"},
        {"s", "<<", "hex"},
        {"s", "<<", "oct"},
        {"s", "<<", "fixed"},
        {"s", "<<", "scientific"},
        {"s", "<<", "hexfloat"},
        {"s", "<<", "defaultfloat"},
        {"s", "<< or >>", "boolalpha"},
        {"s", "<< or >>", "noboolalpha"},
        {"s", ">>", "skipws"},
        {"s", ">>", "noskipws"},
    };
    std::cout << "\n\nCommon Manipulators:\n";
    for (const auto &manip : common_manips)
    {
        std::cout.width(2);
        std::cout << std::left << manip[0];

        std::cout.width(10);
        std::cout << std::left << manip[1];

        std::cout.width(30);
        std::cout << std::left << manip[2] << '\n';
    }
}