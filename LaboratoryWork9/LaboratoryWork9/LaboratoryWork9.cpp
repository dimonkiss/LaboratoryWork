#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "Ukrainian");
    char input[1000];  // Максимальна довжина рядка
    printf("Введіть рядок: ");
    fgets(input, sizeof(input), stdin);  // Отримуємо рядок від користувача (увага: ця функція не є безпечною для використання)

    // Змінюємо рядок на рядок в нижньому регістрі для порівняння
    for (int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    // Масив ключових слів
    const char* keywords[] = { "if", "else", "switch", "while", "for", "do", "return", /* додайте інші ключові слова тут */};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    // Масив для зберігання кількості входжень для кожного ключового слова
    int* keywordCounts = new int[numKeywords];
    for (int i = 0; i < numKeywords; i++) {
        keywordCounts[i] = 0;
    }

    // Зберігаємо знайдені букви для побудови ключового слова
    char foundLetters[1000] = "";
    int foundLetterIndex = 0;

    // Шукаємо ключові слова та підраховуємо кількість входжень
    for (int i = 0; i < numKeywords; i++) {
        const char* keyword = keywords[i];
        char* pos = strstr((char*)input, keyword);
        size_t keywordLength = strlen(keyword);
        while (pos != NULL) {
            keywordCounts[i]++;

            // Додаємо знайдені букви до списку
            for (int j = 0; j < keywordLength; j++) {
                if (strchr(foundLetters, keyword[j]) == NULL) {
                    foundLetters[foundLetterIndex++] = keyword[j];
                }
            }

            pos = strstr(pos + keywordLength, keyword);
        }
    }

    // Визначаємо, чи було знайдено хоча б одне ключове слово
    int totalKeywords = 0;
    for (int i = 0; i < numKeywords; i++) {
        totalKeywords += keywordCounts[i];
    }

    // Якщо не було знайдено жодного ключового слова, виводимо зібрані букви
    if (totalKeywords == 0) {
        printf("Складене ключове слово: %s\n", foundLetters);
    }
    else {
        // Виводимо кількість входжень для кожного ключового слова
        for (int i = 0; i < numKeywords; i++) {
            printf("Кількість входжень слова(з виділенням з букв рядка) '%s': %d\n", keywords[i], keywordCounts[i]);
        }
    }

    return 0;
}





