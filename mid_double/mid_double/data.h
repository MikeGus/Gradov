#ifndef DATA_H
#define DATA_H

#include "errors.h"
#include <vector>
#include <iostream>
#include <iomanip>

void get_num_of_intervals(size_t &intervals, std::istream &input);
void get_borders(float& begin, float& end);
void fill_x(std::vector<float>& x, float begin, float end, size_t intervals);
void fill_x(std::vector<float>& x, std::istream& input, size_t intervals);
void fill_x(std::vector<float>& result, std::vector<float>& source, float (*func)(float point));

void print_data(std::vector<float>& x, std::vector<float>& y, std::vector<float>& ro, std::vector<float>& coefs, int size);
void print_data(std::vector<float>& x, std::vector<float>&y, std::vector<float>& ro);

#endif // DATA_H
