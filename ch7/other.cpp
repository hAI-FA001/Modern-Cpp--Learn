#include <vector>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>

#include <stdexcept>           // need this for flat_map.h
#include "../extra/flat_map.h" // not widely available yet

#include <list>

using namespace std;

int main()
{
    // specialization of vector, stores bits as packed data
    // each bool uses 1 bit rather than 8
    vector<bool> v{true, false, false};
    // also stores bits but has fixed size
    // 16 = num bits
    bitset<16> b{0xFF77};
    deque d{1, 2, 3, 4};

    // these are container adapter: uses another container
    // note the double braces (inner braces = underlying container, so we could do s{some_container})
    stack<int, deque<int>> s{{9, 1, 2, 5, 8}};
    queue<int, vector<int>> q{{2, 1, 3}};
    priority_queue<int, deque<int>, std::greater<int>> pq{d.begin(), d.end()};
    // implements unordered map as 2 vectors essentially
    flat_map<string, string> fm{
        {"k1", "v1"},
        {"k2", "v2"},
    };
}