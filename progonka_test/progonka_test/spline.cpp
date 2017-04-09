#include "spline.h"


void progonka (std::vector<float>& x_array, std::vector<float>& y_array, std::vector<coef>& coef_table)
{
    std::vector<progon_coef> progon_table;
    progon_table.resize(coef_table.size());

    progon_table[1].ksi = progon_table[1].eta = 0;
    for (size_t i = 2; i < x_array.size(); i++)
    {
        float A = x_array[i - 1] - x_array[i - 2];
        float B = -2 * (x_array[i] - x_array[i - 2]);
        float D = x_array[i] - x_array[i - 1];
        float F = (-3) * ((y_array[i] - y_array[i - 1]) / D - (y_array[i - 1] - y_array[i - 2]) / A);

        progon_table[i+1].ksi = D  / (B - A * progon_table[i].ksi);
        progon_table[i+1].eta = (F + A * progon_table[i].eta) / (B - A * progon_table[i].ksi);
    }

    size_t buf_pos = x_array.size() - 1;
    double dx = x_array[buf_pos] - x_array[buf_pos - 1];

    coef_table[buf_pos].c = 0;
    coef_table[buf_pos].a = y_array[buf_pos - 1];
    coef_table[buf_pos].d = (coef_table[buf_pos+1].c - coef_table[buf_pos].c) / (3 * dx);
    coef_table[buf_pos].b = (y_array[buf_pos] - y_array[buf_pos-1]) / dx - dx * (coef_table[buf_pos+1].c + 2 * coef_table[buf_pos].c) / 3;

    for (int i = x_array.size() - 2; i > 0; i--)
    {
        dx = x_array[i] - x_array[i-1];
        coef_table[i].c = progon_table[i+1].ksi * coef_table[i+1].c + progon_table[i+1].eta;
        coef_table[i].a = y_array[i-1];
        coef_table[i].d = (coef_table[i+1].c - coef_table[i].c) / (3 * dx);
        coef_table[i].b = (y_array[i] - y_array[i-1]) / dx - dx * (coef_table[i+1].c + 2 * coef_table[i].c) / 3;
    }
}

size_t find_pos(const float x, std::vector<float>& vector)
{
    size_t pos = 0;

    while (pos < vector.size() && vector[pos] < x) {
        pos++;
    }

    return  pos;
}


float interp_spline(const float x, std::vector<float>& x_array, std::vector<coef>& coef_table)
{
    size_t pos = find_pos(x, x_array);
    double dx = x - x_array[pos - 1];
    return coef_table[pos].a + coef_table[pos].b * dx + coef_table[pos].c * dx * dx + coef_table[pos].d * dx * dx * dx;
}
