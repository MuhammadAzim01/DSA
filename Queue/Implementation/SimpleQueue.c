#include <stdio.h>
#define SIZE 5

void enQueue(int arr[], int *rear, int *front, int val);
void deQueue(int arr[], int *front, int *rear); 
void display(int arr[], int front, int rear);

int main () {
    int front = -1, rear = -1, arr[SIZE];


    for (int i = 0; i < SIZE; i++) {
        enQueue(arr, &rear, &front, i);
    }
    
    deQueue(arr, &front, &rear);

    display(arr, front, rear);

}

void enQueue(int arr[], int *rear, int *front, int val) {
    if ( *rear == SIZE - 1) {
        printf("Queue is Full\n");
    } else {
        if (*front == -1) {
            *front = 0;
        }
        (*rear) +=1;
        arr[(*rear)] = val;
        printf("Added Succesfully\n");
    }

}

void deQueue(int arr[], int *front, int *rear) {
    if (*front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("\nDeleted Element : %d", arr[(*front)]);
        if (*front == *rear) {
            *front = -1;
            *rear = -1;
        } else {
            (*front) +=1;
        }
        
    }
}

void display(int arr[], int front, int rear) {
    printf("\nElements are: ");
    for (int i = front; i <= rear; i++) {
        printf("\t%d\t", arr[i]);
    }

}
