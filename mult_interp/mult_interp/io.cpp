#include "io.h"

Error read_bounds(float& bottom, float& top)
{
    std::cout << "Enter bounds: ";
    std::cin >> bottom >> top;

    Error error = OK;
    if (std::cin.fail()) {
        error = IO_ERROR;
        return error;
    }

    if (bottom > top) {
        float buf = bottom;
        bottom = top;
        top = buf;
    }

    return error;
}

Error read_interval_num(unsigned& intervals)
{
    std::cout << "Enter number of intervals: ";
    std::cin >> intervals;

    Error error = OK;
    if (std::cin.fail() || (intervals < 1)) {
        error = IO_ERROR;
    }

    return error;
}

Error fill_vector(std::vector<float>& vector, float& bottom, float& top, unsigned intervals)
{
    float step = (top - bottom) / intervals;

    float x = bottom;
    for (unsigned i = 0; i < intervals; ++i) {
        vector.push_back(x);
        x += step;
    }

    vector.push_back(top);

    return OK;
}
