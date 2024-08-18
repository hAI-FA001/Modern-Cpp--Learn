#include <set>
#include <iterator>
#include <iostream>

import std;

// #include <algorithm>

using namespace std;

int main()
{
    // std::set is ordered (elements are sorted) -> also overhead

    set<string> s{
        "test",
        "C++",
        "test",
        "test",
        "cpp",
    };

    copy(begin(s), end(s), ostream_iterator<string>(cout, "\n"));
    s.insert("C++");
    copy(begin(s), end(s), ostream_iterator<string>(cout, "\n"));

    // can't use array access
    // s[0];

    // this allows dups
    multiset<string> s2{
        "test",
        "C++",
        "test",
        "test",
        "cpp"};
    s2.insert("C++");

    print("\nMultiset:\n");
    copy(s2.begin(), s2.end(), ostream_iterator<string>(cout, "\n"));

    // constant time lookup due to hash function
    // does not keep elements sorted
    // apparent "order" can change on each addition/removal
    // for unordered set of user defined types, need to provide hash function (a "specialization" of std::hash)
    // there's unordered_multiset too
    unordered_set<string> s3{};
    while (true)
    {
        print("Enter a string (-1 to quit): ");
        string str;
        getline(cin, str);
        if (str == "-1")
        {
            break;
        }
        s3.insert(str);
        print("Collection: ");
        copy(begin(s3), end(s3), ostream_iterator<string>(cout, ", "));
        println("");
    }
}