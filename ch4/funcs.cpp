#include <iostream>

using namespace std;

// need to define here if want to use auto return type
auto my_func()
{
    cout << "inside my_func with auto return type\n";
    return 123;
}

// forward declarations or function prototypes
int my_func2(int); // parameter or formal parameter
// this becomes a generic function
int my_func3(auto j = 123); // default value, we can skip this in function definition (only need to match the return type, name, param list)
void abs_val(int &i);

// can forward declare global vars too
extern int global_var;

int main()
{
    cout << "Global var is " << global_var << '\n';
    my_func();
    cout << my_func2(123) << '\n'; // argument or actual parameter
    cout << my_func3<string>("a") << '\n';

    int i = -100;
    abs_val(i);
    cout << i << '\n';

    // by default, main() returns 0 (AKA return code)
}

// define the var
int global_var = 123;

int my_func2(int i) // parameter or formal parameter
{
    // main implicitly returns 0
    // but other funcs require return statement
    return 123;
}

// this becomes a generic function
int my_func3(auto j)
{
    // declare before usage
    extern int some_other_global_var;
    return some_other_global_var;
}
// define
int some_other_global_var = 5;

void abs_val(int &i)
{
    i = i > 0 ? i : -i;
}