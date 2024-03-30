#include <fplus/fplus.hpp>
#include <functional>

int main()
{
    auto squared = [&](int x)
    {
        return x * x;
    };

    std::vector<std::vector<int>> xss = {{0,1,2}, {3,4,5}};
    fplus::transform(fplus::fwd::transform(squared),xss);

        for(auto& v : xss)
        {
            for(auto& i : v)
            {
                i = squared(i);
                std::cout << i << ", ";
            }
            std::cout << std::endl;
        }

        
    const auto add_fourCurried = [](int a)
    {
        return [a](int b)
        {
            return [a,b] (int c)
            {
                return [a,b,c] (int d)
                {
                    return a+b+c+d;
                };
            };
        };
    };
    assert(add_fourCurried(1)(2)(3)(4) == 1+2+3+4);

}

// Exercise 1:
//     Square every inner value of xss, so
//     {{0,1,2}, {3,4,5}}
//     turns into
//     {{0,1,4}, {9,16,25}}
//     Try out different possibilities to achieve your goal.

// Exercise 2:
//     Use nested lambda expressions
//     to make a fully curried version of add_four.
//     add_four (Int, Int, Int, Int) -> Int
//     add_four_curried : Int -> Int -> Int -> Int -> Int
//     so that
//     add_four(1,2,3,4)
//     means the same as
//     add_four_curried(1)(2)(3)(4)