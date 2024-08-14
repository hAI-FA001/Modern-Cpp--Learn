// batch programs: take all input at beginning
// other is interactive programs

#include <iostream>
#include <print>
#include <cmath>

using namespace std;

int main()
{
    int age{};
    cout << "Enter age: ";
    cin >> age; // non-numeric becomes 0 -> Ctrl+Z becomes 0
    cout << "You entered " << age << "\n";

    if (age)
    {
        cout << "Non-zero value.\n";
    }
    else
    {
        cout << "Zero value\n";
    }

    cout << "\n\n";

    double decimal{};
    cout << "Enter decimal: ";
    cin >> decimal;

    if (decimal == 0.0)
    {
        cout << "Zero\n";
    }
    else
    {
        cout << "NonZero\n";
    }

    int n{};
    cout << "Enter value: ";
    cin >> n;

    // using "!n" works for other objects like ofstream too -> for consistent syntax
    if (!n)
    {
        cout << "Zero\n";
    }
    else if (n < 0)
    {
        cout << "Negative\n";
    }
    else
    {
        cout << "Positive\n";
    }

    cout << "Enter guess: ";
    cin >> age;

    if (6 <= age and age <= 11)
    {
        cout << "Good guess\n";
    }
    else
    {
        cout << "Not good guess\n";
    }

    if (age < 6 or age > 11)
    {
        cout << "Not good guess\n";
    }
    else
    {
        cout << "Good guess\n";
    }

    return 0;
}