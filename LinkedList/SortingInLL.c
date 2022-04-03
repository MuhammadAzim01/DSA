/*
Write a program that should sort values of nodes of Linked List
*/
#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void create(int data);
void sort();
void display();

Node *head = NULL, *tail;

int main(void) {
    
    create(7);
    create(3);
    create(2);
    create(4);
    create(8);
    create(10);
    create(12);
    create(11);
    sort();
    display();

    return 0;
}

void create(int data) {
    if (head == NULL) {
        head = (Node *) malloc (sizeof (Node));
        head->data = data;
        head->next = NULL;
        tail = head;
    } else {
        Node *newNode = (Node *) malloc (sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        tail->next = newNode; 
        tail = newNode; 
    }
}

void sort() {
    Node *currentNode, *nextNode;
    int temp;

    currentNode = head;

    while (currentNode != NULL) {
        nextNode = currentNode;
        while (nextNode->next != NULL) {
            nextNode = nextNode->next;
            if (currentNode->data > nextNode->data) {
                temp = currentNode->data;
                currentNode->data =  nextNode->data;
                nextNode->data = temp;
            }
        }
        currentNode = currentNode->next;   
    }
}

void display() {
    if (head == NULL) {
        printf("\nEmpty\n");
    } else {
        tail = head;
        printf("\n");
        while (tail != NULL) {
            printf("Data: %d\n", tail->data);
            tail = tail->next;
        }
    }
}


