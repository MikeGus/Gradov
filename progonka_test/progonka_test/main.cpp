#include <iostream>
#include "spline.h"
#include "io.h"
#include "func.h"

int main(void)
{
    // x input
    std::cout << "X:" << std::endl;
    float x_b = 0, x_t = 0;
    read_bounds(x_b, x_t);

    unsigned x_intervals = 1;
    read_interval_num(x_intervals);

    std::vector<float> x_vector;
    fill_vector(x_vector, x_b, x_t, x_intervals);

    std::vector<float> y_vector;
    for (size_t i = 0; i < x_vector.size(); ++i) {
        y_vector.push_back(f(x_vector[i]));
    }

    print_table(x_vector, y_vector);
    std::vector<coef> coef_table;
    coef_table.resize(x_vector.size() + 1);

    float search_point = 0;
    std::cout << std::endl << "ENTER X: ";
    std::cin >> search_point;

    progonka(x_vector, y_vector, coef_table);

    float result = interp_spline(search_point, x_vector, coef_table);

    std::cout << "RESULT: " << result << std::endl;
    std::cout << "REAL RESULT: " << f(search_point) << std::endl;

    return 0;
}
