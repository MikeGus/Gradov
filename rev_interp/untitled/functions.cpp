#include "functions.h"
#include "utils.h"

//func1
float f1(float x, float y) {
    return exp(pow(x,3) - y) - pow(x,3) * (pow(x, 3) - 2 * y - 2) - y * y - 2 * y - 2;
}

//func2
float f2(float x, float y) {
    return exp(2 * log(x) - y) + y * exp(-y) - exp(x * x) * log(x * x + y);
}

float f(float x, float y) {
    return f2(x, y) - f1(x, y);
}

float binary_search(float x, float (*func)(float x, float y), float accurancy) {

    float y_b = y_bottom;
    float y_t = y_top;

    while(func(x, y_t) * func(x, y_b) > 0) {
        y_t += 20;
        y_b -= 20;
    }

    float y_m = (y_t + y_b) / 2;

    while(fabs(y_t - y_b) > fabs(y_m) * accurancy + accurancy) {
        if (func(x, y_m) * func(x, y_t) < 0) {
            y_b = y_m;
        }
        else {
            y_t = y_m;
        }
        y_m = (y_t + y_b) / 2;
    }

    return y_m;
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

void print_table(std::vector<float> &y1, std::vector<float> &y2, std::vector<float> &x, int len_x) {

    printf("\nTABLE:\n");
    for (int i = 0; i < len_x; ++i) {
        printf("X[%d]: %5.2f\tY1[%d]: %5.2f\tY2[%d]: %5.2f\tDY : %5.2f\n", i, x[i], i, y1[i], i, y2[i], y1[i] - y2[i]);
    }
    printf("\n");
}
