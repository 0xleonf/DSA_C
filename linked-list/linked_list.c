#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

struct Node *create_node(int value) {
  struct Node *new_node = malloc(sizeof(struct Node));

  new_node->data = value;

  new_node->prev = NULL;
  new_node->next = NULL;

  return new_node;
}

void insert_head(Node **head, int value) {
  Node *new_node = create_node(value);

  if (*head == NULL) {
    *head = new_node;
    return;
  }

  new_node->next = *head;
  (*head)->prev = new_node;
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
