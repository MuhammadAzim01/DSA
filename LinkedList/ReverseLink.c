/*
Write a program that should reverse values of nodes of Linked List
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void create(int data);
void display();
int countNodes();
void reverseLL(int arrSize);

Node *head = NULL, *tail;

int main() {

    create(9);
    create(8);
    create(7);
    create(6);
    create(5);

    int nodeSize = countNodes();

    reverseLL(nodeSize);
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

void reverseLL(int arrSize) {
    int *arr = (int *) malloc (arrSize * sizeof(int));
    int i = 0;
    Node *currentNode = head;


    while (currentNode != NULL) { //Storing values of nodes of LL in Array
        arr[i] = currentNode->data;
        currentNode = currentNode->next;
        i++;
    }

    currentNode = head;
    i = arrSize - 1;
    while (currentNode != NULL) {
        currentNode->data = arr[i];
        currentNode = currentNode->next;
        i--;
    }
    free(arr); // to free the space
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

int countNodes() {
    int count = 1;
    tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        count++;
    }
    return count;
}