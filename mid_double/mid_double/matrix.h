#ifndef MATRIX_H
#define MATRIXH
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>

void fill_matrix(std::vector<std::vector<float>>& matrix, std::vector<float>& coefs, std::vector<float>& x, \
                 std::vector<float>& y, std::vector<float>& ro);
int gaussmethod(std::vector<float>& result, std::vector<std::vector<float>>& matrix, std::vector<float>& coefs);

void print_matrix(std::vector<std::vector<float>>& matrix, std::vector<float>& coefs);

#endif // MATRIX_H
