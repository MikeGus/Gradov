#ifndef IO_H
#define IO_H

#include "errors.h"
#include <vector>
#include <iostream>

Error read_bounds(float& bottom, float& top);

Error read_interval_num(unsigned& intervals);

Error fill_vector(std::vector<float>& vector, float& bottom, float& top, unsigned intervals);

#endif // IO_H
