#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void CreationOfFile(string fileName) {
	// Створення та запис тексту у вихідний файл
	ofstream originalFile(fileName);
	if (!originalFile.is_open()) {
		cerr << "Помилка відкриття файлу!" << endl;
		return;
	}
	cin.ignore(0);
	cout << "Введіть рядки тексту (для завершення введення введіть '0'):" << endl;
	string line;
	while (true) {
		getline(cin, line);
		if (line == "0") {
			break;
		}
		originalFile << line << endl;
	}

	originalFile.close();
}
void CreateCopy(string fileName, string destinationfile) {
	string wordToReplace, replacementWord;
	cout << "Введіть слово, яке слід замінити: ";
	cin >> wordToReplace;
	cout << "Введіть слово, на яке слід зробити заміну: ";
	cin >> replacementWord;
	// Open the source file for reading
	ifstream sourceFile(fileName);
	ofstream destinationFile(destinationfile);

	if (!sourceFile.is_open() || !destinationFile.is_open()) {
		cerr << "Помилка відкриття файлу!" << endl;
		return;
	}

	string line;
	while (getline(sourceFile, line)) {
		// Замініть всі входження searchStr на replaceStr у поточному рядку
		size_t pos = 0;
		while ((pos = line.find(wordToReplace, pos)) != string::npos) {
			line.replace(pos, wordToReplace.length(), replacementWord);
			pos += replacementWord.length();
		}
		// Запишіть змінений рядок у вихідний файл
		destinationFile << line << '\n';
	}
	// Close both files
	sourceFile.close();
	destinationFile.close();

	cout << "Файл успішно скопійовано і зроблена заміна." << endl;

}



int main() {
	cout << "lab11\tKisil Dmytro\tIPZ11/2\t14\n\n" << endl;
	setlocale(LC_ALL, "Ukrainian");
	string fileName{};
	cout << "Введіть ім'я текстового файлу: ";
	cin >> fileName;
	fileName += ".txt";
	const char* fileNameChar = fileName.c_str();
	remove(fileNameChar);
	CreationOfFile(fileName);
	string copyfile = "copy_" + fileName;
	remove(copyfile.c_str());

	CreateCopy(fileName, copyfile);



	return 0;
}
