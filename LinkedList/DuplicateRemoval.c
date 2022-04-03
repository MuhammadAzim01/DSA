/*
Write a program that should delete duplicate nodes from linked list
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void create(int data);
void display();
void removeDuplicates();

Node *head = NULL, *tail;

int main() {

    create(1);
    create(2);
    create(2);
    create(3);
    create(2);
    create(5);
    create(5);
    create(5);
    create(5);
    create(5);
    create(4);

    removeDuplicates();
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

void removeDuplicates() {
    Node *currentNode = head, *nextNode, *previousNode;

    while (currentNode->next != NULL) {
        nextNode = currentNode;
        while (nextNode->next != NULL) {
            previousNode = nextNode;
            nextNode = nextNode->next;
            if (currentNode->data == nextNode->data) {
                previousNode->next = nextNode->next;
                free(nextNode);
                nextNode = previousNode; 
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

