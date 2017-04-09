#include "functions.h"


//main function
float f(float x) {
    return sin((3.14 / 6) * x);
}

//reserve function
float f2(float x) {
    return x*x - 3;
}

//find optimal beginning of tuple of points
int position(std::vector<float> array, int len, int n, float val) {

    for (int i = 0; i < len; ++i) {

        if (array[i] > val) {

            int half_n = n / 2;
            int uneven = n % 2;

            if ((i < half_n) || (uneven && (i < half_n + 1))) {
                return 0;
            }
            else if ((len - i < half_n) || (uneven && (len  - i < half_n + 1))) {
                return len - n;
            }

            if (!uneven) {
                return i - half_n;
            }

            else {

                float dr = array[i] - val;
                float dl = val - array[i - 1];

                if (dr <= dl) {
                    return i - half_n;
                }
                else {
                    return i - half_n - 1;
                }
            }

        }
    }
    return -1;
}

float calculate_result(std::vector<std::vector<float>> &y, std::vector<float> &x, float search_point, int pos, int n) {

    float result = 0;
    for (int j = 0; j < n; ++j) {
        float buf_res = y[j][pos];
        for (int k = 0; k < j; ++k) {
            buf_res *= (search_point - x[pos + k]);
        }
        result += buf_res;
    }

    return result;
}

void fill_table(std::vector<std::vector<float>> &y, std::vector<float> &x, int pos, int n) {

    for (int i = 1; i < n; ++i) {
        int k = i + pos;
        for(int j = pos; j < n + pos - i; ++j) {
            y[i][j]=(y[i-1][j+1]-y[i-1][j]) / (x[k]- x[j]);
            k++;
        }
    }
}

void print_table(std::vector<std::vector<float>> &y, std::vector<float> &x, int len_x) {

    printf("\nTABLE:\n");
    for (int i = 0; i < len_x; ++i) {
        printf("X[%d]: %5.2f\tY[%d]: %5.2f\n", i, x[i], i, y[0][i]);
    }
    printf("\n");
}
