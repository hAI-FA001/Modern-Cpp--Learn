#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void string_to_upper(string &s)
{
    for (int i = 0; i != s.size(); ++i)
    {
        // checked array access
        s.at(i) = toupper(s.at(i));
    }
}

int main()
{
    // empty mutable strings
    string s1;
    string s2{};
    // if want to use auto for empty string
    auto s3 = string();

    // can't init from char
    // string s3 = 'A';
    // this is fine
    s1 = 'A';
    // this works too
    auto s4 = string{} + 'A';

    // 2 methods to check length
    cout << "length()==size()? " << (s1.length() == s1.size()) << '\n';
    cout << "s1 Empty? " << s1.empty() << '\n';

    cout << "Enter a string: ";
    // not same as cin.getline()
    getline(cin, s1);
    // using range-for loop with ref var to update string
    for (auto &c : s1)
    {
        c = toupper(c);
    }
    cout << s1 << '\n';

    auto a = s1[99]; // this does not check index
    cout << "a=" << a << " or " << (int)a << '\n';
    // auto b = s1.at(99); // this throws if index is out of bounds
    // cout << "b=" << b << " or " << (int)b << '\n';

    s1 = "test String";
    string_to_upper(s1); // uses checked access
    cout << s1 << '\n';

    // use these instead of s[0] or s[s.length()-1]
    // these give modifiable refs
    auto first = s1.front();
    auto last = s1.back();
    cout << "first " << first << ", last " << last << '\n';
    first = 'a';
    last = 'a';
    cout << "first " << first << ", last " << last << '\n';

    // reading length() is NOT undefined
    // it returns default value of underlying type (\0 in this case)
    cout << "At length(): " << s1[s1.length()] << '\n';

    s1.insert(1, " inserted string ");
    cout << s1 << '\n';
    s1.erase(10, 5); // 2nd arg isn't last index but number of elements to remove
    cout << s1 << '\n';
    s1.replace(2, 5, "replaced");
    cout << s1 << '\n';

    // returns std::string, which is a NEW variable (a copy)
    cout << s1.substr(5, 2) << '\n';

    // use this instead of +=
    s1.append(" appended string");
    cout << s1 << '\n';
}