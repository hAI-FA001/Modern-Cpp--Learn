#include <chrono>
#include <iostream>
#include <string>
#include <string_view>
#include <print>

using namespace std;
using namespace std::chrono;

class Person
{
public:
    // className(params): member initializers { body }
    // std::chrono::year_month_day is passed by const ref as it may not fit in register if we pass by value
    // Person(const year_month_day &dob, string_view familyName, string_view firstName)
    // use uniform init to avoid narrowing conversions
    // older code may use paranthesis here
    // : dob{dob}, familyName{familyName}, firstName{firstName} {};

    // initializing in body
    Person(const year_month_day &dob, string_view familyName, string_view firstName = "default-firName")
        : dob{dob}
    {
        this->familyName = familyName;
        this->firstName = firstName;
    };

    // tell compiler to generate this function (which is a default ctor)
    // this won't be generated if we define our own ctor, so we tell compiler explicitly
    Person() = default;

    // these promist not to change member vars so their body is const
    // this must return the new string by value (not ref cuz it creates dangling ref)
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
    // historic convention: private members' names start with _ (not done here)
    const year_month_day dob;     // doesn't make sense for non-const dob
    string familyName, firstName; // must be string, not string_view to ensure they exist for lifetime of class
};

int main()
{
    Person genius{{1879y, March, 14d}, "Einstein", "Albert"};
    // std library overloads operator<< for std::chrono::year_month:day
    cout << genius.getName() << " was born " << genius.getDob() << '\n';

    genius.setFirstName("changed-firName");
    genius.setFamilyName("New-famName");
    cout << (genius.getFirstName() + ' ' + genius.getFamilyName()) << " was born " << genius.getDob() << '\n';

    println("{} was born {}", genius.getName(), genius.getDob());

    // strings init as empty strings
    // dob is "0001-00-00 is not a valid date"
    Person defaultPerson;
    cout << defaultPerson.getName() << " was born " << defaultPerson.getDob() << '\n';
}