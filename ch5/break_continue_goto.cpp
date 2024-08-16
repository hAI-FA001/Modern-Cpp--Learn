#include <iostream>

int main()
{
    int i{}, j{};
    // using "break" would only break out of inner loop
    // can use goto for this purpose, but it's rarely needed
    for (; i < 10; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i * j > 5)
            {
                goto break_out_of_loop;
            }
        }
    }
break_out_of_loop:
    std::cout << "Broke out of loop at " << i << ',' << j << '\n';
}