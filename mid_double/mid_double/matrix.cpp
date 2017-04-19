#include  "matrix.h"

void fill_matrix(std::vector<std::vector<float>>& matrix, std::vector<float>& coefs, std::vector<float>& x, \
                 std::vector<float>& y, std::vector<float>& ro, size_t size)
{
    matrix.clear();
    coefs.clear();
    matrix.resize(size);
    coefs.resize(size);

    for (size_t i = 0; i < size; ++i) {
        matrix[i].resize(size);
    }

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            float sum = 0;
            for (size_t k = 0; k < x.size(); ++k) {
                sum += ro[k] * pow(x[k], i + j);
            }
            matrix[i][j] = sum;
        }
        float sum = 0;
        for (size_t k = 0; k < x.size(); ++k) {
            sum += ro[k] * y[k] * pow(x[k], i);
        }
        coefs[i] = sum;
    }
}

int gaussmethod(std::vector<float>& result, std::vector<std::vector<float>>& matrix, std::vector<float>& coefs)
{
    result.clear();
    size_t size = matrix.size();
    result.resize(size);

    //forward
    for (size_t i = 0; i < size; ++i) {
        if (matrix[i][i] == 0) {
            bool swapped = false;
            for (size_t j = i + 1; j < size; ++j) {
                if (matrix[j][i] != 0) {
                    std::swap(matrix[i], matrix[j]);
                    swapped = true;
                    break;
                }
            }
            if (!swapped) {
                return 1;
            }
        }
        for (size_t j = i + 1; j < size; ++j) {
            if (matrix[j][i] == 0) {
                continue;
            }
            float coef = matrix[i][i] / matrix[j][i];
            for (size_t m = i; m < size; ++m) {
                matrix[j][m] *= coef;
                matrix[j][m] -= matrix[i][m];
            }
            coefs[j] *= coef;
            coefs[j] -= coefs[i];
        }
    }
    //backward
    for (int i = size - 1; i >= 0; --i) {
        float sum = 0;
        for (size_t j = i; j < size; ++j) {
            sum += matrix[i][j] * result[j];
        }
        result[i] = (coefs[i] - sum) / matrix[i][i];
    }

    return 0;
}

void print_matrix(std::vector<std::vector<float>>& matrix, std::vector<float>& coefs)
{
    std::cout << std::fixed;
    std::cout << std::setfill(' ');
    std::cout << std::setprecision(2);
    std::cout << "MATRIX:" << std::endl;
    for (size_t i = 0 ; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.size(); ++j) {
            std::cout << std::setw(8) << matrix[i][j] << " ";
        }
        std::cout << coefs[i] << std::endl;
    }
}
