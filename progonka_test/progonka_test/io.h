#ifndef IO_H
#define IO_H

#include "errors.h"
#include <vector>
#include <iostream>
#include <iomanip>

Error read_bounds(float& bottom, float& top);

Error read_interval_num(unsigned& intervals);

Error fill_vector(std::vector<float>& vector, float& bottom, float& top, unsigned intervals);

void print_table(std::vector<float>& x, std::vector<float>& y);

#endif // IO_H
