#include <iostream>

enum Rank : unsigned short
{
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

enum class Suit : char
{
    spades = 'S',
    clubs = 'C',
    hearts = 'H',
    diamonds = 'D',
    none = '\?'
};

// composite type
// Rank is 16b, Suit is 8b -> 24b
// there may be some padding at the end to make it 32b
// needs to be put after the enum definitions
struct PlayingCard
{
    Rank r;
    Suit s;
};

struct Point
{
    // will get default values
    int x{}, y{};
};

Point mirror_point_pass_by_value(Point p)
{
    p.x = -p.x;
    p.y = -p.y;

    return p;
}

// const ref gives error
// Point mirror_point_pass_by_const_ref(const Point &p)
// {
//     p.x = -p.x;
//     p.y = -p.y;

//     return p;
// }

void mirror_point_pass_by_ref(Point &p)
{
    p.x = -p.x;
    p.y = -p.y;
}

void mirror_point_pass_ptr(Point *p)
{
    p->x = -p->x;
    p->y = -p->y;
}

int main()
{
    // uniform init
    PlayingCard ace_of_spades{ace, Suit::spades};
    // this gives error as we use typed enum
    // PlayingCard ace_of_spades{Suit::spades, ace};
    // aggregate init
    auto [the_rank, the_suit] = ace_of_spades;

    Point p1{2, 3};

    // could do this too but less intuitive + also doesn't default init
    using PointA = int[2];
    PointA p2{4, 5};

    std::cout << "Enter x: ";
    std::cin >> p1.x;
    std::cout << "Enter y: ";
    std::cin >> p1.y;

    std::cout << "Some operation: " << p1.x * p1.y << '\n';

    Point test{10, 20};
    std::cout << test.x << ", " << test.y << '\n';
    test = mirror_point_pass_by_value(test);
    std::cout << test.x << ", " << test.y << '\n';
    mirror_point_pass_by_ref(test);
    std::cout << test.x << ", " << test.y << '\n';
    mirror_point_pass_ptr(&test);
    std::cout << test.x << ", " << test.y << '\n';
}