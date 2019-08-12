// Лабораторная работа №3
// Разработка программ, реализующих алгоритмы ветвлений и циклические алгоритмы
// Вилкин М. А., ИКВТ-83, вариант 3

#include <iostream>
#include <cmath>

using namespace std;

double func(double a, double b, double x) {
    if (a < 0)
        return NAN; //НЕ ЧИСЛО
    if ((sqrt(a) + exp(-b * x)) == 0)
        return NAN; //НЕ ЧИСЛО
    return (a + b * exp(x)) / (sqrt(a) + exp(-b * x));
}

void tabulation(double a, double b) {
    double res, x_min = -2;
    double y_min = func(a, b, x_min);

    for (double x = -2; x <= 2; x += 0.5) {
        res = func(a, b, x);
        if (y_min > res) {
            y_min = res;
            x_min = x;
        }

        if(isnan(res)) //НЕ ЧИСЛО
            cout << "\tx =\t" << x << "\t=>\tЛОЖь" << endl;
        else
            cout << "\tx =\t" << x << "\t=>\tf(x) = " << res << endl;
    }

    cout << endl << "________________________________________________" << endl;
    cout << "\tx_min =\t" << x_min << "\t=>\tf(x_min) = " << y_min << endl;
}


int main() {
    setlocale(0, "");

    cout << "Введите a, b, x:" << endl;
    double a, b, x;
    cin >> a >> b >> x;

    double result = func(a, b, x);

    if (isnan(result)) { //НЕ ЧИСЛО
        cout << "Невозможно вычислить на множестве действительных чисел." << endl;
    }
    else
        cout << result << endl;

    cout << "Введите a, b для табуляции функции:" << endl;
    cin >> a >> b;
    tabulation(a, b);

    return 0;
}
