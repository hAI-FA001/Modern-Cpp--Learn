#include <string>

struct Date
{
    int year{}, month{}, day{};
};

class Person
{
    Date dob;
    std::string familyName, firstName;
};

struct PersonS
{
    Date dob;
    std::string familyName, firstName;
};

int main()
{
    Person a_person{};
    // below doesn't compile cuz members are private by default
    // Person genius{{1879, 3, 14}, "Einstein", "Albert"};
    // Person genius2{};
    // genius2.dob = {1, 1, 1};
    // genius2.firstName = "changed name";
    // genius2.familyName = "changed name";

    // changing to struct works
    PersonS genius{{1879, 3, 14}, "Einstein", "Albert"};
}