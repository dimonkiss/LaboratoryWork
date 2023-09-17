#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функція для генерації псевдовипадкових чисел у заданому діапазоні
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Перевірка
void InsertCheck(int& number) {
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

//Функція для вставлення чисел в масив
void InsertArray(int n, int* arr, int choice) {
    if (choice == 1) {
        cout << "Введіть " << n << " цілих чисел:" << endl;
        for (int i = 0; i < n; i++) {
            InsertCheck(arr[i]);
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
            arr[i] = generateRandomNumber(minVal, maxVal);
        }
    }
    else {
        cout << "Некоректний вибір. Програма завершує роботу." << endl;
        delete[] arr; // Звільнення пам'яті перед виходом з програми
        exit(0);
    }
}

//Функція для виведення масиву
void PrintArray(int* arr, int size) {
    cout << "=======================================================================================================" << endl;
    
    for (int i = 0; i <size ; ++i) {
        cout << "\t" << arr[i];
    }

    cout << "\n=======================================================================================================" << endl;
}

// Функція для сортування масиву вставками
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Функція для знаходження та виводу кількості кожного унікального значення в масиві
void countUniqueValues(int arr[], int n) {
    // Сортуємо масив
    insertionSort(arr, n);

    int uniqueCount = 0; // Лічильник унікальних значень

    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            uniqueCount++;
        }
    }

    // Створюємо масиви для зберігання унікальних значень та їх кількостей
    int* uniqueArr = new int[uniqueCount];
    int* countArr = new int[uniqueCount];
    int currentIndex = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            uniqueArr[currentIndex] = arr[i];
            countArr[currentIndex] = 1;
            currentIndex++;
        }
        else {
            countArr[currentIndex - 1]++;
        }
    }

    // Виводимо кількість кожного унікального значення
    cout << "Кількість кожного унікального значення:" << endl;
    for (int i = 0; i < uniqueCount; i++) {
        cout << "Значення " << uniqueArr[i] << ": " << countArr[i] << " разів" << endl;
    }

    // Знаходимо максимальну кількість входжень
    int maxCount = countArr[0];
    for (int i = 1; i < uniqueCount; i++) {
        if (countArr[i] > maxCount) {
            maxCount = countArr[i];
        }
    }

    // Виводимо всі значення, які мають максимальну кількість входжень
    cout << "Значення, які найбільше трапляються в масиві:" << endl;
    for (int i = 0; i < uniqueCount; i++) {
        if (countArr[i] == maxCount) {
            cout << "Значення " << uniqueArr[i] << " (зустрічається " << maxCount << " разів)" << endl;
        }
    }

    // Звільнюємо виділену пам'ять
    delete[] uniqueArr;
    delete[] countArr;
}


int main() {
    cout << "lab6.1\tKisil Dmytro\tIPZ11/2\t14\n\n" << endl;
    setlocale(LC_ALL, "Ukrainian");
    cout << "Завдання 1. Використання базових операцій обробки одновимірних масивів" << endl;
    cout << "\tПередбачити вибір способу створення масиву:" << endl;
    cout << "\t- введення з клавіатури;" << endl;
    cout << "\t- заповнення масиву псевдовипадковими числами." << endl;
    cout << "\tУмови завдання 1 подані у таблиці 6.1." << endl;
    cout << "Забороняється використовувати бібліотеку стандартних шаблонів STL і шаблон вектору std::vector" << endl;
    cout << "14.1. Створити одновимірний масив цілих чисел, кількість елементів якого ввести з клавіатури. Значення елементів можуть повторюватися. Передбачити меню вибору способу створення масиву: введення з клавіатури або генерація псевдовипадкових чисел. Вивести на екран кількість входжень до масиву значень кожного з його елементів, індекс та значення елемента, яке повторюється найбільшу кількість разів.\n\n" << endl;
    // Ініціалізуємо генератор випадкових чисел
    srand(time(0));
    
    

    int n;
    cout << "Введіть кількість елементів масиву: ";
    InsertCheck(n);

    int* arr = new int[n]; // Створюємо динамічний масив

    int choice;
    cout << "Виберіть спосіб заповнення масиву (1 - введення з клавіатури, 2 - генерація псевдовипадкових чисел): ";
    InsertCheck(choice);

   //Заповнюємо масив
    InsertArray(n,arr,choice);

    PrintArray(arr, n);

    countUniqueValues(arr,n);





   
    // Звільнюємо виділену пам'ять
    delete[] arr;


    return 0;
}

