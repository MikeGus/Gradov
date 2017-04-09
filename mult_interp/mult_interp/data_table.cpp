#include "data_table.h"

Error fill_data_table(std::vector<std::vector<float>>& table, std::vector<float>& x, std::vector<float>& y, \
                      float (*func)(float x, float y))
{
    size_t x_size = x.size();
    size_t y_size = y.size();

    table.resize(y_size);
    for (size_t i = 0; i < y_size; ++i) {
        table[i].resize(x_size);
    }

    for (size_t i = 0; i < y_size; ++i) {
        for (size_t j = 0; j < x_size; ++j) {
            table[i][j] = func(x[j], y[i]);
        }
    }

    return OK;
}

void print_data_table(std::vector<std::vector<float>>& table, std::vector<float>& x, std::vector<float>& y)
{
    std::cout << "Table:" << std::endl;
    std::cout << "     y\\x";

    size_t x_size = x.size();
    size_t y_size = y.size();

    for (size_t i = 0; i < x_size; ++i) {
        std::cout << std::setw(8) << std::setprecision(2) << std::fixed << x[i];
    }
    std::cout << std::endl << std::endl;

    for (size_t i = 0; i < y_size; ++i) {
        std::cout << std::setw(8) << y[i];
        for (size_t j = 0; j < x_size; ++j) {
            std::cout << std::setw(8) << table[i][j];
        }
        std::cout << std::endl;
    }
}
