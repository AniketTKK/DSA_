A code to reverse a linked list using recursion
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct node {
  int data;
  struct node *next;
};

// A function to create a new node and return its pointer
struct node *create_node(int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// A function to print the linked list
void print_list(struct node *head) {
  struct node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// A recursive function to reverse the linked list and return the new head
struct node *reverse_list(struct node *head) {
  // Base case: if the list is empty or has one node, return the head
  if (head == NULL || head->next == NULL) {
    return head;
  }
  // Recursive case: reverse the rest of the list and make the current head point to NULL
  struct node *new_head = reverse_list(head->next);
  head->next->next = head;
  head->next = NULL;
  return new_head;
}

int main() {
  // Create a sample linked list
  struct node *head = create_node(1);
  head->next = create_node(2);
  head->next->next = create_node(3);
  head->next->next->next = create_node(4);
  head->next->next->next->next = create_node(5);

  // Print the original list
  printf("Original list: ");
  print_list(head);

  // Reverse the list using recursion and print the reversed list
  head = reverse_list(head);
  printf("Reversed list: ");
  print_list(head);

  return 0;
}

