#include <fplus/fplus.hpp>

typedef std::pair<float, float> point;

float point_distance(const point& p1, const point& p2)
{
    const float dx = p2.first - p1.first;
    const float dy = p2.second - p1.second;
    return std::sqrt(dx * dx + dy * dy);
}

int main()
{
    using namespace std;

    vector<point> polygon =
        { {1,2}, {7,3}, {6,5}, {4,4}, {2,9} };

    const auto edges =
        fplus::overlapping_pairs_cyclic(polygon);

    const auto result =
        //fplus::maximum_on(point_distance, edges);
        // instead of two separate points we need to use a vector<point>
        fplus::maximum_on([&edges] (const point& p1, const point& p2) -> bool
        {
            const float dx = p2.first - p1.first;
            const float dy = p2.second - p1.second;
            float dist1 = std::sqrt(dx * dx + dy * dy);

            const float dx2 = p1.first - p2.first;
            const float dy2 = p1.second - p2.second;
            float dist2 = std::sqrt(dx2 * dx2 + dy2 * dy2);
            return dist1 > dist2;
        },edges);

    cout << fplus::show(result) << endl;
}

// Exercise:
//     Change the call to maximum_on
//     by using a lambda function
//     using point_distance internally,
//     so the code compiles and runs as intended.
