#include <iostream>
#include <vector>
#include <algorithm>

// functors can have state
// so we can calc running avg, min and max like this
template <typename T>
struct MinMaxAvg
{
    void operator()(T i)
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
    }

    T min, max;
    int num{1};
    T avg;
    bool first{true};
};

int main()
{
    // std::vector v{3, 5, 2, 6, 2, 4};
    // this also compiles
    // "v" is std::initializer_list<int>
    // auto v = {3, 5, 2, 6, 2, 4};
    // this also compiles
    const int v[] = {3, 5, 2, 6, 2, 4};

    // need "f" before std::for_each
    // so it's state is accessible after std::for_each
    MinMaxAvg<int> f;
    // std::ref() passes functor as ref
    // otherwise a copy would be made and result would be lost after std::for_each's scope
    // std::for_each decompose into f(3), f(5), etc
    // could do the same w/ range-for, but logic would be repeated in the body
    std::for_each(std::begin(v), std::end(v), std::ref(f));

    std::cout << "Min: " << f.min << ", Max: " << f.max << ", Avg: " << f.avg << ", Num: " << f.num << '\n';
}