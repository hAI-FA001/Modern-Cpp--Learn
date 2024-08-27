#include <string>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

class Person
{
public:
    // special member functions
    // which ones to use? try declaring them =delete first, then move to =default to remove compiler errors as needed

    // default ctor
    // e.g. Person p{}, p(), or just p;
    Person() = default;
    // copy ctor
    // e.g. Person p{p1}
    Person(const Person &) = default;
    // copy assignment operator
    // e.g. Person p; p = p1;
    Person &operator=(const Person &) = default;
    // move ctor
    // e.g.Person p { std::move(p1) }
    Person(Person &&) = default;
    // move assignment operator
    // e.g. Person p; p = std::move(p1);
    Person &operator=(Person &&) = default;
    // dtor
    // when object goes out of scope
    ~Person() = default;
    // };

    // copied below from person1.cpp
    // class Person
    // {
    // public:
    Person(const year_month_day &dob, string_view familyName, string_view firstName = "default-firName")
        : dob{dob}
    {
        this->familyName = familyName;
        this->firstName = firstName;
    };

    string getName() const { return firstName + ' ' + familyName; }
    const year_month_day &getDob() const { return dob; }

    const string &getFamilyName() const { return familyName; }
    const string &getFirstName() const { return firstName; }

    void setFamilyName(string paramfamilyName)
    {
        this->familyName = paramfamilyName;
    }

    void setFirstName(string paramfirstName)
    {
        this->firstName = paramfirstName;
    }

private:
    // needs to be non-const
    // otherwise, gives errors in assignment operators
    year_month_day dob;
    string familyName, firstName;
};

void print_person(const Person &p)
{
    cout << p.getName() << " was born " << p.getDob() << '\n';
}

int main()
{
    // below line doesn't compile if dtor is deleted
    Person genius{{1879y, March, 14d}, "Einstein", "Albert"};
    print_person(genius);

    // needs default ctor
    // if p2 is init using () instead of {}, it gives warnings and errors
    Person p1{}, p2{}, p3;

    Person p4{p1}, p5{p2};

    Person p6;
    p6 = p1;

    Person p7{std::move(p2)};

    Person p8;
    p8 = std::move(p3);

    for (const auto &p : {p1, p2, p3, p4, p5, p6, p7, p8})
    {
        print_person(p);
    }
}