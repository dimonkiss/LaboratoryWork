#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
// Оголошення перерахування PaymentType та структури Abonent
enum PaymentType {
	Hourly,       // Оплата щогодинна
	Subscription  // Оплата абонементна
};

struct Abonent {
	string surname;
	string phoneNumber;
	string address; // місто 
	PaymentType paymentType;
	double paymentAmount;
};

// Генерує випадковий номер телефону
string generatePhoneNumber(string Coutry) {
	string phoneNumber = "";
	if (Coutry == "UA") {
		phoneNumber += "+380";
	}
	else if (Coutry == "UK") {
		phoneNumber += "+44";
	}
	else {
		phoneNumber += "+1";
	}
	for (int i = 0; i < 9; ++i) {
		phoneNumber += to_string(rand() % 10);
	}
	return phoneNumber;
}

// Генерує випадкову адресу (місто)
string generateAddress() {
	string cities[] = { "Київ", "Львів", "Одеса", "Харків", "Дніпро" };
	return cities[rand() % 5];
}

// Генерує випадковий PaymentType
PaymentType generatePaymentType() {
	return rand() % 2 == 0 ? Hourly : Subscription;
}
void InsertCheck(int& number) {
	bool validInput = false;

	do {
		if (cin >> number and number >= 0 and number <=5) {
			validInput = true;
		}
		else {
			cout << "Incorect input. Try again." << endl;
			cin.clear(); // Очищаємо стан помилки вводу
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Видаляємо некоректний ввід з буфера
		}
	} while (!validInput);

}
void InsertCheckCoutry(string& number) {
	bool validInput = false;

	do {
		if (cin >> number and (number == "UA" or number == "UK" or number == "US")) {
			validInput = true;
		}
		else {
			cout << "Incorect input. Try again." << endl;
			cin.clear(); // Очищаємо стан помилки вводу
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Видаляємо некоректний ввід з буфера
		}
	} while (!validInput);

}
void InsertToArray(int numAbonents, Abonent* abonents, string Coutry) {
	for (int i = 0; i < numAbonents; ++i) {
		abonents[i].surname = "Абонент " + to_string(i + 1);
		abonents[i].phoneNumber = generatePhoneNumber(Coutry);
		abonents[i].address = generateAddress();
		abonents[i].paymentType = generatePaymentType();
		abonents[i].paymentAmount = rand() % 100 + 50; // Генеруємо випадкову суму оплати від 50 до 149
	}

	// Виведення даних про абонентів
	cout << "Прізвище\tНомер телефону\tАдреса\tТип оплати\tВартість оплати\n\n" << endl;
	for (int i = 0; i < numAbonents; ++i) {
		cout << abonents[i].surname << "\t" << abonents[i].phoneNumber << "\t" << abonents[i].address << "\t"
			<< (abonents[i].paymentType == Hourly ? "Щогодинна" : "Абонементна") << "\t"
			<< abonents[i].paymentAmount << endl;
	}
}
// Функція для виведення абонентів з щохвилинною оплатою, сума оплати у яких нижче заданого рівня
void printHourlyPaymentBelowThreshold(const Abonent* abonents, int numAbonents, double threshold) {
	bool found = false;
	cout << "Список абонентів з щохвилинною оплатою, сума оплати менше " << threshold << ":\n" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "\nПрізвище\tНомер телефону\tАдреса\tВартість оплати" << endl;

	for (int i = 0; i < numAbonents; ++i) {
		found = true;
		if (abonents[i].paymentType == Hourly && abonents[i].paymentAmount < threshold) {
			cout << abonents[i].surname << "\t" << abonents[i].phoneNumber << "\t" << abonents[i].address << "\t"
				<< (abonents[i].paymentType == Hourly ? "Щогодинна" : "Абонементна") << "\t"
				<< abonents[i].paymentAmount << endl;
		}

	}
	if (!found) {
		cout << "Немає абонентів з щохвилинною оплатою, сума оплати менше " << threshold << endl;
	}
}
// Функція для знаходження номеру телефону абонента за заданою адресою
void findPhoneNumberByAddress(const Abonent* abonents, int numAbonents, const string& searchAddress) {
	bool found = false;
	for (int i = 0; i < numAbonents; ++i) {
		found = true;
		if (abonents[i].address == searchAddress) {
			cout << abonents[i].surname << "\t" << abonents[i].phoneNumber << "\t" << abonents[i].address << "\t"
				<< (abonents[i].paymentType == Hourly ? "Щогодинна" : "Абонементна") << "\t"
				<< abonents[i].paymentAmount << endl;
		}
	}
	if (!found) {
		cout << "Немає абонентів з адресою " << searchAddress << endl;
	}

}
int main()
{
	cout << "lab10\tKisil Dmytro\tIPZ11/2\t14\n\n" << endl;
	setlocale(LC_ALL, "Ukrainian");
	cout << "Створити масив структур. Кожна структура складається з таких елементів: прізвище абонента, номер телефону, адреса, вид оплати (щохвилинна чи абонементна), вартість оплати. Реалізувати такі операції:доповнити масив прізвищами абонентів, номери телефонів яких починаються на задані цифри(імітувати введення нової АТС);видати список абонентів з щохвилинною оплатою, сума оплати у яких нижче заданого рівня;визначити номер телефону абонента за заданою адресою.Результати запитів вивести у вигляді таблиць";
	int choice;
	// Ініціалізація генератора випадкових чисел
	srand(time(0));
	const int numAbonents = 25;
	Abonent abonents[numAbonents];
	string Coutry;
	int level;
	int count = 0;
	string addres;
	int adreschoice;
	do {
		cout << "\n\n\n1.Заповнити масив данними" << endl;
		cout << "2.Видати список абонентів з щохвилинною оплатою, сума оплати у яких нижче заданого рівня;" << endl;
		cout << "3.Визначити номер телефону абонента за заданою адресою" << endl;
		cout << "0.Вихід\n" << endl;
		InsertCheck(choice);
		switch (choice) {

		case 1:
			cout << "Введіть вашу країну(UA - Україна,UK - Велика Британія,US - Сполучені Штати Америки): ";
			InsertCheckCoutry(Coutry);
			InsertToArray(numAbonents, abonents, Coutry);
			++count;
			break;
		case 2:

			if (count > 0) {
				cout << "\nВведіть мінімальне значення для оплати абонента: ";
				InsertCheck(level);

				printHourlyPaymentBelowThreshold(abonents, numAbonents, level);
			}
			else {
				cout << "Масив не має значень натисніть будь ласка клавішу 1" << endl;
				continue;
			}
			break;
		case 3:
			if (count > 0) {
				cout << "Виберіть адресу: " << endl;
				cout << "1.Київ" << endl;
				cout << "2.Львів" << endl;
				cout << "3.Одеса" << endl;
				cout << "4.Харків" << endl;
				cout << "5.Дніпро" << endl;
				InsertCheck(adreschoice);
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
				findPhoneNumberByAddress(abonents, numAbonents, addres);
			}
			else {
				cout << "Масив не має значень натисніть будь ласка клавішу 1" << endl;
				continue;
			}
			break;

		case 0:
			break;

		}



	} while (choice != 0);
}

