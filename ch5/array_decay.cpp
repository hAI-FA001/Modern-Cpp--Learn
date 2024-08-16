#include <iostream>

// when we pass array, size info is lost
// so there's no difference b/w declaring the parameter as array or as ptr
void print_arr(const char s[])
{
    while (*s)
    {
        std::cout << *s++;
    }
    std::cout << '\n';
}

void print_ptr(const char *s)
{
    while (*s)
    {
        std::cout << *s++;
    }
    std::cout << '\n';
}

// non-const char* versions
void print_arr2(char s[])
{
    while (*s)
    {
        std::cout << *s++;
    }
    std::cout << '\n';
}

void print_ptr2(char *s)
{
    while (*s)
    {
        std::cout << *s++;
    }
    std::cout << '\n';
}

// as pointers are passed, we can modify original array
void modify_arr(char s[])
{
    while (*s)
    {
        *s++ = 'a';
    }
}

void modify_ptr(char *s)
{
    while (*s)
    {
        *s++ = 'a';
    }
}

int main()
{
    // we pass str literals, so params need to be const
    print_arr("Hello");
    print_ptr("World!");

    // use builtin array if params are not const
    char a1[] = "Hello";
    char a2[] = "World!";
    print_arr2(a1);
    print_ptr2(a2);

    modify_arr(a1);
    modify_ptr(a2);
    print_arr2(a1);
    print_ptr2(a2);
}