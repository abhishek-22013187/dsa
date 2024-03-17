#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* pNext;
} Node;

Node* create_new_node(char data) {
    Node* new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed. Please try again.\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->pNext = NULL;

    return new_node;
}

Node* unshift_node(Node* head, char data){
    Node* new_node = create_new_node(data);

    new_node->pNext = head;
    return new_node;
}

Node* push_node(Node* head, char data){
    Node* new_node = create_new_node(data);
    Node* current_node = head;

    while (current_node->pNext){
        current_node = current_node->pNext;
    }

    current_node->pNext = new_node;
    return head;
}

Node* delete_node(Node* head, char data){
    Node* current_node = head;
    Node* prev_node = NULL;

    if (current_node != NULL && current_node->data == data) {
        head = current_node->pNext;
        free(current_node);
        return head;
    }

    while (current_node != NULL && current_node->data != data) {
        prev_node = current_node;
        current_node = current_node->pNext;
    }

    if (current_node == NULL) {
        fprintf(stderr, "Element '%c' not found in the list.\n", data);
        return head;
    }

    prev_node->pNext = current_node->pNext;
    free(current_node);
    return head;
}

void print_linked_list(Node* head) {
    Node* current_node = head;
    while (current_node) {
        printf("%c->", current_node->data);
        current_node = current_node->pNext;
    }
    printf("/0\n");
}

int main() {
    printf("**********\n");

    Node* head = NULL;

  
    head = create_new_node('h');
    head = push_node(head, 'w');
    head = push_node(head, 'n');


    // ! a)
    printf("Linked list before deletion: ");
    print_linked_list(head);

    // ! b)
    head = delete_node(head, 'w');
    printf("Linked list after deletion: ");
    print_linked_list(head);

    printf("**********\n");
    return 0;
}