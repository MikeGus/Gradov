#include <iostream>
#include <vector>
#include "io.h"
#include "data_table.h"

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

    // y input
    std::cout << "Y:" << std::endl;
    float y_b = 0, y_t = 0;
    read_bounds(y_b, y_t);

    unsigned y_intervals = 1;
    read_interval_num(y_intervals);

    std::vector<float> y_vector;
    fill_vector(y_vector, y_b, y_t, y_intervals);


    // fill data table
    std::vector<std::vector<float>> table;
    fill_data_table(table, x_vector, y_vector, f);

    print_data_table(table, x_vector, y_vector);

    float search_x = 0;
    float search_y = 0;

    std::cout << std::endl;
    std::cout << "Enter search point: ";
    std::cin >> search_x >> search_y;

    if (std::cin.fail()) {
        std::cout << "Wrong input!" << std::endl;
        return IO_ERROR;
    }
    if (search_x < x_b || search_x > x_t || search_y < y_b || search_y > y_t) {
        std::cout << "Search point out of bounds!" << std::endl;
        return SP_OUT_OF_BOUNDS;
    }

    std::vector<std::vector<float>> calculation_table;
    create_table(calculation_table, y_intervals + 1);

    float n_x = 0;
    std::cout << "Enter n (axis OX): ";
    std::cin >> n_x;
    if (std::cin.fail()) {
        std::cout << "Wrong input!" << std::endl;
        return IO_ERROR;
    }
    n_x++;

    float n_y = 0;
    std::cout << "Enter n (axis OY): ";
    std::cin >> n_y;
    if (std::cin.fail()) {
        std::cout << "Wrong input!" << std::endl;
        return IO_ERROR;
    }
    n_y++;

    //filling calcutation line
    int pos = position(x_vector, x_vector.size(), n_x, search_x);
    std::vector<float> result_line;
    for (size_t i = 0; i < y_intervals + 1; ++i) {
        for (size_t j = 0; j < x_intervals + 1; ++j) {
            calculation_table[0][j] = table[i][j];
        }
        fill_table(calculation_table, x_vector, pos, n_x);
        float res = calculate_result(calculation_table, x_vector, search_x, pos, n_x);
        result_line.push_back(res);
    }

    pos = position(y_vector, y_vector.size(), n_y, search_y);
    for (size_t i = 0; i < y_intervals + 1; ++i) {
        calculation_table[0][i] = result_line[i];
    }
    fill_table(calculation_table, y_vector, pos, n_y);

    float result = calculate_result(calculation_table, y_vector, search_y, pos, n_y);
    std::cout << std::endl;
    std::cout << "Result: " << std::setprecision(5) << result << std::endl;
    std::cout << "Real result: " << f(search_x, search_y) << std::endl;

    return 0;
}
