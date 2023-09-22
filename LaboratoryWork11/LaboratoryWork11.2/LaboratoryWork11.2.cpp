#include <iostream>
#include <string>
#include <ctime> // Add this for generating random numbers
#include <cstdlib> // Add this for generating random numbers
#include <fstream>
#include <conio.h>
#include <regex>
using namespace std;

enum PaymentType {
    Hourly,
    Subscription
};

struct Abonent {
    int id;
    string surname;
    string phoneNumber;
    string address;
    PaymentType paymentType;
    double paymentAmount;
};

struct DynamicArrayAbbonents {
    Abonent* data;
    int size;
    int capacity;
};

void initializeDynamicArray(DynamicArrayAbbonents& arr, int initialCapacity) {
    arr.data = new Abonent[initialCapacity];
    arr.size = 0;
    arr.capacity = initialCapacity;
    cout << "Масив ініціалізовано!!!" << endl;
}

void InsertCheck(int& number) {
    bool validInput = false;

    do {
        if (cin >> number && number >= 1) {
            validInput = true;
        }
        else {
            cout << "Incorrect input. Try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!validInput);
}
void InsertCheckChoice(int& number) {
    bool validInput = false;

    do {
        if (cin >> number && number >= 0) {
            validInput = true;
        }
        else {
            cout << "Incorrect input. Try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!validInput);
}
void InsertCheckChoice1(int& number) {
    bool validInput = false;

    do {
        if (cin >> number && number > 0 and number <=5) {
            validInput = true;
        }
        else {
            cout << "Incorrect input. Try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!validInput);
}
string generatePhoneNumber() {
    string phoneNumber = "+380";
    for (int i = 0; i < 9; ++i) {
        phoneNumber += to_string(rand() % 10);
    }
    return phoneNumber;
}

string generateAddress() {
    string cities[] = { "Київ", "Львів", "Одеса", "Харків", "Дніпро" };
    return cities[rand() % 5];
}

PaymentType generatePaymentType() {
    return rand() % 2 == 0 ? Hourly : Subscription;
}
void writeArrayToFile(const DynamicArrayAbbonents abonents) {
    remove("abonents.txt");
    ofstream outFile("abonents.txt");

    if (!outFile) {
        cerr << "Failed to open the file abonents.txt for writing." << endl;
        return;
    }

    // Write array data to the file
    for (int i = 0; i < abonents.size; ++i) {
        outFile << abonents.data[i].id << "\t" << abonents.data[i].surname << "\t" << abonents.data[i].phoneNumber << "\t" << abonents.data[i].address << "\t"
            << (abonents.data[i].paymentType == Hourly ? "Щогодинна" : "Абонементна") << "\t"
            << abonents.data[i].paymentAmount << endl;
    }

    outFile.close();

}
void addItem(DynamicArrayAbbonents& abonents) {
    if (abonents.size < abonents.capacity) {
        abonents.data[abonents.size].id = abonents.size + 1;
        abonents.data[abonents.size].surname = "Абонент " + to_string(abonents.size + 1);
        abonents.data[abonents.size].phoneNumber = generatePhoneNumber();
        abonents.data[abonents.size].address = generateAddress();
        abonents.data[abonents.size].paymentType = generatePaymentType();
        abonents.data[abonents.size].paymentAmount = rand() % 100 + 50;
        ++abonents.size;
    }
    else {
        // You should handle resizing the array here
        int newCapacity = abonents.capacity * 2; // Double the capacity
        Abonent* new_data = new Abonent[newCapacity];

        for (int i = 0; i < abonents.size; ++i) {
            new_data[i] = abonents.data[i];
        }

        delete[] abonents.data; // Free the old memory

        abonents.data = new_data;
        abonents.capacity = newCapacity;

        // Now you can add the new item
        addItem(abonents);
    }
    writeArrayToFile(abonents);
}

void printArrayToConsole(DynamicArrayAbbonents abonents) {
    cout << "Id\tПрізвище\tНомер телефону\tАдреса\tТип оплати\tВартість оплати\n\n" << endl;
    for (int i = 0; i < abonents.size; ++i) {
        cout << abonents.data[i].id << "\t" << abonents.data[i].surname << "\t" << abonents.data[i].phoneNumber << "\t" << abonents.data[i].address << "\t"
            << (abonents.data[i].paymentType == Hourly ? "Щогодинна" : "Абонементна") << "\t"
            << abonents.data[i].paymentAmount << endl;
    }
}

void InsertToArray(int numAbonents, DynamicArrayAbbonents& abonents) {
    for (int i = 0; i < numAbonents; ++i) {
        addItem(abonents);
    }
    printArrayToConsole(abonents);
    writeArrayToFile(abonents);
}

void editElementById(DynamicArrayAbbonents& abonents, int id) {
    int same;
    string tmp;
    int tmpint;
    for (int i = 0; i < abonents.size; ++i) {
        if (abonents.data[i].id == id) {
            cout << "Редагування елемента з id - " << id << endl;
            cout << "Введіть нові значення: " << endl;
            //string surname;
            //string phoneNumber;
            //string address;
            //PaymentType paymentType;
            //double paymentAmount;
            cout << "Введіть нове призвіще: ";
            cout << "Оставити тим сами  - 1";
            cin >> tmp;
            if (tmp != "1") {
                abonents.data[i].surname = tmp;
            }
            cout << "Введіть новий мобільний телефон: ";
            cout << "Оставити тим сами  - 1";
            cin >> tmp;
            if (tmp != "1") {
                abonents.data[i].phoneNumber = tmp;
            }
            cout << "Введіть нову адресу: ";
            cout << "Оставити тим сами  - 0";
            cout << "1.Київ" << endl;
            cout << "2.Львів" << endl;
            cout << "3.Одеса" << endl;
            cout << "4.Харків" << endl;
            cout << "5.Дніпро" << endl;
            cin >> tmpint;
            switch (tmpint) {
            case 1:
                abonents.data[i].address = "Київ";
                break;
            case 2:
                abonents.data[i].address = "Львів";
                break;
            case 3:
                abonents.data[i].address = "Одеса";
                break;
            case 4:
                abonents.data[i].address = "Харків";
                break;
            case 5:
                abonents.data[i].address = "Дніпро";
                break;
            default:
                break;

            }

            cout << "Введіть новий тип платежу: ";
            cout << "Оставити тим сами  - -1";
            cout << "0.Похвилина" << endl;
            cout << "1.Абонемент" << endl;
            cin >> tmpint;
            switch (tmpint) {
            case 1:
                abonents.data[i].paymentType = Hourly;
                break;
            case 2:
                abonents.data[i].paymentType = Subscription;
                break;
            default:
                break;
            }
            cout << "Введіть нову оплату: ";
            cout << "Оставити тим сами  - 1";
            cin >> tmpint;
            if (tmpint != 1) {
                abonents.data[i].paymentAmount = tmpint;
            }
            return;
            writeArrayToFile(abonents);
        }
    }
    cout << "Element with id " << id << " not found." << endl;
    return; // Element not found
}

void deleteElementById(DynamicArrayAbbonents& abonents, int id) {
    int foundIndex = -1;


    for (int i = 0; i < abonents.size; ++i) {
        if (abonents.data[i].id == id) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {

        for (int i = foundIndex; i < abonents.size - 1; ++i) {
            abonents.data[i] = abonents.data[i + 1];
        }

        abonents.size--;
        cout << "Елемент з id " << id << " був вилучений." << endl;
        writeArrayToFile(abonents);
        return;
    }

    cout << "Елемент з id " << id << " не знайдений" << endl;
    return;
}
void fromfiletoconsole() {
    ifstream file("abonents.txt");
    // Перевірка, чи вдалося відкрити файл
    if (!file.is_open()) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }

    // Зчитування та виведення вмісту файлу рядок за рядком
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    // Закриття файлу після завершення роботи з ним
    file.close();
}
void fromfiletoconsolelimit(string fileName, double payment) {
    ifstream file(fileName); // Відкрити файл для читання

    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл" << endl;
        return; // Помилка відкриття файлу
    }

    string line;
    cout << "Id\tПрізвище\tНомер телефону\tАдреса\tТип оплати\tВартість оплати\n\n" << endl;
    while (getline(file, line)) { // Прочитати кожен рядок у файлі
        size_t pos = line.find_last_of('\t'); // Знайти останню табуляцію
        if (pos != string::npos) {
            string last_value = line.substr(pos + 1); // Отримати підстроку після останньої табуляції
            size_t payment_pos = line.find_last_of('\t', pos - 1); // Знайти позицію останньої табуляції перед останньою колонкою
            string payment_type = line.substr(payment_pos + 1, pos - payment_pos - 1); // Отримати тип оплати
            if (payment_type == "Щогодинна" and stoi(last_value) < payment) {
                cout << line << endl;
                
            }
        }
    }

    file.close(); // Закрити файл
}
void fromfiletoconsoleadres(string adres) {
    ifstream file("abonents.txt"); // Відкрити файл для читання

    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл" << endl;
        return; // Помилка відкриття файлу
    }
    string line;
    cout << "Id\tПрізвище\tНомер телефону\tАдреса\tТип оплати\tВартість оплати\n\n" << endl;
    while (getline(file, line)) { // Прочитати кожен рядок у файлі
        if (line.find(adres) != string::npos) {
            cout << line << endl;
        }
    }

}
int main() {
    cout << "lab11.2\tKisil Dmytro\tIPZ11/2\t14\n\n" << endl;
    setlocale(LC_ALL, "Ukrainian");

    DynamicArrayAbbonents abonents{};
    int maxabonents;
    cout << "Введіть максимальну кількість абонентів що можуть бути у масиві: " << endl;
    InsertCheck(maxabonents);

    initializeDynamicArray(abonents, maxabonents);
    int elm;
    cout << "Введіть яку кількість елементів ви хочете додати:  ";
    InsertCheck(elm);
    InsertToArray(elm, abonents);
    int choice;
    int adreschoice;
    string addres;
    do {
        system("cls");
        cout << "1.Додати елемент до масиву" << endl;
        cout << "2.Редагувати елемент в масиві" << endl;
        cout << "3.Видалити елемент з масиву" << endl;
        cout << "4.Вивести масив з файлу в консоль" << endl;
        cout << "5.Вивести масив у якого ліміт менше за введений і оплата щогодинна" << endl;
        cout << "6.Вивести масив за вказаною адресою" << endl;
        cout << "0.Вихід" << endl;
        InsertCheckChoice(choice);
        int id;
        string str;
        switch (choice) {
        case 1:
            addItem(abonents);
            printArrayToConsole(abonents);
            char ch;

            cout << "Press any key to continue: ";

            // Use _getch() to read a key press without echoing to the console
            ch = _getch();
            system("cls");
            break;
        case 2:
            cout << "Insert id: ";
            InsertCheck(id);
            editElementById(abonents, id);
            printArrayToConsole(abonents);
            char ch1;

            cout << "Press any key to continue: ";

            // Use _getch() to read a key press without echoing to the console
            ch1 = _getch();
            system("cls");
            break;
        case 3:
            cout << "Insert id: ";
            InsertCheck(id);
            deleteElementById(abonents, id);
            printArrayToConsole(abonents);
            char cha;

            cout << "Press any key to continue: ";

            // Use _getch() to read a key press without echoing to the console
            cha = _getch();
            system("cls");
            break;
        case 4:
            fromfiletoconsole();
            char ch2;

            cout << "Press any key to continue: ";

            // Use _getch() to read a key press without echoing to the console
            ch2 = _getch();
            system("cls");
            break;
        case 5:
            double paymentLimit;
            cout << "Введіть ліміт платежу для відображення абонентів (почасова оплата): ";
            cin >> paymentLimit;
            fromfiletoconsolelimit("abonents.txt", paymentLimit);
            char ch3;

            cout << "Press any key to continue: ";

            // Use _getch() to read a key press without echoing to the console
            ch3 = _getch();
            system("cls");
            break;
        case 6:
           
            
            cout << "Виберіть адресу: " << endl;
            cout << "1.Київ" << endl;
            cout << "2.Львів" << endl;
            cout << "3.Одеса" << endl;
            cout << "4.Харків" << endl;
            cout << "5.Дніпро" << endl;
            InsertCheckChoice1(adreschoice);
            switch (adreschoice) {
            case 1:
                addres = "Київ";
                break;
            case 2:
                addres = "Львів";
                break;
            case 3:
                addres = "Одеса";
                break;
            case 4:
                addres = "Харків";
                break;
            case 5:
                addres = "Дніпро";
                break;
            default:
                break;

            }
            fromfiletoconsoleadres(addres);
            char ch4;

            cout << "Press any key to continue: ";

            // Use _getch() to read a key press without echoing to the console
            ch4 = _getch();
            system("cls");
            break;
        case 0:
            continue;
        default:
            break;

        }

    } while (choice != 0);

    return 0;
}


