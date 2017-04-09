#include <iostream>
#include <vector>

#include "data.h"
#include "function.h"
#include "errors.h"
#include "matrix.h"

int main(void)
{
    std::vector<float> x;
    std::vector<float> y;
    std::vector<float> ro;
    std::vector<std::vector<float>> matrix;

    size_t intervals = 1;
    get_num_of_intervals(intervals);

    float begin = 0;
    float end = 0;

    get_borders(begin, end);

    fill_x(x, begin, end, intervals);
    fill_x(y, x, function);

    for (size_t i = 0; i < x.size(); ++i) {
        ro.push_back(1);
    }


    print_data(x, y, ro);

    std::vector<float> coefs;
    fill_matrix(matrix, coefs, x, y, ro);

    std::vector<float> func_coefs;
    gaussmethod(func_coefs, matrix, coefs);

    print_data(x, y, ro, func_coefs);

    return 0;
}
