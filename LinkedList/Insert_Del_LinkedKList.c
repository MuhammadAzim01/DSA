#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void display();
void create(int data);
void insertAtStrt(int data);
void insertAtN(int data, int pos);
void insertAtEnd(int data);
void delAtStrt();
void delAtPos(int pos);
void delAtEnd();
int getVal(char pos[]);

Node *head, *tail, *n; // here n is new node
int val; // to get data from user to insert

int main(void) {

    for (int i = 0; i < 5; i++)
    {
        create(i+1);
    }

    int insrtDelChoice, desiredPos;
    do{
        printf("\n\n\t\t\tTesting Linked List\n\n");
        printf("1.Insertion At Start\n");
        printf("2.Insertion At Desired Position\n");
        printf("3.Insertion At End\n");
        printf("4.Deletion at Start\n");
        printf("5.Deletion at Desired Position\n");
        printf("6.Deletion at End\n");
        printf("7.Display\n");
        printf("8.Exit\n");
        printf("\nInput: ");

        scanf("%d", &insrtDelChoice);

        switch(insrtDelChoice) {
            case 1:
                val = getVal("start");
                insertAtStrt(val);
                break;
            case 2:
                val = getVal("Desired Pos");

                printf("\nEnter the positon (greater than 1): ");
                scanf("%d", &desiredPos);

                insertAtN(val, desiredPos);
                break;
            case 3:
                val = getVal("End");
                insertAtEnd(val);
                break;
            case 4:
                delAtStrt();
                break;
            case 5:
                do {
                    printf("\nEnter the positon(greater than 1): ");
                    scanf("%d", &desiredPos);
                } while (desiredPos < 1);
                
                delAtPos(desiredPos);
                break;
            case 6:
                delAtEnd();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting...");
                break;
            default:
                printf("\nWrong Choice! Try Again\n");

        }
    } while (insrtDelChoice != 8);
    return 0;
}

//Display linked List
void display() {
    if (head == NULL) {
        printf("\nEmpty\n");
    }else {
        tail = head;
        printf("\n");
        while (tail != NULL) {
            printf("Data: %d\n", tail->data);
            tail = tail->next;
        }
    }
}
//                                           Creation
void create(int data) {
    if (head == NULL) {
        head = (Node* ) malloc(sizeof(Node)); // malloc function returns void pointer (we can't derefrence the pointer) so we use typecast 
        head->data = data;
        head->next = NULL;
        tail = head;
    } else {
        n = (Node* ) malloc(sizeof(Node));
        n->data = data;
        n->next = NULL;
        tail->next = n; // link new node with last node
        tail = n; // updating the last node to the new node
    }
}
// Get Value From user
int getVal(char pos[]) {
    printf("\nEnter the Value at %s: ", pos);
    scanf("%d", &val);
    return val;
}
//                                   Insertion 
void insertAtStrt(int data) {
    n = (Node* ) malloc(sizeof(Node));
    n->data = data;
    n->next = head;
    head = n;
}

void insertAtN(int data, int pos) {
    if (pos < 1) {  //incase entered pos is less than 1 then insert at start
        insertAtStrt(data);
    } else {
        int count = 1;
        Node *pre; // to store previous node of n

        tail = head;

        while (count != pos){
            pre = tail;
            tail = tail->next;
            count++;
        }
        //Inserting New node
        n = (Node* ) malloc(sizeof(Node));
        n->data = data;
        //linking new node
        n->next = tail;
        pre->next = n;  
    }
    
}

void insertAtEnd(int data) {
    tail = head;

    while (tail->next != NULL) {
        tail = tail->next;
    }
    //Inserting New Node
    n = (Node* ) malloc(sizeof(Node));
    n->data = data;
    n->next = NULL; //as last node always has null pointer in next link
    tail->next = n; // updating next line of previously last node
}
//                                      Deletion
void delAtStrt(){
    if (head == NULL) {
        printf("Linked List Is Empty");
        return;
    }
    tail = head;
    head = tail->next;
    free(tail);
}

void delAtPos(int pos) {
    if (head == NULL || pos < 1) {
        printf("Linked List Is Empty");
        return;
    }

    if (pos == 1) { 
        delAtStrt();
    } else {
        int count = 1;
        Node *pre;
        
        tail = head;
        while (count != pos) {
            pre = tail;
            tail = tail->next;
            count++;
        }

        pre->next = tail->next;
        free(tail);
    }

}

void delAtEnd() {
    if (head == NULL) {
        printf("Linked List Is Empty");
        return;
    }
    Node *last; 
       
    tail = head;
    while (tail->next != NULL) {
        last = tail;
        tail = tail->next;
    }

    free(tail); //deleting Current last node
    last->next = NULL;
}
