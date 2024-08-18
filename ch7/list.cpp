#include <iostream>
#include <forward_list>
#include <list>
#include <algorithm>

import std;

void print_lst(std::list<std::string> &lst)
{
    for (auto s : lst)
    {
        std::cout << s << " ";
    }
    std::cout << '\n';
}

void print_lst(std::forward_list<std::string> &lst)
{
    for (auto s : lst)
    {
        std::cout << s << " ";
    }
    std::cout << '\n';
}

int main()
{
    // vec is inefficient due to requirement of contiguous allocation
    // (also why there's no push_front() (can use std::deque for this limitation))
    // and requires elements of same type and size

    // std::list takes more memory (~sizeof 2 ptrs x number of elements)
    // insert/delete is faster
    std::list<std::string> lst{"a", "test", "z", "b"};
    print_lst(lst);
    // can't do begin() + 2 -> not contiguous
    lst.insert(++ ++lst.begin(), "inserted");
    print_lst(lst);
    lst.remove("test");
    print_lst(lst);

    // std::forward_list is similar but uses only 1 ptr (to next)
    std::forward_list<std::string> fwd;

    // std::list has "bi-directional iterator"
    // std::forward_list has "forward iterator"
    auto iter = fwd.before_begin(); // member func, unique to forward_list
    std::cout << "Enter some words (blank line to end): \n>";
    for (;;)
    {
        std::string s;
        std::getline(std::cin, s);
        if (s.empty())
        {
            break;
        }
        fwd.insert_after(iter, s);
        //  - | [()] -ins-> [() a] -inc-> [(a)] -push-> [a (a)]
        // +1 | [a (a)] -ins-> [a (a) b] -inc-> [a a (b)] -push-> [b a a (b)]
        // remember: this isn't index, it points to current value, so only need to increment it once and before push_front
        ++iter;
        fwd.push_front(s + "2");
        print_lst(fwd);
    }

    // copy fwd into lst2
    std::list<std::string> lst2(begin(fwd), end(fwd));
    // can't use array access or std::sort() (either cuz perf is poor or requires random access)
    // so std::list has own sort()
    // lst[0] = 1;
    // std::sort(lst.begin(), lst.end());
    lst2.sort(); // builtin sort(), not std::sort
    for (const auto &e : lst2)
    {
        std::cout << "- " << e << '\n';
    }

    auto it1 = fwd.begin();
    auto it2 = lst2.begin();
    for (; it1 != fwd.end() and it2 != lst2.end(); ++it1, ++it2)
    {
        std::cout << "Comparing: " << *it1 << " and " << *it2 << '\n';
    }
}