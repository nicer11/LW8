typedef struct Node {
    char *word;
    struct Node *prev, *next;
} Node;

Node* create_node(const char *word);
void append(Node **head, Node **tail, const char *word);
void print_list(Node *head);
void free_list(Node *head);
void insert_copy_before(Node **head, Node *node);
int max_word_length(Node *head);
void insert_before_max(Node **head);
void build_list(Node **head, Node **tail, const char *input);