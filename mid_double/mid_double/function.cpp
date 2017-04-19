#include "function.h"

#include <cmath>

float function(float x)
{
    return 2 *x * x * x + 3 * x - 4 ;
}

float calculate_fi(std::vector<float>& coefs, float x, int size)
{
    float result = 0;
    for (size_t i = 0 ; i < size; ++i) {
        result += coefs[i] * pow(x, i);
    }

    return result;
}
