
#include <iostream>
using namespace std;
unsigned long long factorial(double n) {
	unsigned long long result = 1;
	for (int i = 1; i <= n; ++i) {
		result *= i;
	}
	return result;
}
void InsertCheck(int& number) {
	bool validInput = false;
	do {
		if (cin >> number and number>0) {
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
	cout << "lab3\tKisil Dmytro\tIPZ11/2\t14\n\n" << endl;
	int lim;
	cout << "Insert limit of operations(k): ";
	InsertCheck(lim);
	double k = 0;
	double sum = 0;
	double member = 0;
	cout << "======================================================================================================================" << endl;
	cout << "\tx\tk\tmember\t\tsum" << endl;
	for (double x = 1; x < 5; ++x) {
		cout << "======================================================================================================================" << endl;
		member = 0;
		sum = 0;
		while (abs(member) < 1e38 and abs(sum) < 1e38 and k  <=lim) {
			member = pow(-1, k + 1) * pow(x / 3, 2 * k - 1) / factorial(2 * k + 1);
			sum += member;
			cout << "\t" << x << "\t" << k << "\t" << member << "\t" << sum << endl;
			k++;
		}
		if (k -1 == lim) {
			cout << "Break because of your limit" << endl;
		}
		else {
			cout << "Break because limit of RAM is cant use more memory" << endl;
		}
		k = 0;
		++lim;

	}
}

