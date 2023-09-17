
#include <iostream>
using namespace std;
int comparisons = 0;
int swaps = 0;
int comparisons_1 = 0;
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
void InsertCheckChoice(int& number) {
    bool validInput = false;
    do {
        if (cin >> number and (number==1 or number==2)) {
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

    for (int i = 0; i < size; ++i) {
        cout << "\t" << arr[i];
    }

    cout << "\n=======================================================================================================" << endl;
}

// Алгоритм блукаючого сортування (Stooge sort)
void stoogeSort(int arr[], int low, int high) {
    if (low >= high) return;

    if (arr[low] > arr[high]) {
        swap(arr[low], arr[high]);
        cout << "Swap: " << endl;
        swaps++;
        PrintArray(arr, high + 1);
    }
    comparisons++;
    if (high - low + 1 > 2) {
        int t = (high - low + 1) / 3;
        stoogeSort(arr, low, high - t);
        stoogeSort(arr, low + t, high);
        stoogeSort(arr, low, high - t);
    }
}

// Алгоритм бінарного пошуку з визначенням найближчих вузлів
void binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            found = true;
            comparisons_1++;
            // Знайдено позицію
            cout << "Елемент знайдено на позиції " << mid + 1 << endl;

            // Шукати подальше вліво
            int temp = mid - 1;
            while (temp >= 0 && arr[temp] == target) {
                comparisons_1++;
                cout << "Елемент знайдено на позиції " << temp+1 << endl;
                temp--;
            }

            // Шукати подальше вправо
            temp = mid + 1;
            while (temp < size && arr[temp] == target) {
                comparisons_1++;
                cout << "Елемент знайдено на позиції " << temp+1 << endl;
                temp++;
            }

            break;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
        comparisons_1++;
    }

    if (!found) {
        cout << "Елемент не знайдено у масиві." << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    cout << "lab6.2\tKisil Dmytro\tIPZ11/2\t14\n\n" << endl;
    cout << "Завдання 2. Алгоритми сортування та пошуку" << endl;
    cout << "\t- визначити ефективність методу сортування: кількість порівнянь та обмінів;" << endl;
    cout << "\t- визначити ефективність методу пошуку: кількість порівнянь;" << endl;
    cout << "\t- передбачити вибір режиму виведення результатів: або тільки відсортований масив, або з проміжними ітераціями." << endl;
    cout << "\tУмови завдання 2 подані в таблиці 6.1." << endl;
    cout << "Забороняється використовувати бібліотеку стандартних шаблонів STL і шаблон вектору vector" << endl;
    cout << "14.2. Створити одновимірний масив, кількість елементів якого ввести з клавіатури. Передбачити меню вибору способу створення масиву: введення з клавіатури або генерація псевдовипадкових чисел. Відсортувати масив за алгоритмом блукаючого сортування (Stooge sort) [1.14] та здійснити пошук в масиві за алгоритмом бінарного пошуку з визначенням найближчих вузлів [2.11]. Передбачити виведення проміжних результатів в процесі виконання ітерацій сортування масиву.\n\n" << endl;

    // Ініціалізуємо генератор випадкових чисел
    srand(time(0));

    int n;
    cout << "Введіть кількість елементів масиву: ";
    InsertCheck(n);

    int* arr = new int[n]; // Створюємо динамічний масив

    int choice;
    cout << "Виберіть спосіб заповнення масиву (1 - введення з клавіатури, 2 - генерація псевдовипадкових чисел): ";
    InsertCheckChoice(choice);

    //Заповнюємо масив
    InsertArray(n, arr, choice);

    PrintArray(arr, n);

    stoogeSort(arr, 0, n - 1);

    cout << "Відсортований масив: " << endl;
    PrintArray(arr, n);

    int target;
    cout << "\n\nВведіть число для пошуку: ";
    InsertCheck(target);
    cout << endl << endl;
    binarySearch(arr, n, target);


    cout << "\n\nСтатистика ефективності методу сортування: " << endl;
    cout << "Кількість порівнянь: " << comparisons << endl;
    cout << "Кількість обмінів: " << swaps << endl;
    cout << "\n\nСтатистика ефективності методу пошуку: " << endl;
    cout << "Кількість порівнянь: " << comparisons_1 << endl;
    return 0;



}


