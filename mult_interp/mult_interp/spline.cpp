#include "spline.h"

size_t progonka(std::vector<float> result, std::vector<progon_coef>& progon_table, std::vector<coef>& table)
{
    //clearing workspace
    result.clear();
    progon_table.clear();

    size_t size = table.size();

    if (size == 0) {
        return size;
    }
    if (size == 1){
        float buffer =  -table[0].f / table[0].a;
        result.push_back(buffer);
        return size;
    }


    progon_coef buffer;

    //forward pass
    buffer.nu = table[0].f / table[0].a;
    buffer.psi = - table[0].b / table[0].a;
    progon_table.push_back(buffer);

    for (size_t i = 1; i < size - 1; ++i) {
        buffer.psi = table[i].d / (table[i].b - table[i].a * progon_table[i - 1].psi);
        buffer.nu = (table[i].a * progon_table[i - 1].nu + table[i].f) / (table[i].b - table[i].a * progon_table[i - 1].psi);
        progon_table.push_back(buffer);
    }

    //reverse pass
    float buffer_res = (table[size - 1].f - table[size - 1].b * progon_table[size - 2].nu) / \
            (table[size - 1] + table[size - 1].b * progon_table[size - 2].psi);
    result.push_back(buffer_res);

    for (int i = size - 2; i >= 0; --i) {
        buffer_res = progon_table[i].psi * result[size - 2 - i] + progon_table[i].nu;
        result.push_back(buff_res);
    }

    return size;
}

std::vector<float> progonka(std::vector<std::vector<float>>& table, std::vector<float>& nu, std::vector<float>& psi)
{
    /*
    size_t size = table.size();
    float K1 = table[0][0];
    float M1 = table[0][1];
    float P1 = table[0][size];

    float nu1 = P1 / K1;
    float psi1 = - M1 / K1;

    nu.push_back(nu1);
    psi.push_back(psi1);

    for (size_t i = 1; i < size - 1; ++i) {
        float Ai = table[i][i - 1];
        float Bi = table[i][i];
        float Di = table[i][i + 1];
        float Fi = table[i][size];

        float psii = Di / (Bi - Ai * psi[i - 1]);
        psi.push_back(psii);
        float nui = (Ai * nu[i - 1] + Fi) / (Bi - Ai * psi[i - 1]);
        nu.push_back(nui);
    }
    */

    std::vector<float> result;
    float Kn = table[size - 1][size - 2];
    float Mn = table[size - 1][size - 1];
    float Pn = table[size - 1][size];

    float Un = (Pn - Mn * nu[size - 2]) / (Kn + Mn * psi[size - 2]);
    result.push_back(Un);

    for (size_t i = size - 2; i >= 0; --i) {
        float Ui = psi[i] * result[size - 2 - i] + nu[i];
        result.push_back(Ui);
    }

    std::vector<float> real_result;
    for (auto it = result.rbegin(); it < result.rend(); ++it) {
        real_result.push_back(*it);
    }

    return real_result;
}
