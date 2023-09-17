
#include <iostream>
using namespace std;
int start = 0;
void InsertCheck(int& number) {
	bool validInput = false;

	do {
		if (cin >> number and start != 0 and start != 1) {
			validInput = true;
		}
		else if ((start == 0 or start == 1) and number >= 3) {
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
int generateRandomNumber(int min, int max) {
	return rand() % (max - min + 1) + min;
}
void InsertMatrix(int n, int m, int**& arr, int choice) {
	if (choice == 1) {
		cout << "Введіть " << n * n << " цілих чисел:" << endl;
		for (int i = 0; i < m; i++) {
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


		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = generateRandomNumber(minVal, maxVal);
			}
		}
	}

}
void printMatrix(int** matrix, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}
void printArray(int* matrix, int m) {

	for (int j = 0; j < m; j++) {
		cout << matrix[j] << "\t";
	}
	cout << endl;
}
void InsertArray(int m, int*& arr, int choice) {
	if (choice == 1) {
		cout << "Введіть " << m << " цілих чисел:" << endl;
		for (int i = 0; i < m; i++) {

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



		for (int j = 0; j < m; j++) {
			arr[j] = generateRandomNumber(minVal, maxVal);
		}

	}

}
// Функція для множення матриці на вектор
void multiplyMatrixVector(int** matrix, int* vector, int* result, int numRows, int numCols) {
	for (int i = 0; i < numRows; i++) {
		result[i] = 0;
		for (int j = 0; j < numCols; j++) {
			result[i] += matrix[i][j] * vector[j];
		}
	}
}

// Функція для множення вектора на матрицю
void multiplyVectorMatrix(int* vector, int** matrix, int* result, int numRows, int numCols) {
	for (int i = 0; i < numCols; i++) {
		result[i] = 0;
		for (int j = 0; j < numRows; j++) {
			result[i] += vector[j] * matrix[j][i];
		}
	}
}

void ArrayDifference(int* array1,int* array2, int size) {
	int* vector = new int[size];
	cout << "Відмінність: " << endl;
	for (int i = 0; i < size; ++i) {
		vector[i] = array1[i] - array2[i];
	}
	printArray(vector, size);
	delete[] vector;
}
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Ukrainian");
	cout << "lab7.2\tKisil Dmytro\tIPZ11/2\t14\n\n" << endl;
	cout << "14.2. Створити матрицю, кількість рядків m>3 та кількість стовпців n>3 якої ввести з клавіатури. Передбачити меню вибору способу створення матриці: введення з клавіатури або генерація псевдовипадкових додатніх та від'ємних чисел. Створити вектор, задавши з клавіатури його вимірність та згенерувавши значення його елементів. Перемножити матрицю на вектор та вектор на матрицю. Передбачити несумісність вектора та матриці з виведенням відповідного повідомлення. Вивести на екран вхідну матрицю, вхідний вектор та вектори-результатів. Порівняти результати множення матриці на вектор і вектора на матрицю\n\n" << endl;
	int m, n, vectorSize;

	cout << "Введіть кількість рядків матриці (m > 3): ";
	InsertCheck(m);
	cout << "Введіть кількість стовпців матриці (n > 3): ";
	InsertCheck(n);
	cout << "Введіть розмір вектора: ";
	InsertCheck(vectorSize);

	int** matrix = new int* [m];
	for (int i = 0; i < m; ++i) {
		matrix[i] = new int[m]; // Для кожного вказівника створюємо рядок матриці
	}
	int* vector = new int[vectorSize];

	int choice;
	cout << "Виберіть спосіб заповнення матриці (1 - введення з клавіатури, 2 - генерація псевдовипадкових чисел): ";
	InsertCheckChoice(choice);

	InsertMatrix(n, m, matrix, choice);

	printMatrix(matrix, m, n);

	int choice_1;
	cout << "Виберіть спосіб заповнення масиву (1 - введення з клавіатури, 2 - генерація псевдовипадкових чисел): ";
	InsertCheckChoice(choice_1);

	InsertArray(vectorSize, vector, choice_1);

	printArray(vector,vectorSize);

	if (n != vectorSize) {
		cout << "Несумісні розміри матриці і вектора. Множення неможливе." << endl;
	}
	else {
		// Множення матриці на вектор і вектора на матрицю
		int* resultMatrixVector = new int[m];
		int* resultVectorMatrix = new int[n];

		multiplyMatrixVector(matrix, vector, resultMatrixVector, m, n);
		multiplyVectorMatrix(vector, matrix, resultVectorMatrix, m, n);

		// Виведення результатів
		cout << "Матриця:" << endl;
		printMatrix(matrix, m, n);

		cout << "Вектор:" << endl;
		printArray(vector,vectorSize);
		cout << endl;

		// Виведення результатів множення
		cout << "Результат множення матриці на вектор:" << endl;
		printArray(resultMatrixVector, vectorSize);
		cout << endl;

		cout << "Результат множення вектора на матрицю:" << endl;
		printArray(resultVectorMatrix, vectorSize);
		cout << endl;
		ArrayDifference(resultMatrixVector,resultVectorMatrix,vectorSize);
		cout << endl;

		// Звільнення пам'яті
		delete[] resultMatrixVector;
		delete[] resultVectorMatrix;
	}

	for (int i = 0; i < m; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] vector;
	

}
