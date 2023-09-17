#include <iostream>
using namespace std;

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

// Структура для представлення точки з координатами (x, y)
struct Point {
    int x, y;
};

// Функція для знаходження орієнтації трьох точок
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;     // Точки лежать на одній прямій
    return (val > 0) ? 1 : 2; // 1 - Годинникова стрілка, 2 - Проти годинникової стрілки
}

// Головна функція для знаходження опуклого многокутника
void convexHull(Point points[], int n) {
    if (n < 3) return; // Якщо менше 3 точок, то неможливо сформувати опуклий многокутник

    // Знайдемо точку з найменшою y-координатою (і саму ліву, якщо їх багато)
    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftmost].x || (points[i].x == points[leftmost].x && points[i].y < points[leftmost].y)) {
            leftmost = i;
        }
    }

    // Початкова точка опуклого многокутника
    int p = leftmost, q;
    do {
        cout << "(" << points[p].x << ", " << points[p].y << ")\n";

        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            // Якщо точка i лежить зліва від вектора, то вона є кращою кандидатурою для наступної точки
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }

        p = q;
    } while (p != leftmost);
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    cout << "lab6.3\tKisil Dmytro\tIPZ11/2\t14\n\n" << endl;
    cout << "Завдання 3. Векторна алгебра, поліноми, многочлени, алгебраїчні рівняння" << endl;
    cout << "Забороняється використовувати бібліотеку стандартних шаблонів STL, шаблон вектору std::vector, а також бібліотечні методи." << endl;
    cout << "14.3. На площині задані своїми координатами (X1, Y1), (X2, Y2), ..., (Xn, Yn) n >2 точок. Знайти такий мінімальний за площею опуклий многокутник, що всі n точок лежать або всередині цього многокутника, або на його кордоні. Кількість точок n та їх координати ввести з клавіатури. Вивести на екран координати шуканого многокутника\n\n" << endl;
    int n;
    cout << "Введіть кількість точок: ";
    InsertCheck(n);

    Point* points = new Point[n];

    
    for (int i = 0; i < n; i++) {
        cout << "Введіть координати точки " << i + 1 <<" (x, y):\n";
        InsertCheck(points[i].x);
        InsertCheck(points[i].y);
    }

    cout << "Координати опуклого многокутника:\n";
    convexHull(points, n);

    return 0;
}



