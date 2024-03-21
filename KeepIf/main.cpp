#include <cassert>
#include <vector>
#include <functional>
bool is_even(int x)
{
    return x % 2 == 0;
}

// Exercise:
// Implement keep_if on your own
// so it can be used like this:
std::vector<int> keep_if(std::function<bool(int)> predicate,std::vector<int> list)
{
    std::vector<int> result;
    for(auto e : list)
    {
        if(predicate(e))
        {
            result.emplace_back(e);
        }
    }
    return result;
}

int main()
{
    std::vector<int> xs = {0,1,2,3,4};
    const auto ys = keep_if(is_even, xs);
    assert(ys == std::vector<int>({0,2,4}));
}

// Then run some tests with it.

// Bonus:
// See if you can make it work
// for different container types
// (e.g. std::list and std::vector).
