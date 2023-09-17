// LaboratoryWork1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
int counter = 0;
#include <iostream>
using namespace std;
void InsertCheck(double& number) {

	bool validInput = false;
	switch (counter) {
	case 0:
		do {
			if (cin >> number and number >0 and log(number) != 0 ) {
				validInput = true;
			}
			else {
				cout << "Incorect input. Try again." << endl;
				cin.clear(); // Очищаємо стан помилки вводу
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Видаляємо некоректний ввід з буфера
			}
		} while (!validInput);
		break;
	case 1:
		do {
			if (cin >> number and 1- number !=0) {
				validInput = true;
			}
			else {
				cout << "Incorect input. Try again." << endl;
				cin.clear(); // Очищаємо стан помилки вводу
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Видаляємо некоректний ввід з буфера
			}
		} while (!validInput);
		break;
	case 3:
		do {
			if (cin >> number and 1 - number != 0) {
				validInput = true;
			}
			else {
				cout << "Incorect input. Try again." << endl;
				cin.clear(); // Очищаємо стан помилки вводу
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Видаляємо некоректний ввід з буфера
			}
		} while (!validInput);
		break;
	case 4:
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
		break;
	case 5:
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
		break;
	default:
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
		break;

	}
	++counter;

}
double Calculation(double a, double b, double c, double d) {
		double x = (pow(a, 2) / abs(1 - b)) + (pow(b, 2) / abs(1 - d)) + (pow(c, 2) / log(a));
		return x;
}
int main()
{
	
	double a , b ,c ,d;
	cout << "lab1\tKisil Dmytro\tIPZ11/2\t14\n\n" << endl;
	//1
	cout << "X=A²/|1-B|+B²/|1-D|+C²/LnA" << endl;
	cout << "Inserted values must meet these conditions: 1 - b != 0 and 1 - d != 0 and log(a) != 0 and a > 0" << endl;
	cout << "Insert please a: ";
	InsertCheck(a);
	cout << "Insert please b: ";
	InsertCheck(b);
	cout << "Insert please c: ";
	InsertCheck(c);
	cout << "Insert please d: ";
	InsertCheck(d);
	double x = Calculation(a,b,c,d);
	cout << "Result: " << x << endl;

	//Набір 1:

	//	A = 3.0
	//	B = 2.0
	//	C = 1.0
	//	D = 4.0
	//	Результат = 11.2436
	// 
	//	Набір 2:

	//	A = 2.0
	//	B = 0.5
	//	C = 2.0
	//	D = 1.5
	//	Результат = 14.2708
	// 
	//	Набір 3:

	//	A = 5.0
	//	B = 3.0
	//	C = 2.5
	//	D = 0.0
	//	Результат = 32.8833

	//2
	cout << "Calculate the kinetic energy of a body of mass m moving at a speed v relative to the Earth's surface. Enter the value of body mass m and velocity v from the keyboard.\n" << endl;
	double m, v;
	cout << "Insert mass:\t";
	InsertCheck(m);
	cout << "Insert speed:\t";
	InsertCheck(v);
	double E = (m * v * v) / 2;
	cout << "Kinetic energy: " << E << endl;

	//Набір 1

	// m = 10
	// v = 2
	// E = 20

	//Набір 2

	// m = 100
	// v = 4
	// E = 800

	//Набір 3

	// m = 3.5
	// v = 1.5
	// E = 3.9375
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
