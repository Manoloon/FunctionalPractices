#include <cassert>
#include <vector>
#include <array>
#include <iostream>
#include <functional>
//#include <fplus/fplus.hpp>

template<typename T>
bool is_even(T x)
{
    static_assert(std::is_arithmetic_v<T>,"is_even: T must be an arithmetic type");
    return static_cast<int>(x) % 2 == 0;
}

// Exercise:
// Implement keep_if on your own
// so it can be used like this:
template<typename T,typename V>
std::vector<T> keep_if(std::function<bool(T)> pred, const V& container)
{
    std::vector<T> result;
    for(const auto& e : container)
    {
        if(pred(e))
        {
            result.emplace_back(e);
        }
    }
    return result;
}

int main()
{
    std::vector<int> xs = {0,1,2,3,4};
    auto ys = keep_if<int>(is_even<int>, xs);
    for(auto y : ys)
    {
        std::cout << y << ", ";
    }
    std::cout << std::endl;
    assert(ys == std::vector<int>({0,2,4}));

    std::array<float,4> fs = {1.3,2.2,4.0,6.0};
    auto resultFs = keep_if<float>(is_even<float>,fs);
    for(auto y : resultFs)
    {
        std::cout << y << ", ";
    }
    assert(resultFs == std::vector<float>({2.2,4.0,6.0}));
}

// Then run some tests with it.

// Bonus:
// See if you can make it work
// for different container types
// (e.g. std::list and std::vector).
