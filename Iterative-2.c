 #include <stdio.h>

struct node {
  int data;
  struct node *next;
};

void reverse(struct node **head) {
  struct node *prev = NULL;
  struct node *curr = *head;
  struct node *next = NULL;
  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head = prev;
}

int main() {
  struct node *head = NULL;
  struct node *node1 = malloc(sizeof(struct node));
  struct node *node2 = malloc(sizeof(struct node));
  struct node *node3 = malloc(sizeof(struct node));

  node1->data = 1;
  node1->next = node2;

  node2->data = 2;
  node2->next = node3;

  node3->data = 3;
  node3->next = NULL;

  head = node1;

  printf("the Og linked list: ");
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");

  reverse(&head);

  printf("the reversed linked list is : ");
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");

  return 0;
}

