#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  // struct Node *prev;
} Node;

void insert_head(Node **head, int value) {
  Node *new_node = malloc(sizeof(Node));

  if (new_node == NULL) {
    printf("failed to allocated memory\n");
    return;
  }

  new_node->data = value;

  new_node->next = *head;

  *head = new_node;
}

void print_list(Node *head) {
  Node *current = head;
  while (current != NULL) {
    printf("%d->", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

int main() {

  Node *head = NULL;

  insert_head(&head, 20);
  insert_head(&head, 50);
  insert_head(&head, 33);

  printf("Linked list\n");
  print_list(head);

  free(head);

  return 0;
}
