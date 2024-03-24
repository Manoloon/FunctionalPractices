#include <fplus/fplus.hpp>

int str_to_int(const std::string& str)
{
    int result;
    std::istringstream(str) >> result;
    return result;
}
template<typename T>
T str_to_type(const std::string& str)
{
    T result;
    std::istringstream(str) >> result;
    return result;
}

int main()
{
    const std::string input = "1,5,4,7,2,2,3";
    const auto parts = fplus::split(',', false, input);

    const auto nums =
        fplus::transform(str_to_int, parts);

    const auto result =
        //fplus::reduce(std::multiplies<int>(), 1, nums);
        fplus::reduce(std::plus<int>(), 1, nums);

    std::cout << result << std::endl;

    const std::string inputFloat = "1.2,5.3,4.4,7.5,2.1,3.8";
    const auto partsF = fplus::split(',', false, inputFloat);
    const auto numsF = fplus::transform(str_to_type<double>,partsF);
    const auto resultF = fplus::reduce(std::plus<double>(),1,numsF);
    std::cout << resultF << std::endl;
}

// Exercise:
//
//     Modify the code,
//     so that the numbers are not multiplied but added.
//
//     Additionally change it
//     so that is works with floating point numbers too.
//     For this you should parse doubles instead of ints.
