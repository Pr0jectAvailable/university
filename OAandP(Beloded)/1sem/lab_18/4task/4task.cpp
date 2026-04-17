#include <iostream>
#include <cmath>

using namespace std;

double f1(double x) {
    return 5 * x - 1 + pow(x, 3);
}

double f2(double x) {
    return pow(x, 2) + 1.0 / x;
}

double count_ff(double (*f)(double), double a, double b, double eps, int& iterations) {
    double x;
    iterations = 0;

    if (f(a) * f(b) >= 0) {
        cout << "На интервале " << a << ", " << b << " нет корня или несколько корней" << endl;
        return NAN;
    }

    while (fabs(b - a) > eps) {
        iterations++;
        x = (a + b) / 2.0;

        if (f(x) == 0.0) {
            return x;
        }
        else if (f(a) * f(x) < 0) {
            b = x;
        }
        else {
            a = x;
        }
    }

    return (a + b) / 2.0;
}

int main() {
    setlocale(LC_ALL, "RU-ru");

    double eps = 0.001;
    int attempts, attempts2;

    cout << "точность e: " << eps << endl << endl;

    cout << "1) уравнение: 5x - 1 + x^3 = 0" << endl;

    cout << "Отделение корней для первого уравнения:" << endl;
    cout << "f(-2) = " << f1(-2) << endl;
    cout << "f(-1) = " << f1(-1) << endl;
    cout << "f(0) = " << f1(0) << endl;
    cout << "f(1) = " << f1(1) << endl;

    double a1 = 0.0, b1 = 1.0;
    cout << "интервал: " << a1 << ", " << b1  << endl;

    double main = count_ff(f1, a1, b1, eps, attempts);

    if (!isnan(main)) {
        cout << "корень: x = ";
        printf("%.5f\n", main);
        cout << "Значение функции в корне: f(x) = ";
        printf("%.5f", f1(main));
        cout << endl << "итераций: " << attempts <<endl;
    }

    cout << endl << "----------------------------------------" << endl << endl;

    cout << "2) Уравнение: x^2 + 1/x = 0" << endl;

    cout << "Отделение корней для второго уравнения:" << endl;
    cout << "f(-1.5) = " << f2(-1.5) << endl;
    cout << "f(-1.2) = " << f2(-1.2) << endl;
    cout << "f(-1) = " << f2(-1) << endl;
    cout << "f(-0.8) = " << f2(-0.8) << endl;
    cout << "f(-0.5) = " << f2(-0.5) << endl;

    double a2 = -1.2, b2 = -0.8;
    cout << "интервал: " << a2 << ", " << b2 << endl;

    double main2 = count_ff(f2, a2, b2, eps, attempts2);

    if (!isnan(main2)) {
        cout << "корень: x = ";
        printf("%.5f\n", main2);
        cout << "Значение функции в корне: f(x) = ";
        printf("%.5f", f2(main2));
        cout << endl << "итераций: " << attempts2 << endl;
    }

    return 0;
}

//В соответствии со своим вариантом отделить корни двух уравнений
//и вычислить их методом дихотомии для исходных дан - ных из таблицы, приведенной ниже