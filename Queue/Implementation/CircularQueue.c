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
    deQueue(arr, &front, &rear);
    deQueue(arr, &front, &rear);
    enQueue(arr, &rear, &front, 99);
    enQueue(arr, &rear, &front, 66);
    enQueue(arr, &rear, &front, 677);

    display(arr, front, rear);

}

void enQueue(int arr[], int *rear, int *front, int val) {
    if ( (*front == 0 && *rear == SIZE - 1)|| ((*rear) + 1) == *front) {
        printf("Queue is Full\n");
    } else {
        *rear = ((*rear) + 1) % SIZE;
        arr[(*rear)] = val;

        if (*front == -1) {
            *front = 0;
        }
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
            *front = ((*front) + 1) % SIZE;;
        }
    }
}

void display(int arr[], int front, int rear) {
    int i = front;
    for(i; i!= rear; i++){
		if (i == SIZE-1) {
            printf("\n%d",arr[i]);
			i = 0;
		}	
		printf("\n%d",arr[i]);
	}

	printf("\n%d\n",arr[i]);
}

