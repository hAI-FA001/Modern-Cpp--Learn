// exceptions alter the normal flow
// exceptions thrown from outside try-block or from funcs declared noexcept will terminate the program

#include <iostream>
#include <exception>

template <typename T>
T getInteger(T value)
{
    std::cout << "Enter an int (0 to throw): ";
    std::cin >> value;
    if (!value)
    {
        // usually u want to throw an instance of std::exception
        // but any type can be thrown
        // and if u don't specify an object, std::terminate is called
        // if we catch it by-ptr, need to add "new"
        throw new std::exception{};
    }

    return value;
}

int main()
{
    long long v{};
    try
    {
        v = getInteger(v);
    }
    // the "..." catches any type AKA catch-all exception
    // catch (...)
    // caught object should be named by ref
    // this becomes the "current exception"
    // can catch it by value and by ptr too

    // why by-ref over by-value?
    //   if ExA inherits from ExB and we throw ExA,
    //   then by-value would convert ExA to ExB and lose the specifics of ExA such as error code
    //   AKA no "slicing" (where derived class object is truncated to base class size)
    // why not by-ptr?
    //   memory management headaches
    //   by-ref means no memory leaks
    catch (std::exception *e)
    {
        std::cerr << "Caught exception\n";
        std::cerr << e->what() << '\n';
        delete e;
        // return 1;
        // putting throw in catch block has special meaning: rethrow the exception
    }
    std::cout << "Got value: " << v << '\n';
}