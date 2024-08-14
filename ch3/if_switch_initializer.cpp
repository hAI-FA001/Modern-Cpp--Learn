#include <iostream>

using namespace std;

int main()
{
    int n{};

    cout << "Enter a value: ";
    cin >> n;
    cout << "Value is " << (n ? "Non" : "") << "Zero\n";
    cout << "Value is " << (n > 0 ? "Positive" : (n < 0 ? "Negative" : "Zero")) << '\n';

    // if initializer
    if (auto m = n % 10; m < 5)
    {
        cout << "Less than 5\n";
    }
    else
    {
        cout << "Greater than 5\n";
    }

    // switch initializer
    switch (auto m = n % 10; m)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        cout << "Less than five\n";
        break;
    default:
        cout << "Greater than five\n";
        break;
    }
}