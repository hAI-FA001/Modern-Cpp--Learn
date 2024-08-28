// scope where we define lambdas can be different than scope where we call it
// so need to take care regarding dangling refs
// captured vars must not be out of scope when invoking
// capturing vars is analogous to state in functors

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<double> v{3, 5, 2, 6, 2, 4};
    double min, max;
    int num{1};
    double avg;
    bool first{true};

    // [&] means capture by-ref
    // can specify like [&min, &max, &num, &avg, &first]
    // v is also captured by ref here
    // [=] gives errors in body where we assign to outer scope vars
    //   (expression must be l-value)
    // [] gives error that enclosing-function local var can't be referenced unless it's in capture list
    auto l = [&](auto i)
    {
        if (first)
        {
            min = max = avg = i;
            first = false;
            return;
        }

        if (i < min)
        {
            min = i;
        }

        if (i > max)
        {
            max = i;
        }

        avg = ((avg * num) + i) / (num + 1);
        ++num;
    };

    // can pass lambda by value (std::ref() not needed)
    std::for_each(std::begin(v), std::end(v), l);
    std::cout << "Min, Max, Avg, Num: " << min << ' ' << max << ' ' << avg << ' ' << num << '\n';

    std::vector v2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // need to reset these too
    min = max = avg = 0;
    num = 1;
    first = true;
    std::for_each(std::begin(v2), std::end(v2), l);
    std::cout << "Min, Max, Avg, Num: " << min << ' ' << max << ' ' << avg << ' ' << num << '\n';
}