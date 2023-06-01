Backtracking algorithm using linked list data structure
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertAtEnd(int x) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node *temp1 = head, *temp2 = head->next;

    while (temp2->next != NULL) {
        temp1 = temp2;
        temp2 = temp2->next;
    }

    free(temp2);

    temp1->next = NULL;
}

void printList() {
    struct node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void backtrackingUsingLinkedList(int n, int k) {

}

int main() {
//     int n, k, i, j, count=0, flag=0, m=0, l=0, r=0, p=0, q=0, s=0, t=0, u=0, v=0, w=0, x=0, y=0, z=0;

//     printf("Enter the number of queens: ");
//     scanf("%d", &n);

//     backtrackingUsingLinkedList(n);

//     return 0;

}
