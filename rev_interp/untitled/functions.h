#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>


float f(float x, float y);

float f1(float x, float y);

float f2(float x, float y);

float binary_search(float x, float (*func)(float x, float y), float accurancy=1e-5);

//find optimal beginning of tuple of points
int position(std::vector<float> array, int len, int n, float val);


float calculate_result(std::vector<std::vector<float>> &y, std::vector<float> &x, float search_point, int pos, int n);


void fill_table(std::vector<std::vector<float>> &y, std::vector<float> &x, int pos, int n);


void print_table(std::vector<float> &y1, std::vector<float> &y2, std::vector<float> &x, int len_x);

#endif // FUNCTIONS_H
