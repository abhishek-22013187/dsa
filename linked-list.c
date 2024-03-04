#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* pNext;
} Node;

Node* create_new_node(int data) {
    Node* new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed. Please try again.\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->pNext = NULL;

    return new_node;
}

Node* unshift_node(Node* head, int data){
 Node* new_node = create_new_node(data);

  new_node->pNext = head;
  return new_node;
}

Node* push_node(Node* head, int data){
 Node* new_node = create_new_node(data);
 Node* current_node = head;


 while (current_node->pNext){
  current_node = current_node->pNext;
 }

 current_node->pNext = new_node;
 return head;
}

Node* splice_node(Node* head, int index, int data){
  Node* current_node = create_new_node(data);

  if (index == 0 || head == NULL) {
    current_node->pNext = head;
    return current_node;  
  }

  Node* temp_node = head;

  int i=0;
  while (i!=index-1)
  {
    temp_node = temp_node->pNext;
    i++;
  }

 if (temp_node != NULL) {
      current_node->pNext = temp_node->pNext;
      temp_node->pNext = current_node;
    } else {
      fprintf(stderr, "Index out of bounds.\n");
      exit(EXIT_FAILURE);
    }
    return head;
}

void print_linked_list(Node* head) {
    Node* current_node = head;
    while (current_node) {
        printf("%d->", current_node->data);
        current_node = current_node->pNext;
    }
    printf("/0\n");
	}

  int main() {
    printf("****************************\n");

    Node* head = NULL;

    head = create_new_node(12);

    head = unshift_node(head, 22);

    head = splice_node(head, 0 ,12);
    head = splice_node(head, 1 ,7);

    head =  push_node(head, 123);

    print_linked_list(head);


    printf("****************************\n");
    return 0;
}