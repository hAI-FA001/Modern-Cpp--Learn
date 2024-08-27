#include <iostream>

using namespace std;

struct Date
{
    int year{}, month{}, day{};

    // "spaceship" operator
    // defines all ordering and equality comparisons
    // ordering is performed member-wise, starting with first data member
    auto operator<=>(const Date &) const = default;
};

class Person
{
public:
    Person(const Date &dob, string_view familyName, string_view firstName)
        : dob{dob}, familyName{familyName}, firstName{firstName} {}

    string getName() const { return firstName + ' ' + familyName; }
    const auto &getDob() const { return dob; }

    // compares: family name, first name, then dob
    auto operator<=>(const Person &) const = default;

    // declare as friend
    friend ostream &operator<<(ostream &, const Person &);

private:
    string familyName, firstName;
    const Date dob;
};

// can access private and protected members cuz it's declared friend
ostream &operator<<(ostream &os, const Person &p)
{
    os << "Name: " << p.getName() << ", DOB: " << p.dob.year << '/' << p.dob.month << '/' << p.dob.day;
    return os;
}

int main()
{
    Person p1{{2000, 1, 1}, "Doe", "John"},
        p2{{2000, 1, 1}, "Aoe", "John"};

    cout << "p1: " << p1 << '\n';
    cout << "p2: " << p2 << '\n';

    if (p1 == p2)
    {
        cout << "Same person\n";
    }
    else
    {
        cout << "Different person\n";
    }

    cout << "p1 is ";
    if (p1.getDob() > p2.getDob())
    {
        cout << "younger than ";
    }
    else if (p1.getDob() < p2.getDob())
    {
        cout << "older than ";
    }
    else
    {
        cout << "the same age as ";
    }
    cout << "person2\n";
}