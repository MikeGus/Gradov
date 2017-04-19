#include <iostream>
#include <vector>

#include "data.h"
#include "function.h"
#include "errors.h"
#include "matrix.h"
#include <fstream>

int main(void)
{
    std::vector<float> x;
    std::vector<float> y;
    std::vector<float> ro;
    std::vector<std::vector<float>> matrix;

    size_t intervals = 1;

    std::ifstream input;
    input.open("C:/Programs/Gradov/mid_double/mid_double/data.txt");
    if (!input.is_open()) {
        std::cout << "Can not open file.\n";
        return 0;
    }
    get_num_of_intervals(intervals, input);
    fill_x(x, input, intervals);
    fill_x(y, input, intervals);
    fill_x(ro, input, intervals);
    input.close();

    std::cout << "Number of intervals: " << intervals << std::endl;
    print_data(x, y, ro);
/*    float begin = 0;
    float end = 0;
    get_borders(begin, end); */

    size_t n = 0;
    std::cout << "Enter n: ";
    std::cin >> n;

/*    fill_x(x, input, intervals);
    fill_x(x, begin, end, intervals);
    fill_x(y, x, function);

    for (size_t i = 0; i < x.size(); ++i) {
        ro.push_back(1);
    }
    */



    std::vector<float> coefs;
    fill_matrix(matrix, coefs, x, y, ro, n + 1);


    std::vector<float> func_coefs;
    gaussmethod(func_coefs, matrix, coefs);

    print_matrix(matrix, coefs);
    print_data(x, y, ro, func_coefs, n + 1);

    return 0;
}
