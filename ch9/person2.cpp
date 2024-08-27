#include <chrono>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;
using namespace std::chrono;

class Person
{
public:
    // other members are defaulted (strings become empty, bool becomes false)
    Person(year_month_day dob) : dob{dob} {};

    Person(year_month_day dob, string_view familyName, string_view firstName, bool familyNameFirst = false)
        : dob{dob}, familyName{familyName}, firstName{firstName}, familyNameFirst{familyNameFirst} {};

    // destructor
    // base classes need a virtual dtor
    // so any heap objects of type Student/Employee assigned to Person*
    // can invoke correct dtor of derived class
    // avoids memory leaks
    virtual ~Person() {};

    void setFamilyName(string_view familyName)
    {
        familyName = familyName;
    }
    void setFirstName(string_view firstName)
    {
        firstName = firstName;
    }
    void setFamilyNameFirst(bool familyNameFirst)
    {
        familyNameFirst = familyNameFirst;
    }

    string getName()
    {
        if (familyName.empty() || firstName.empty())
        {
            return familyName + firstName;
        }
        else if (familyNameFirst)
        {
            return familyName + ' ' + firstName;
        }
        else
        {
            return firstName + ' ' + familyName;
        }
    }

protected:
    const year_month_day dob;

private:
    string familyName, firstName;
    bool familyNameFirst{};
};

// derived with "public" keyword
// omitting "public" causes the public membors of Person to not be visible
// cuz classes default to private inheritance
class Student : public Person
{
public:
    // defined later
    // "forward declared"
    enum class Schooling;

    // vector<string> is needed to be passed by value
    // it's passed by const ref here so only 1 copy is made
    Student(const Person &person, const vector<string> &attended_classes = {}, Schooling school_type = Schooling::preschool)
        : Person{person}, school_type{school_type}, attended_classes{attended_classes} {}

    const year_month_day &getDob() const { return dob; }
    const vector<string> &getAttendedClasses() const { return attended_classes; }

    enum class Schooling
    {
        preschool,
        elementary,
        juniorhigh,
        highschool,
        college,
        homeschool,
        other
    };

private:
    Schooling school_type;
    vector<string> attended_classes;
};

class Employee : public Person
{
public:
    Employee(const Person &person, int employee_id, int salary = 0)
        : Person{person}, employee_id{employee_id}, salary{salary} {}

    bool isBirthdayToday(year_month_day today) const { return dob.month() == today.month() and dob.day() == today.day(); }
    void setSalary(int salary) { salary = salary; }

    auto getDetails() const { return pair{employee_id, salary}; }

private:
    const int employee_id;
    int salary;
};

int main()
{
    Person p{{1879y, March, 14d}, "Einstein", "Albert"};
    Student s{p, {"math", "physics", "philosophy"}, Student::Schooling::other};
    Employee e{p, 1001, 15000};

    cout << "Full name: " << s.getName() << '\n';
    cout << "Schooling classes: ";
    for (const auto &c : s.getAttendedClasses())
    {
        cout << c << ' ';
    }
    cout << '\n';

    auto [id, salary] = e.getDetails();
    cout << "ID: " << id << ", Salary: $" << salary << '\n';
    year_month_day next_bday{2023y, March, 14d};
    if (e.isBirthdayToday(next_bday))
    {
        cout << "Happy Birthday\n";
    }
}