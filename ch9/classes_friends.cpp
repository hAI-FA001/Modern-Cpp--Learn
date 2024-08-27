#include <iostream>

using namespace std;

// forward declare
// allows ref and ptr to B to be used, but members can't be accessed yet
class B;

class A
{
public:
    // B can access all members of A
    friend class B;

    // definition must be written outside, *after* definition of B
    void a(B &other, int secondParam = 0);

private:
    // use m_ as prefix so it doesn't clash with member func name
    double m_a{42.42};
};

class B
{
public:
    friend class A;

    void b(A &other, int secondParam = 0)
    {
        cout << "b():" << other.m_a << '\n';
        other.m_a = secondParam;
    }

private:
    int m_b{2};
};

// defined "non-inline" or "out-of-line"
void A::a(B &other, int secondParam)
{
    cout << "a():" << other.m_b << '\n';
    other.m_b = secondParam;
}

int main()
{
    A obj_a{};
    B obj_b{};

    obj_a.a(obj_b);
    obj_b.b(obj_a);
    obj_a.a(obj_b);
    obj_b.b(obj_a);
}