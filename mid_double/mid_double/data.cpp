#include "data.h"

#include "function.h"

void get_num_of_intervals(size_t& intervals)
{
    std::cout << "Enter number of intervals: ";
    std::cin >> intervals;
}

void get_borders(float& begin, float& end)
{
    std::cout << "Enter borders: ";
    std::cin >> begin >> end;
    if (begin > end) {
        std::swap(begin, end);
    }
}

void fill_x(std::vector<float>& x, float begin, float end, size_t intervals)
{
    x.clear();
    float step = (end - begin) / intervals;
    float val = begin;
    for (size_t i = 0; i <= intervals; ++i) {
        x.push_back(val);
        val += step;
    }
}

void fill_x(std::vector<float>& x, std::istream& input)
{
    x.clear();
    size_t intervals = 0;
    input >> intervals;
    float val = 0;
    for (size_t i = 0; i < intervals; ++i) {
        input >> val;
        x.push_back(val);
    }
}

void fill_x(std::vector<float>& result, std::vector<float>& source, float (*func)(float point))
{
    result.clear();
    for (auto val : source) {
        result.push_back(func(val));
    }
}

void print_data(std::vector<float>& x, std::vector<float>& y, std::vector<float>& ro, std::vector<float>& coefs)
{
    std::cout << std::setprecision(3);
    std::cout << std::fixed;
    std::cout << std::setfill('-') << std::setw(40) << "-" << std::endl;
    std::cout << "Result: " << std::endl;
    std::cout << std::setfill('-') << std::setw(40) << "-" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::setw(8) << 'x'<< std::setw(8) << 'y' << std::setw(8) << "ro" << std::setw(8) << "fi" << \
              std::setw(8) << 'k' << std::endl;
    for (size_t i = 0; i < x.size(); ++i) {
        float dy = calculate_fi(coefs, x[i] + 0.01) - calculate_fi(coefs, x[i] - 0.01);
        float dx = 0.02;
        float k = dy / dx;
        std::cout << std::setw(8) << x[i] << std::setw(8) << y[i] << std::setw(8) << ro[i] << std::setw(8) \
                  << calculate_fi(coefs, x[i]) << std::setw(8) << k << std::endl;
    }
    std::cout << std::setfill('-') << std::setw(40) << "-" << std::endl;
    std::cout << std::setfill(' ');
}

void print_data(std::vector<float>& x, std::vector<float>&y, std::vector<float>& ro)
{
    std::cout << std::setprecision(3);
    std::cout << std::fixed;
    std::cout << std::setfill('-') << std::setw(40) << "-" << std::endl;
    std::cout << "Initial data: " << std::endl;
    std::cout << std::setfill('-') << std::setw(40) << "-" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::setw(8) << 'x'<< std::setw(8) << 'y' << std::setw(8) << "ro" << std::endl;
    for (size_t i = 0; i < x.size(); ++i) {
        std::cout << std::setw(8) << x[i] << std::setw(8) << y[i] << std::setw(8) << ro[i] << std::endl;
    }
    std::cout << std::setfill('-') << std::setw(40) << "-" << std::endl;
    std::cout << std::setfill(' ');
}
