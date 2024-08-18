#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

// use ref else it'll make copy of both the vec and the array it maintains
void populate_int(vector<double> &v)
{
    for (;;)
    {
        cout << "Enter a number (-1 to quit): ";
        double i{};
        cin >> i;
        if (i == -1)
        {
            break;
        }
        // adds at end, growing the container
        v.push_back(i);
    }
}

int main()
{
    vector<double> v;
    populate_int(v);

    // sorts in reverse
    // don't use crbegin or crend -> will give error as sort() modifies vector
    sort(rbegin(v), rend(v));

    // copies from 1st param upto (not incl) 2nd param into 3rd param
    // 3rd param is "output iterator": takes type of output (int), output stream and optional delimiter
    copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
    cout << '\n';

    sort(v.begin(), v.end());
    // using range-for
    for (auto val : v)
    {
        cout << val << " ";
    }
    cout << '\n';

    // should prefer member functions for algos
    // e.g. string.find() returns index after **linear search**
    // vector.find() returns iterator after **linear search**
    // set.find() returns iterator after **binary search** (as set impl maintains elements in sorted order)
    string a{"hello"};
    vector v2{1, 9, 7, 3};
    set s{3, 8, 6, 4, 3}; // dup will be removed

    sort(begin(v2), end(v2));

    cout << "Before: \nstring: " << a << "\nvector: ";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << "\nset: ";
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    // string's find returns index
    // not found means string::npos was returned
    auto f1 = a.find('l');
    if (f1 != string::npos)
    {
        cout << "Found in string at pos " << f1 << '\n';
        // takes 2nd param (number of chars to erase)
        a.erase(f1, 1);
    }

    // these return iter (not index)
    // so not found means iter is end(container)

    // lower_bound returns where the item is (or where it should be inserted)
    // binary_search tells whether it exists or not
    auto f2 = std::lower_bound(begin(v2), end(v2), 7);
    if (std::binary_search(begin(v2), end(v2), 7))
    {
        cout << "Found in vector *f2=" << *f2 << '\n';
        // these don't take 2nd param
        // they only erase 1 element
        v2.erase(f2);
    }

    auto f3 = s.find(6);
    if (f3 != end(s))
    {
        cout << "Found in set *f3=" << *f3 << '\n';
        s.erase(f3);
    }

    cout << "After: \nstring: " << a << "\nvector: ";
    copy(begin(v2), end(v2), ostream_iterator<int>(cout, " "));
    cout << "\nset: ";
    copy(begin(s), end(s), ostream_iterator<int>(cout, " "));
    cout << '\n';

    v2.push_back(111);
    v2.emplace_back(999);
    copy(begin(v2), end(v2), ostream_iterator<int>(cout, " "));
    cout << '\n';
}