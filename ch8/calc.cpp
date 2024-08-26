#include <iostream>
#include <fstream>
#include <cmath>

double calc(char op, double x, double y)
{
    double r{};
    switch (op)
    {
    case '+':
        r = x + y;
        break;
    case '-':
        r = x - y;
        break;
    case '*':
        r = x * y;
        break;
    case '/':
        if (y)
        {
            r = x / y;
        }
        else
        {
            std::cerr << "Error: Divide by Zero.\n";
        }
        break;
    case '^':
        r = pow(x, y);
        break;
    default:
        std::cerr << "Error: invalid op.\n";
    }

    return r;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Syntax: " << argv[0] << " <input file name> <output file name>\n";
        return 1;
    }

    std::ifstream infile{argv[1]};
    std::ofstream outfile{argv[2]};
    while (!infile.eof())
    {
        double x, y;
        char op;

        infile >> x >> op >> y;
        if (infile.fail() || infile.bad())
        {
            std::cerr << "Error in input.\n";
            break;
        }

        auto r = calc(op, x, y);
        outfile << x << ' ' << op << ' ' << y << " = " << r << '\n';
    }

    // if last line in file is blank, then it gives error (cuz it doesn't follow x op y)
    // all calcs can be put in same line with spaces instead of \n separating them
}