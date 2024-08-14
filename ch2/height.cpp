#include <print>

using namespace std;

namespace Wonderland
{
    auto alice_height_m{0.15};

    // nested
    namespace Animals
    {
        auto white_rabbit{1};
    } // namespace Animals

} // namespace Wonderland

// another way for nested namespaces
namespace Wonderland::Animals
{
    auto mouse{2};
} // namespace Wonderland::Animals

namespace VictorianEngland
{
    auto alice_height_m{0.9};
} // namespace VictorianEngland

// unnamed namespace
// purpose: replace static keyword in global variable definitions
namespace
{
    int i = 3000;
} // namespace

int main()
{
    using namespace VictorianEngland;
    println("Alice height varies b/w {}m and {}m", Wonderland::alice_height_m, alice_height_m);
    println("i={}", i);
}