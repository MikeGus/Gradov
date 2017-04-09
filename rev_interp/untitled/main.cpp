#include <iostream>
#include "functions.h"
#include "utils.h"
#include <iomanip>


int main(void)
{
    std::cout << "Bounds of interval: [ " << x_bottom << " .. " << x_top << " ]" << std::endl;
    std::cout << "Enter number of intervals: ";
    unsigned int_num = 1;

    std::cin >> int_num;
    if (int_num < 1) {
        std::cout << "Wrong number of intervals!" << std::endl;
        return -1;
    }

    float step = (x_top - x_bottom) / int_num;
    unsigned point_num = int_num + 1;

    std::vector<float> x_array;
    for (float x = x_bottom; x < x_top; x+= step) {
        x_array.push_back(x);
    }
    x_array.push_back(x_top);

    std::vector<float> y1_array;
    std::vector<float> y2_array;

    for (auto it = x_array.begin(); it < x_array.end(); ++it) {
        y1_array.push_back(binary_search(*it, f1));
        y2_array.push_back(binary_search(*it, f2));
    }

    //resizing y
    std::vector<std::vector<float>> y;
    y.resize(point_num);
    for(unsigned i = 0; i < point_num; ++i) {
        y[i].resize(point_num, 0);
    }

    for (unsigned i = 0; i < point_num; ++i) {
        y[0][i] = x_array[i];
    }

    std::vector<float> y_array;
    for (unsigned i = 0; i < point_num; ++i) {
        y_array.push_back(y1_array[i] - y2_array[i]);
    }

    //read n
    unsigned n = min_n;
    std::cout << "Enter n in bounds [" << min_n << " .. " << point_num - 1 << "] : ";
    std::cin >> n;

    //check n
    if (n < min_n || n > point_num - 1) {
        std::cout << "N is out of bounds!" << std::endl;
        return -1;
    }

    //n becomes number of points
    n = n + 1;

    //printing table
    print_table(y1_array, y2_array, x_array, point_num);

    //calculating position of first x
    int pos = position(y_array, point_num, n, search_point);

    //filling table
    fill_table(y, y_array, pos, n);

    //calculating result
    float result = calculate_result(y, y_array, search_point, pos, n);
    float y_result = binary_search(result, f1);

    //printing result
    std::cout << std::endl;
    std::cout << "N: " << n - 1 << std::endl;
    std::cout << "Calculated point: x = " << result << "\ty = " << y_result <<std::endl;

    std::cout << "Check:" << std::endl;
    std::cout << std::fixed;
    std::cout << "F1(x, y) = " << f1(result, y_result) << std::endl;
    std::cout << "F2(x, y) = " << f2(result, y_result) << std::endl;

    return 0;
}
