#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>


//main function
float f(float x);


//reserve function
float f2(float x);


//find optimal beginning of tuple of points
int position(std::vector<float> array, int len, int n, float val);


float calculate_result(std::vector<std::vector<float>> &y, std::vector<float> &x, float search_point, int pos, int n);


void fill_table(std::vector<std::vector<float>> &y, std::vector<float> &x, int pos, int n);


void print_table(std::vector<std::vector<float>> &y, std::vector<float> &x, int len_x);

#endif // FUNCTIONS_H
