#include <stdio.h>
#include <stdlib.h>
#include "headlines.h"


// Удаляет все элементы с заданным коэффициентом
void removeByCoefficient(Node** head, int coeff) {
    Node* curr = *head;
    Node* prev = NULL;
    while (curr != NULL) {
        if (curr->coefficient == coeff) {
            Node* toDelete = curr;
            if (prev == NULL) {
                *head = curr->next;
            } else {
                prev->next = curr->next;
            }
            curr = curr->next;
            free(toDelete);
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

// Пример добавления элемента (в начало)
void addTerm(Node** head, int degree, int coefficient) {
    //if (coefficient == 0) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->degree = degree;
    newNode->coefficient = coefficient;
    newNode->next = *head;
    *head = newNode;
}

// Функция для печати многочлена
void printPoly(Node* head) {
    Node* curr = head;
    while (curr) {
        printf("%dx^%d ", curr->coefficient, curr->degree);
        if (curr->next) printf("+ ");
        curr = curr->next;
    }
    printf("\n");
}
