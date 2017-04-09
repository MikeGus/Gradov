#include <iostream>
#include "functions.h"
#include "utils.h"



int main(void) {

    float x_top = 0;
    float x_bottom = 0;
    int len_x = 2;


    //read bounds
    std::cout << "Enter bounds of interval: ";
    std::cin >> x_bottom >> x_top;
    if(x_bottom > x_top) {
        float buf = x_top;
        x_top = x_bottom;
        x_bottom = buf;
    }

    //read number of intervals
    std::cout << "Enter number of intervals >= " << min_intervals << ": ";
    std::cin >> len_x;

    //check number of intervals
    if(len_x < min_intervals) {
        std::cout << "Wrong number of intervals!" << std::endl;
        return -1;
    }

    std::vector<float> x;

    //calculating step
    float step = (x_top - x_bottom) / len_x;

    //filling x
    for(float i = x_bottom; i < x_top; i += step) {
        x.push_back(i);
    }
    //fill last point (precautions cause x contains floats)
    x.push_back(x_top);
    len_x += 1;

    //resizing y
    std::vector<std::vector<float>> y;
    y.resize(len_x);
    for(int i = 0; i < len_x; ++i) {
        y[i].resize(len_x, 0);
    }

    for (int i = 0; i < len_x; ++i) {
        y[0][i] = f(x[i]);
    }

    //read search_point
    float search_point = x[0];
    std::cout << "Enter x in bounds [" << x[0] << " .. " << x[len_x - 1] <<"] : ";
    std::cin >> search_point;

    //check search point
    if (search_point < x[0] || search_point > x[len_x - 1]) {
        std::cout << "Search point is out of bounds!" << std::endl;
        return -1;
    }

    //read n
    int n = min_n;
    std::cout << "Enter n in bounds [" << min_n << " .. " << len_x - 1 << "] : ";
    std::cin >> n;

    //check n
    if (n < min_n || n > len_x - 1) {
        std::cout << "N is out of bounds!" << std::endl;
        return -1;
    }

    //n becomes number of points
    n = n + 1;

    //printing table
    print_table(y, x, len_x);

    //calculating position of first x
    int pos = position(x, len_x, n, search_point);

    //filling table
    fill_table(y, x, pos, n);

    //calculating result
    float result = calculate_result(y, x, search_point, pos, n);

    //printing result
    std::cout << std::endl;
    std::cout << "Calculated number: " << result << std::endl;
    std::cout << "N: " << n - 1 << std::endl;
    std::cout << "Real number: " << f(search_point) << std::endl;

    return 0;
}
