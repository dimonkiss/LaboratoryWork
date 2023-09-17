
#include <iostream>
using namespace std;
void InsertCheck(double& number) {
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
double Calculation(double x, double b, double c) {
	if (x > 0 and b * x != c) {
		return x / (b*x - c);
	}
	else if (b*c == 0 and x > 0) {
		return b * b - x;
	}
	else if (x < 0) {
		return b * x / (c * c);
	}
	else {
		cout << "Error!!!" << endl;
		return 0;
	}
}
string CylinderBelong(double x, double y, double z, double h, double r) {
	// Обчислення відстані точки до вісі Oz
	double distanceToOz = sqrt(x * x + y * y);

	// Перевірка, чи точка належить циліндру
	if (distanceToOz <= r && z >= 0 && z <= h) {
		return "Point is belong cylinder.\n";
	}
	else {
		return "Point isn`t belong cylinder.\n";
	}
}
int main()
{
	cout << "lab2\tKisil Dmytro\tIPZ11/2\t14\n\n" << endl;
	//1
	//double x, b, c;
	//cout << "{ x/(bx-c), x>0, bx != c";
	//cout << "{ b*b-x, x>0, bc = 0";
	//cout << "{ bx/(c*c), x < 0\n";
	//cout << "Insert x: ";
	//InsertCheck(x);
	//cout << "Insert b: ";
	//InsertCheck(b);
	//cout << "Insert c: ";
	//InsertCheck(c);
	//double res = Calculation(x,b,c);
	//cout << "Result: " << res << endl;
	


	// Перший набір значень
	//x = 2.0;
	//b = 3.0;
	//c = 1.0;
	//res = 0.4

	// Другий набір значень
	//x = 1.0;
	//b = 0.0;
	//c = 0.0;
	//res = -1

	// Третій набір значень
	//x = -1.0;
	//b = 2.0;
	//c = 3.0;
	//res = -0.22222222


	//2
	cout << "A point in space is given by Cartesian coordinates (x, y, z). Check whether it belongs to a cylinder whose axis coincides with the axis Oz, height is h, and the lower base lies in the plane Oxy and has a radius r. The values ​​of the point's horizontal coordinates, height and radius are entered from the keyboard." << endl;
	double x, y, z, h, r;
	cout << "Insert x:";
	InsertCheck(x);
	cout << "Insert y:";
	InsertCheck(y);
	cout << "Insert z:";
	InsertCheck(z);
	cout << "Insert h:";
	InsertCheck(h);
	cout << "Insert r:";
	InsertCheck(r);
	string res = CylinderBelong(x, y, z, h, r);
	cout << res;
	//Набір 1:

	//	Координата x = 2.0
	//	Координата y = 3.0
	//	Координата z = 1.0
	//	Висота h = 5.0
	//	Радіус r = 2.0
	//	Результат ні
	
	//Набір 2:

	//	Координата x = 1.0
	//	Координата y = 1.0
	//	Координата z = 3.0
	//	Висота h = 4.0
	//	Радіус r = 1.5
	//	Результат так
	
	//Набір 3:

	//	Координата x = 0.0
	//	Координата y = 0.0
	//	Координата z = 0.0
	//	Висота h = 6.0
	//	Радіус r = 3.0
	//	Результат так

}

