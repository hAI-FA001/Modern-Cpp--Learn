#include <iostream>
#include <string_view>

using namespace std::literals;

template <typename T>
struct LambdaAutoAsFunctor
{
    void
    operator()(T s) { std::cout << "Functor template: " << s << '\n'; }
};

int main()
{
    auto l = [](std::string_view &s)
    { std::cout << "Lambda: " << s << '\n'; };

    std::string str = "Hello";
    std::string_view str_view = str;
    l(str_view);

    std::cout << "Enter a string: ";
    std::cin >> str;
    str_view = str;

    l(str_view);

    struct LambdaAsFunctor
    {
        void operator()(std::string_view s)
        {
            std::cout << "Functor: " << s << '\n';
        }
    };

    LambdaAsFunctor f;
    f(str);

    auto l_auto = [](auto s)
    { std::cout << "Lambda auto: " << s << '\n'; };
    l_auto(str);

    LambdaAutoAsFunctor<std::string_view> fa;
    fa(str);
}