#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
unsigned long long factorial(double n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }

    return result;
}

double functionY1(double x) {
    double sum1 = 0;
    double sum2 = 0;

    for (int i = 0; i < 11; ++i) {

        sum1 += pow(-1, i) * pow(x + 2, 2 * i) / factorial(2 * i);
        
    }
    for (int i = 0; i < 11; ++i) {
        sum2 += pow(-1, i) * pow(pow(x,2), 2 * i) / factorial(2 * i);
    }
    return  pow(sum1,2) - sum2;
}
double functionY2(double x) {
    double sum1 = 0;
    double sum2 = 0;

    for (int i = 0; i < 11; ++i) {

        sum1 += pow(-1, i) * pow(x + x, 2 * i) / factorial(2 * i);
        
    }
    for (int i = 0; i < 11; ++i) {
        sum2 += pow(-1, i) * pow(x, 2 * i) / factorial(2 * i);
    }
    return sum1 * sum2 ;
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
void InsertCheck(int& number) {
    bool validInput = false;
    do {
        if (cin >> number and number > 0) {
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
    //1
    cout << "lab4\tKisil Dmytro\tIPZ11/2\t14\n\n" << endl;
    setlocale(LC_ALL,"Ukrainian");
    //double min_x, max_x, step, accuracy;

    //// Зчитуємо введені користувачем значення
    //cout << "Введіть мінімальне значення x: ";
    //InsertCheck(min_x);

    //cout << "Введіть максимальне значення x: ";
    //InsertCheck(max_x);

    //cout << "Введіть крок: ";
    //InsertCheck(step);

    //// Виводимо заголовок таблиці
    //cout << setw(20) << "Значення x" << setw(20) << "Значення y" << setw(30) << "Стандартне значення y" << setw(20) << "Похибка" << endl;
    //cout << "----------------------------------------------------------------------------------------------" << endl;
    //
    //    // Обчислюємо значення функцій та похибку для кожного x
    //    for (double x = min_x; x <= max_x; x += step) {
    //        double y = functionY1(x);
    //        double standard_y =  pow(cos(2+x),2) - cos(x*x);
    //        double error = abs(y - standard_y);

    //        // Виводимо результати для функції y1
    //        if (x<=0 and x>=-3 ) {
    //            cout << setw(20) << x  << setw(20) << y  << setw(20) << standard_y << setw(20) << error << endl;
    //        }

    //    }



    //    for (double x = min_x; x <= max_x; x += step) {
    //        double y = functionY2(x);
    //        double standard_y = cos(x + x) * cos(x) ;
    //        double error = abs(y - standard_y);

    //        // Виводимо результати для функції y2
    //        if (x <= 3 and x >= 2) {
    //            cout << setw(20) << x << setw(20) << y << setw(20) << standard_y << setw(20) << error << endl;
    //        }

    //    }
    //2
    cout << "У трьох видах спорту стартує n осіб. Визначити, скільки існує можливих результатів, якими можуть закінчитися змагання, якщо кожна людина стартує в одному, довільно обраному виді спорту? Під результатом змагання розуміється розподіл місць для всіх спортсменів, що стартують в кожному виді." << endl;
    int champs;
    cout << "Введіть кількість учасників: ";
    InsertCheck(champs);
    long long quantity = 3;
    if (champs == 1) {
        cout << "Він не може сам з собою змагатись" << endl;
    }
    else {
        for (int i = 2; i <= champs; ++i) {
            quantity *= i;
        }
        cout << "Кількість варіантів: " << quantity;
    }

    return 0;
}



