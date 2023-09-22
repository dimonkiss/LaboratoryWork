#include <iostream>
#include <cstring>
#include <cctype>
#include <locale.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");
    char firstString[100];
    char secondString[100];

    cout << "Введіть перший рядок символів: ";
    cin.getline(firstString, sizeof(firstString));

    cout << "Введіть другий рядок символів: ";
    cin.getline(secondString, sizeof(secondString));

    // Перевірка на однакову довжину
    if (strlen(firstString) != strlen(secondString)) {
        cout << "Помилка: Рядки мають різну довжину." << endl;
        return 1;
    }

    // Обчислення ключа шифру
    int key = tolower(secondString[0]) - tolower(firstString[0]);

    // Зашифрування першого рядка
    for (int i = 0; i < strlen(firstString); i++) {
        if (isalpha(firstString[i])) {
            char base = islower(firstString[i]) ? 'a' : 'A';
            firstString[i] = ((firstString[i] - base + key + 26) % 26) + base;
        }
    }

    // Порівняння зашифрованого рядка з другим рядком
    if (strcmp(firstString, secondString) == 0) {
        cout << "Другий рядок є шифрованим першого з ключем " << key << "." << endl;
    }
    else {
        cout << "Другий рядок не є шифрованим першого." << endl;
    }

    return 0;
}
