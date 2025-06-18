#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "headlines.h"

int main() {
    system("chcp 65001"); // Установка кодировки UTF-8 для консоли
    char input[1024];
    printf("Введите строку: ");
    fgets(input, sizeof(input), stdin);

    Node *head = NULL, *tail = NULL;
    build_list(&head, &tail, input);

    printf("Исходный список:\n");
    print_list(head);

    insert_before_max(&head);

    printf("Модифицированный список:\n");
    print_list(head);

    free_list(head);
    return 0;
}

