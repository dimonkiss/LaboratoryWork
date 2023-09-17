#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int start = 0;
void InsertCheck(int& number) {
    bool validInput = false;
    
    do {
        if (cin >> number and start!=0) {
            validInput = true;
        }
        else if (start == 0 and number >=4) {
            validInput = true;
        }
        else {
            cout << "Incorect input. Try again." << endl;
            cin.clear(); // Очищаємо стан помилки вводу
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Видаляємо некоректний ввід з буфера
        }
    } while (!validInput);
    ++start;
}

void InsertCheckChoice(int& number) {
    bool validInput = false;
    do {
        if (cin >> number and (number == 1 or number == 2)) {
            validInput = true;
        }
        else {
            cout << "Incorect input. Try again." << endl;
            cin.clear(); // Очищаємо стан помилки вводу
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Видаляємо некоректний ввід з буфера
        }
    } while (!validInput);
}

//Функція для вставлення чисел в масив
void InsertMatrix(int n, int**& arr, int choice) {
    if (choice == 1) {
        cout << "Введіть " << n*n << " цілих чисел:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                InsertCheck(arr[i][j]);
            }
        }
    }
    else if (choice == 2) {
        int minVal, maxVal;
        cout << "Введіть діапазон генерації псевдовипадкових чисел (мінімальне та максимальне значення): " << endl;
        cout << "Введіть мінімальне значення :";
        InsertCheck(minVal);
        cout << "Введіть максимальне значення :";
        InsertCheck(maxVal);


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = generateRandomNumber(minVal, maxVal);
            }
        }
    }

}

 //Функція для виведення матриці на екран
void printMatrix(int** matrix, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void diviseMatrix(int**& matrix, int m) {
  
    for (int i = 0; i < m / 2; i++) {
        for (int j = 0; j < m / 2; j++) {
            swap(matrix[i][j], matrix[i + m / 2][j + m / 2]);
        }
    }
    for (int i = 0; i < m/2; i++) {
        for (int j = 0; j < m/2; j++) {
            swap(matrix[i + m/2][j], matrix[i][j + m / 2]);
        }
    }
}

int sumOfQuadrant(int** matrix, int m, int rowStart, int rowEnd, int colStart, int colEnd) {
    int sum = 0;
    for (int i = rowStart; i < rowEnd; i++) {
        for (int j = colStart; j < colEnd; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

void findMaxQuadrantSum(int** matrix, int m) {
    // Знаходження сум для кожної чверті матриці
    int sum1 = sumOfQuadrant(matrix, m, 0, m / 2, 0, m / 2);
    int sum2 = sumOfQuadrant(matrix, m, 0, m / 2, m / 2, m);
    int sum3 = sumOfQuadrant(matrix, m, m / 2, m, 0, m / 2);
    int sum4 = sumOfQuadrant(matrix, m, m / 2, m, m / 2, m);

    // Знаходження максимальної суми
    int maxSum = max(max(sum1, sum2), max(sum3, sum4));
    int quadrant = 0;

    if (maxSum == sum1) {
        quadrant = 1;
    }
    else if (maxSum == sum2) {
        quadrant = 2;
    }
    else if (maxSum == sum3) {
        quadrant = 3;
    }
    else {
        quadrant = 4;
    }

    // Виведення результатів
    cout << "Сума в першій чверті: " << sum1 << endl;
    cout << "Сума в другій чверті: " << sum2 << endl;
    cout << "Сума в третій чверті: " << sum3 << endl;
    cout << "Сума в четвертій чверті: " << sum4 << endl;
    cout << "Найбільша сума в чверті " << quadrant << ": " << maxSum << endl;
}


int main() {

    srand(time(0));
    setlocale(LC_ALL, "Ukrainian");
    cout << "lab7.1\tKisil Dmytro\tIPZ11/2\t14\n\n" << endl;
    cout << "14.1. Створити квадратну матрицю, розмірність m>4 якої ввести з клавіатури. Передбачити меню вибору способу створення матриці: введення з клавіатури або генерація псевдовипадкових додатніх та від'ємних чисел. Переставляючи блоки вхідної матриці відповідно до малюнку,отримати нову матрицю.Знайти найбільшу суму елементів серед сум в кожній з четвертей матриці.Вивести на екран вхідну матрицю, матрицю після переставлення блоків, значення сум в кожній з четвертей та найбільшу суму із вказівкою номера четверті.\n\n" << endl;
    int m;
    cout << "Введіть розмірність матриці (m > 4): ";
    InsertCheck(m);

    int choice;
    cout << "Виберіть спосіб заповнення масиву (1 - введення з клавіатури, 2 - генерація псевдовипадкових чисел): ";
    InsertCheckChoice(choice);

    int** matrix = new int* [m];
    for (int i = 0; i < m; ++i) {
        matrix[i] = new int[m]; // Для кожного вказівника створюємо рядок матриці
    }
    InsertMatrix(m,matrix,choice);

    cout << "Початкова матриця:" << endl;
    printMatrix(matrix, m);

    diviseMatrix(matrix, m);

    cout << "Матриця після зміни: " << endl;
    printMatrix(matrix,m);

    findMaxQuadrantSum(matrix,m);

    delete[] matrix;

    return 0;
}


