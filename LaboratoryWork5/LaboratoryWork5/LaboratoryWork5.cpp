
#include <iostream>
using namespace std;
void printOddNumbersReverse(int n) {
    // Базовий випадок: якщо n менше або дорівнює 0, нічого не робити
    if (n <= 0) {
        return;
    }

    // Перевірка, чи поточне n є непарним числом
    if (n % 2 != 0) {
        std::cout << n << " ";
    }

    // Рекурсивний виклик для чисел, менших за поточне n
    printOddNumbersReverse(n - 1);
}

long long int iterativePowMod(long long int b, long long int p, long long int m) {
    long long int result = 1;
    b = b % m; // Зменшуємо b до значення, яке менше за m

    while (p > 0) {
        if (p % 2 == 1) {
            result = (result * b) % m;
        }
        b = (b * b) % m;
        p /= 2;
    }

    return result;
}
long long int recursivePowMod(long long int b, long long int p, long long int m) {
    if (p == 0) {
        return 1;
    }
    else if (p % 2 == 0) {
        long long int half_pow = recursivePowMod(b, p / 2, m) % m;
        return (half_pow * half_pow) % m;
    }
    else {
        long long int half_pow = recursivePowMod(b, p / 2, m) % m;
        return (b * ((half_pow * half_pow) % m)) % m;
    }
}
void InsertCheck(int& number) {
    bool validInput = false;
    do {
        if (cin >> number and number > 0 and number < 10) {
            validInput = true;
        }
        else {
            cout << "Incorect input. Try again." << endl;
            cin.clear(); // Очищаємо стан помилки вводу
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Видаляємо некоректний ввід з буфера
        }
    } while (!validInput);
}
void InsertCheck(long long int& number) {
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
int main()
{
    setlocale(LC_ALL, "Ukrainian");
    cout << "lab5\tKisil Dmytro\tIPZ11/2\t14\n\n" << endl;

    //1
    //cout << "Увести з клавіатури три натуральних числа b, p, m. Обчислити значення виразу , де операція mod обраховує остачу від ділення цілих чисел. Для зведення в степень b^p з логарифмічною складностю O(log p) використати рекурентне співвідношення:" << endl;
    //cout << "\t\t{1, p=0" << endl;
    //cout << "pow(b,p)= \t{pow(pow(b,p/2),2), p - парне" << endl;
    //cout << "\t\t{b* pow(pow(b,p/2),2), p- непарне" << endl;
    //long long int b, p, m;
    //cout << "Введіть число b: ";
    //InsertCheck(b);
    //cout << "Введіть число p: ";
    //InsertCheck(p);
    //cout << "Введіть число m: ";
    //InsertCheck(m);
    //cout << "Ітеративно: " << iterativePowMod(b, p, m) << endl;
    //cout << "Рекурсивно: " << recursivePowMod(b, p, m) << endl;

    //Набір 1
    //b = 7
    //p = 4
    //m = 9
    //res = 7
    
    //Набір 2
    //b = 10
    //p = 6
    //m = 3
    //res = 1

    //Набір 
    //b = 13
    //p = 4
    //m = 9
    //res = 4



    //2
    //int n;
    //cout << "Увести з клавіатури натуральне число n. Використовуючи рекурсивну функцію, визначити і вивести всі непарні (парні) числа з послідовності цілих чисел від n до 0, зберігаючи їх порядок." << endl;
    //cout << "Введіть натуральне число n: ";
    //InsertCheck(n);



    //cout << "Непарні числа від " << n << " до 1: ";
    //printOddNumbersReverse(n);
    //cout << endl;

    return 0;
}

