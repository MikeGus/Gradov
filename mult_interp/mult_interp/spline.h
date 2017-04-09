#ifndef SPLINE_H
#define SPLINE_H

#include "errors.h"
#include <vector>
#include <iostream>

struct progon_coef {
    float psi;
    float nu;
};

struct coef {
    float a;
    float b;
    float d;

    float f;
};

size_t progonka(std::vector<float> result, std::vector<progon_coef>& progon_table, std::vector<coef>& table);

#endif // SPLINE_H
