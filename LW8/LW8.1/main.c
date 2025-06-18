#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "headlines.h"




int main() {
    system("chcp 65001");
    Node* poly = NULL;
    int n, degree, coefficient;

    printf("Введите количество членов многочлена: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("Введите степень и коэффициент для члена %d (через пробел): ", i + 1);
        scanf("%d %d", &degree, &coefficient);
        addTerm(&poly, degree, coefficient);
    }

    printf("Исходный многочлен: ");
    printPoly(poly);

    int coeffToRemove;
    printf("Введите коэффициент для удаления: ");
    scanf("%d", &coeffToRemove);

    removeByCoefficient(&poly, coeffToRemove);

    printf("После удаления коэффициента %d: ", coeffToRemove);
    printPoly(poly);

    // Очистка памяти
    while (poly) {
        Node* tmp = poly;
        poly = poly->next;
        free(tmp);
    }
    return 0;
}