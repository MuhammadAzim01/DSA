/*
Write a program that should count nodes with even values
*/
#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void create(int data);
int countEven(); 

Node *n, *head = NULL, *tail;

int main(void) {
    int val;
    for (int i = 1; i <= SIZE; i++)
    {
        printf("\nEnter the value: ");
        scanf("%d", &val);
        create(val);
    }

    int evenNo = countEven();

    printf("No of even numbers are : %d", evenNo);
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

int countEven() {
    tail = head;
    int countEven = 0;

    while (tail != NULL) {
        if ((tail->data % 2) == 0) {
            countEven++;
        }
        tail = tail->next;
    }

    return countEven;
}

