/*
Write a program that split a single linked list into three linked lists. Assume that initial link list has 30 nodes.
*/
#include<stdio.h>
#include<stdlib.h>

#define SIZE 30

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void create(int data);
void display(Node **head);
void splilSingleLinkedList(int pos1, int pos2);

Node *n, *tmp, *head, *tail, *head1, *head2, *head3, *pre;

int main(void) {
    head = NULL;
    for (int i = 1; i <= SIZE; i++)
    {
        create(i);
    }

    int pos[2];
    for (int i = 0; i < 2; i++){
        printf("Enter the point %d to break: ", i+1);
        scanf("%d", &pos[i]);
    }
    
    splilSingleLinkedList(pos[0], pos[1]);

    printf("\nLinked List 1: ");
    display(&head1);

    printf("\nLinked List 2: ");
    display(&head2);

    printf("\nLinked List 3: ");
    display(&head3);

    return 0;
}

void create(int data) {
    if (head == NULL) {
        head = (Node *) malloc (sizeof (Node));
        head->data = data;
        head->next = NULL;
        tail = head;
    } else {
        n = (Node* ) malloc(sizeof(Node));
        n->data = data;
        n->next = NULL;
        tail->next = n; 
        tail = n; 
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

void splilSingleLinkedList(int pos1, int pos2) {
    head1 = tail = head;
    int count = 1;

    while (tail != NULL) {
        pre = tail;
        tail = tail->next;
        if (count == pos1) {
            pre->next = NULL;
            head2 = tail;
        } else if (count == pos2) {
            pre->next = NULL;
            head3 = tail;
        }
        count++;
    } 
}