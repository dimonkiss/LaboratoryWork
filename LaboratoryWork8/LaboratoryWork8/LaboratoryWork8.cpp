#include <iostream>
#include <cmath>

using namespace std;

// Функція, що обчислює значення f(x)
double f(double x) {
    return 3 * x - cos(x) - 1;
}

// Похідна функції f(x)
double df(double x) {
    return 3 + sin(x);
}

// Метод Ньютона для знаходження кореня
double newtonMethod(double a, double b, double epsilon) {
    double x0 = (a + b) / 2; // Початкове наближення
    double x1;

    do {
        x1 = x0 - f(x0) / df(x0);
        x0 = x1;
    } while (abs(f(x1)) > epsilon);

    return x1;
}

// Метод дотичних для знаходження кореня
double secantMethod(double a, double b, double epsilon) {
    double x0 = (a + b) / 2; // Початкове наближення
    double x1 = x0 - f(x0) / df(x0);
    double x2;

    do {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
    } while (abs(f(x2)) > epsilon);

    return x2;
}
void InsertCheck(double& number) {
    bool validInput = false;
    do {
        if (cin >> number) {
            validInput = true;
        }
        else {
            cout << "Incorect input. Try again." << endl;
            cin.clear(); // Очищаємо стан помилки вводу
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Видаляємо некоректний ввід з буфера
        }
    } while (!validInput);
}
int main() {
    setlocale(LC_ALL, "Ukrainian");

    double a, b, epsilon;
    double (*methodPtr)(double, double, double);
    methodPtr = newtonMethod;
    cout << "1. Задайте a і b для інтервалу [a, b]: " << endl;
    cout << "Введіть а: ";
    InsertCheck(a);
    cout << "Введіть b: ";
    InsertCheck(b);

    cout << "2. Введіть точність обчислення (типу до сотих з 1 (0.01)): ";
    InsertCheck(epsilon);

    double root = methodPtr(a,b,epsilon);
    methodPtr = secantMethod;
    // Розв'язок методом дотичних
    double rootSecant = methodPtr(a, b, epsilon);

    cout << "3. Корені рівняння 3x - cos(x) - 1 = 0:" << endl;
    cout << "Метод Ньютона: x = " << root  << endl;
    cout << "Метод Дотичних: x = " << rootSecant << endl;

    // Перевірка правильності коренів
    cout << "4. Перевірка правильності:" << endl;
    cout << "f(" << root << ") = " << 3*root - cos(root) - 1 << endl;
    cout << "f(" << rootSecant << ") = " << 3 * rootSecant - cos(rootSecant) - 1 << endl;

    // Визначення похибки
    double error = abs((3 * root - cos(root) - 1) - (3 * rootSecant - cos(rootSecant) - 1));
    cout << "5. Похибка між методами: " << error << endl;

    return 0;
}

