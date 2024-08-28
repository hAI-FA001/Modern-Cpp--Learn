// lambda is a callable entity
// works like a free func whilest having properties of a local var
// unlike constexpr func, it can access global state (e.g. cout)
// unlike free func, it an "capture" vars from within the scope they are called from
// compilers will implement lambdas by using functors behind the scenes

#include <iostream>
#include <functional>

int main()
{
    // syntax: [capture](optional params){body}
    // the () can be omitted as in []{}
    // lambda is assigned to var
    // funcs can be assigned too using address-of &
    // return type is void implicitly
    // it's type is "lambda []()->void", which captures its sign
    auto l = []()
    { std::cout << "Lambda is called"; };

    l();

    // w/o using auto

    // w/ typedef
    typedef void (*MyLambdaType)(bool);
    MyLambdaType l1;
    l1 = [](bool a)
    { std::cout << "Got " << a << '\n'; };

    typedef std::function<double(char)> MyOtherLambdaType;
    MyOtherLambdaType l2;
    l2 = [](char a)
    { return (double)a; };

    // w/ using
    using MyAnotherLambdaType = std::function<void()>;
    MyAnotherLambdaType l3;
    l3 = [] {};

    // w/ std::function
    std::function<int(int, int)>
        l4;
    l4 = [](int a, int b) -> int
    { return a + b; };

    // using decltype
    decltype([](int a, int b) -> int
             { return a - b; }) l5;
}