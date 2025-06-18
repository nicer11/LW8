#include <stdio.h>
#include "headlines.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// Создание нового узла
Node* create_node(const char *word) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->word = strdup(word);
    node->prev = node->next = NULL;
    return node;
}

// Добавление узла в конец списка
void append(Node **head, Node **tail, const char *word) {
    Node *node = create_node(word);
    if (!*head) {
        *head = *tail = node;
    } else {
        node->prev = *tail;
        (*tail)->next = node;
        *tail = node;
    }
}

// Вывод списка
void print_list(Node *head) {
    for (Node *cur = head; cur; cur = cur->next) {
        printf("%s", cur->word);
        if (cur->next) printf(" ");
    }
    printf(".\n");
}

// Освобождение памяти
void free_list(Node *head) {
    while (head) {
        Node *tmp = head;
        head = head->next;
        free(tmp->word);
        free(tmp);
    }
}

// Вставка копии перед данным узлом
void insert_copy_before(Node **head, Node *node) {
    Node *copy = create_node(node->word);
    copy->next = node;
    copy->prev = node->prev;
    if (node->prev) node->prev->next = copy;
    node->prev = copy;
    if (*head == node) *head = copy;
}

// Поиск максимальной длины слова
int max_word_length(Node *head) {
    int max = 0;
    for (Node *cur = head; cur; cur = cur->next) {
        int len = strlen(cur->word);
        if (len > max) max = len;
    }
    return max;
}

// Вставка копии перед словом максимальной длины
void insert_before_max(Node **head) {
    int max = max_word_length(*head);
    for (Node *cur = *head; cur; cur = cur->next) {
        if ((int)strlen(cur->word) == max) {
            insert_copy_before(head, cur);
            // Пропустить только что вставленную копию
            cur = cur->next;
        }
    }
}



void build_list(Node **head, Node **tail, const char *input) {
    char word[101];
    int i = 0, j = 0;
    while (input[i]) {
        if (isalpha((unsigned char)input[i])) {
            word[j] = (unsigned char)input[i];
            j++;
        } else if ((input[i] == ' ' || input[i] == '.') && j > 0) {
            word[j] = '\0';
            append(head, tail, word);
            j = 0;
        }
        if (input[i] == '.') break;
        i++;
    }
}


