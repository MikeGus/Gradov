#ifndef DATA_TABLE_H
#define DATA_TABLE_H

#include <vector>
#include <iostream>
#include <iomanip>
#include "errors.h"
#include "functions.h"

Error fill_data_table(std::vector<std::vector<float>>& table, std::vector<float>& x, std::vector<float>& y, \
                      float (*func)(float x, float y));

void print_data_table(std::vector<std::vector<float>>& table, std::vector<float>& x, std::vector<float>& y);

#endif // DATA_TABLE_H
