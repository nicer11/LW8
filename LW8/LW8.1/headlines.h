// Структура для элемента многочлена
typedef struct Node{
    int degree;         // Степень X
    int coefficient;    // Коэффициент (ненулевой)
    struct Node* next;
} Node;


void removeByCoefficient(Node** head, int coeff);
void addTerm(Node** head, int degree, int coefficient);
void printPoly(Node* head);