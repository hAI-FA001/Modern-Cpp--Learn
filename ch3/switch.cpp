#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int r{}, x{}, y{};
    char op{};
    cout << "Enter a calculation e.g. 1 + 1: ";
    cin >> x >> op >> y;
    cout << "Entered " << x << op << y << '\n';

    // cout << (int)'+' << ' '
    //      << (int)'-' << ' '
    //      << (int)'*' << ' '
    //      << (int)'/' << ' '
    //      << (int)'%' << ' '
    //      << (int)'^' << '\n';

    switch (op) // must evalute to integral type (from char to long long w/ or w/o unsigned)
    {
    // case '+':
    case 43:
        r = x + y;
        break;
    // case '-':
    case 45:
        r = x - y;
        break;
    // case '*':
    case 42:
        r = x * y;
        break;
    // case '/':
    case 47:
        if (y)
        {
            r = x / y;
        }
        else
        {
            cerr << "ERROR: Division by Zero\n";
        }
        break;
    // case '^':
    case 94:
        r = static_cast<int>(pow(x, y));
        break;
    // case '%':
    case 37:
        if (y)
        {
            r = x % y;
        }
        else
        {
            cerr << "ERROR: Division by Zero\n";
        }
        break;

    default:
        cerr << "ERROR: Invalid Op (Must be +, -, *, /, ^ or %)\n";
        break;
    }
    cout << "Result: " << r << '\n';

    int n{};
    cout << "Enter number b/w 0 and 3: ";
    cin >> n;

    switch (n)
    {
    case 0:
        cout << "n < 1\n";
        // c++ attributes
        [[fallthrough]]; // suppresses warnings
    case 1:
        cout << "n < 2\n";
        [[fallthrough]];
    case 2:
        cout << "n < 3\n";
        break;
    case 3:
        cout << "n == 3\n";
        break;
    default:
        cout << "Out of range\n";
        break;
    }
}