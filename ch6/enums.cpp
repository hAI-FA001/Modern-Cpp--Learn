#include <iostream>

// underlying type must be an integer (can also be `char`)
enum Rank : unsigned short
{
    // the "enumerators"
    ace = 1,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    none = 99
};

// enum class was made to address limitations of anonymous enums in C (name collisions in enums & assigning enum of 1 to enum of another)
// enum class AKA scoped or strongly typed enum
enum class Suit : char
{
    spades = 'S',
    clubs = 'C',
    hearts = 'H',
    diamonds = 'D',
    none = '\?' // does not clash w/ "none" in Rank
};

void print_suit(Suit s)
{
    switch (s)
    {
    case Suit::spades:
        std::cout << "Spades";
        break;

    case Suit::clubs:
        std::cout << "Clubs";
        break;

    case Suit::hearts:
        std::cout << "Hearts";
        break;

    case Suit::diamonds:
        std::cout << "Diamonds";
        break;
    case Suit::none:
        std::cout << "None";
        break;
    default:
        std::cout << "Out of enumeration set";
        break;
    }

    std::cout << '\n';
}

int main()
{
    Rank r1{ace},
        r2{},       // 0 is default value which isn't in the enumeration set -> possible problem
        r3{};       // worse: r3 has a random value
    auto r4 = king; // type is Rank
    int i = seven;  // type implicitly changed to integral

    // enums in enum class must be qualified with the type name
    Suit s1 = Suit::hearts;
    Suit s2{};    // s2 has value of zero/NUL -> possible problem
    Suit s3{'S'}; // this works too
    auto s4 = Suit::diamonds;
    // this gives error (no implicit conversion done)
    // char c = Suit::none;

    Rank ranks[13];
    for (int j = 0; j != 13; j++)
    {
        ranks[j] = (Rank)(j + 1);
    }
    for (auto p = std::rbegin(ranks); p != std::rend(ranks); ++p)
    {
        std::cout << *p << ' ';
    }
    std::cout << '\n';

    print_suit(s1);
    print_suit(s2);
    print_suit(s3);
    print_suit(s4);
}