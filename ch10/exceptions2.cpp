#include <iostream>
#include <exception>
#include <stdexcept>

class FatalError : public std::runtime_error
{
public:
    FatalError(std::string msg, int rc) : std::runtime_error{msg}, rc{rc} {}

    const int getRC() const { return rc; }

private:
    int rc;
};

int throwing()
{
    std::cout << 1 + R"(
    Please choose:
    1) throw std::runtime_error
    2) throw std::exception
    3) throw int
    4) throw FatalError
    5) quit
    Enter 1-5: )";

    int option;
    std::cin >> option;

    switch (option)
    {
    case 1:
        throw std::runtime_error{"std::runtime_error thrown"};
    case 2:
        throw std::exception{};
    case 3:
        throw 99;
    case 4:
        throw FatalError{"FatalError thrown", 1};
    case 5:
        return 1;
    default:
        std::cout << "Error: unrecognized option\n";
    }
    return 0;
}

int main()
{
    for (;;)
    {
        int action{};
        try
        {
            action = throwing();
        }
        catch (FatalError &e)
        {

            std::cerr << "Caught FatalError (" << e.what() << "), code: " << e.getRC() << "\n";
        }
        catch (std::runtime_error &e)
        {
            std::cerr << "Caught std::runtime_error (" << e.what() << ")\n";
        }
        catch (std::exception &e)
        {
            std::cerr << "Caught std::exception\n";
        }
        catch (...)
        {
            std::cerr << "Caught something other than std::exception. Quitting.\n";
            return 99;
        }

        if (action)
        {
            return action;
        }
    }
}