#include <iostream>
#include <vector>
#include <cmath>
#include "utils.hpp"


float F(float x, float y);
std::vector<Dot> find_dots(float accurancy, float step, float b_x, float t_x);
float binary_search(float accurancy, float x, float (*func)(float x, float y));
float add(std::vector<Dot> &mask);
void print_result(std::vector<Dot> &mask);

int main(void)
{
    float accurancy = base_accurancy;
    float intervals;

    std::cout << "Enter y accurancy: ";
    std::cin >> accurancy;
    std::cout << "Enter number of intervals: ";
    std::cin >> intervals;

    float step = (x_top - x_bottom) / intervals;

    auto mask = find_dots(accurancy, step, x_bottom, x_top);
    float result = ((mask[0]).y - (mask[intervals]).y) / 2;
    auto it = mask.begin();
    it++;

    for (; it != mask.end(); it++) {
        result += (*it).y;
    }

    result = result * step;

    //print_result(mask);
    std::cout << "Result: " << result;

    return 0;
}

float F(float x, float y) {
    return exp(pow(x, 3) - y) - pow(x, 6) + 2 * pow(x, 3) * y + \
            2 * pow(x, 3) - pow (y, 2) - 2 * y - 2;
}

float binary_search(float accurancy, float x, float (*func)(float x, float y)) {

    float y_b = y_bottom;
    float y_t = y_top;

    while(func(x, y_t) * func(x, y_b) > 0) {
        y_t *= 2;
        y_b *= 2;
    }

    float y_m = (y_t + y_b) / 2;

    while(fabs(y_t - y_b) > fabs(y_m) * accurancy + accurancy) {
        if (func(x, y_m) * func(x, y_t) < 0) {
            y_b = y_m;
        }
        else {
            y_t = y_m;
        }
        y_m = (y_t + y_b) / 2;
    }

    return y_m;
}

std::vector<Dot> find_dots(float accurancy, float step, float b_x, float t_x) {

    float x = b_x;
    std::vector<Dot> mask;

    Dot buf;

    while (x <= t_x){

        buf.x = x;
        buf.y = binary_search(accurancy, x, F);
        mask.push_back(buf);
        x += step;
    }

    return mask;
}

void print_result(std::vector<Dot> &mask) {
    std::cout << "X\t\tY" << std::endl;
    auto it = mask.begin();
    while(it < mask.end()) {
        std::cout << (*it).x << "\t" << (*it).y << std::endl;
        it++;
    }
}
