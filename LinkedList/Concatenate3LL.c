/*
 Write a program that concatentes 3 linked list into one link list.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void create(Node **head, Node **tail, int data);
void display(Node **head);

Node *n, *tmp;

int main(void) {
    Node *head1, *head2, *head3, *tail1, *tail2, *tail3;
    head1 = head2 = head3 = NULL;
    
    for (int i = 1; i <= 5; i++)
    {
        create(&head1, &tail1, i);
        create(&head2, &tail2, (i * 2));
        create(&head3, &tail3, (i * 3));
    }

    Node *tmp = head1;
    int flag = 0;
    
    do {
        tmp = tmp->next;
        if (tmp->next == NULL && flag == 0) {
            tmp->next = head2;
            flag++;
        } else if (tmp->next == NULL && flag == 1) {
            tmp->next = head3;
            flag++;
        }
    } while(tmp->next != NULL);

    display(&head1);
    return 0;
}

void create(Node **head, Node **tail, int data) {
    if (*head == NULL) {
        *head = (Node *) malloc (sizeof (Node));
        (*head)->data = data;
        (*head)->next = NULL;
        *tail = *head;
    } else {
        n = (Node* ) malloc(sizeof(Node));
        n->data = data;
        n->next = NULL;
        (*tail)->next = n; // link new node with last node
        *tail = n; // Updating last node by assigining to new node
    }
}

void display(Node **head) {
    tmp = *head;

    printf("\n");
    while (tmp != NULL) {
        printf("Data: %d\n", tmp->data);
        tmp = tmp->next;
    }
}
