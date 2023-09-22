#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream file("C:\\Users\\dkhpr\\Desktop\\LaboratoryWorks\\LaboratoryWork11\\LaboratoryWork11.2\\abonents.txt"); // Відкрити файл для читання

    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл" << endl;
        return 1; // Помилка відкриття файлу
    }

    string line;
    while (getline(file, line)) { // Прочитати кожен рядок у файлі
        size_t pos = line.find_last_of('\t'); // Знайти останню табуляцію
        if (pos != string::npos) {
            string last_value = line.substr(pos + 1); // Отримати підстроку після останньої табуляції
            cout << last_value << endl; // Вивести останнє значення в консоль
        }
    }

    file.close(); // Закрити файл
    return 0;
}

