#ifndef SPLINE_H
#define SPLINE_H

//#include "errors.h"
#include <vector>
#include <iostream>

struct progon_coef {
    float eta;
    float ksi;
};

struct coef {
    float a;
    float b;
    float c;
    float d;
};

void progonka (std::vector<float>& X, std::vector<float>& y_array, std::vector<coef>& coef_table);
float interp_spline(const float x, std::vector<float>& X, std::vector<coef>& coef_table);

#endif // SPLINE_H
