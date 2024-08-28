#include <string>
#include <string_view>

using namespace std::literals;

// generics implies:
//   types as params
//   compiler-generated code

// T = type passed
// U = return type
template <typename T, typename U = double>
// pass by const-ref in case large, user-defined types are passed
// this usage should be anticipated for generics
// note: production code could use std::midpoint
U average(const T &a, const T &b)
{
    return (a + b) / U{2}; // force promotion to be applied if U is float
}

// simplest type of template is the variable
template <typename T = long double>
constexpr T pi{3.1415926536897932385L};

template <typename T>
// note: production code could use std::min
T minimum(const T &a, const T &b)
{
    return (a < b) ? a : b;
}

// need default type as we use default ctor
// char is chosen as it's the smallest
// void may be preferred in theory, but compiler would produce error when it sees "void value" during instantiation of class
template <typename T = char>
// note: std::optional<T> is recommended
class Opt
{
    bool valid{false};
    T value;

public:
    Opt() = default;
    Opt(const T &value) : value{value}, valid{true} {};

    // this allows us to redefine a value (but not its type)
    Opt &operator=(const T &new_value)
    {
        value = new_value;
        valid = true;
        return *this;
    }

    bool hasValue() const { return valid; }
    const T &get() const
    {
        if (!valid)
        {
            throw;
        }
        else
        {
            return value;
        }
    }
};

class Stringy
{
    std::string str;

public:
    // ctor is defined w/ both "template" and "explicit"
    // explicit means do not perform any implicit conversions
    //   e.g. if we have Foo(int x) ctor and a void bar(Foo foo), we can call bar(123) and it implicitly uses Foo(int x) for conversion
    //   with "explicit", we disallow such conversions
    //   also this kind of ctor is called a "converting ctor"
    // so new ctor is (attempted to be) generated when called with different types
    // this takes an r-value ref T&&, and funcs that take r-value ref promise not to modify it
    // such funcs can be used w/ temporaries and is efficient cuz it doesn't copy the temporary
    template <typename T>
    explicit Stringy(T &&str) : str{str} {}

    std::string get() const { return str; }
};

int main()
{
    // return types: double, double, int, double
    auto a1 = average(3.5, 3.0);
    auto a2 = average(3, 4);
    auto a3 = average<int, int>(3, 4);
    auto a4 = average<double>(3.5, 3);

    // types: float, double, long double
    // <> is always necessary when dereferencing template vars
    // <float> or <double> is useful where auto promotion of float isn't desired
    auto circ = pi<float> * 2.0f * 1.5f;
    auto area = pi<double> * 1.5 * 1.5;
    auto pi2 = pi<> * 2.0L;

    // error: <int> or <double>?
    // auto m1 = minimum(3, 2.5);
    // int
    auto m2 = minimum(-2, 1);
    // double
    auto m3 = minimum(-5.5, -6.5);

    // types: double, int, char, size_t
    auto o1 = Opt{1.2};
    auto o2 = Opt{3};
    auto o3 = Opt{};
    auto o4 = Opt<size_t>{};

    // init from: const char*, string, string_view, char
    Stringy sy1{"Star"};
    Stringy sy2{"Wars"s};
    Stringy sy3{"Trilogy"sv};
    Stringy sy4{'V'};
    // error: narrow from int to char
    // Stringy sy5{5};
}