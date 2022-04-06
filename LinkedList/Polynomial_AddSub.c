/*
 Write a program that add/subtract 2 polynomials.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct {
    int number;
    int power;
} Data;

typedef struct Node{
    Data data;
    struct Node *next;
}Node;

void scanExpression(char expression[], Node **head, Node **tail);
void create(Node **head, Node **tail, int number, int power); 
void concatenate(Node *head1, Node *head2, Node **resultantHead, Node **resultantTail, int choice); 
void evaluatePolynomials(Node *head1, Node *head2, Node **resultantNode, int choice);
void display(Node *head);

int main(void) {
    Node *head1, *head2, *tail1, *tail2;
    head1 = head2 = NULL;
    char polynomialExpression[100];

    printf("\nEnter First Polynomial: ");
    gets(polynomialExpression);

    scanExpression(polynomialExpression, &head1, &tail1);

    printf("\nEnter second Polynomial: ");
    gets(polynomialExpression);

    scanExpression(polynomialExpression, &head2, &tail2);
    Node *resultHead;
    int choice;

    do {
        printf("\n\n\nMenu\n");
        printf("1.Add\n");
        printf("2.Subtract\n");
        printf("3.Exit\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            evaluatePolynomials(head1, head2, &resultHead, 1);
            printf("After Sum: ");
            display(resultHead);
            break;
        case 2:
            evaluatePolynomials(head1, head2, &resultHead, 2);
            printf("After Subtraction: ");
            display(resultHead);
            break;
        case 3:
            printf("\nExiting");
            break;
        default:
            printf("Wrong Choice! try again\n");
            break;
        }

    } while (choice != 3);

    return 0;
}

void create(Node **head, Node **tail, int number, int power) {
    Node *newNode;
    
    if (*head == NULL) {
        *head = (Node *) malloc (sizeof (Node));
        (*head)->data.number = number;
        (*head)->data.power = power;
        (*head)->next = NULL;
        *tail = *head;
    } else {
        newNode = (Node* ) malloc(sizeof(Node));
        newNode->data.number = number;
        newNode->data.power = power;
        newNode->next = NULL;
        (*tail)->next = newNode; 
        *tail = newNode; 
    }
}

void scanExpression(char expression[], Node **head, Node **tail) {
    int number, numberSign, power, powerSign, flag;
    number = flag = power = 0;
    numberSign = powerSign = 1;
    
    for (int i = 0; i < strlen(expression); i++) {
        if (isdigit(expression[i]) && flag == 0) {
            number = number * 10 + (expression[i] - '0');
        } else if (expression[i] == '^') {
            flag = 1;
        } else if (isdigit(expression[i]) && flag == 1) {
            power = power * 10 + (expression[i] - '0');
        }
        if ((expression[i] == '+' || expression[i] == '-') && (expression[i-1] != '^')) {
            number *= numberSign;
            power *= powerSign;
            if (i != 0) 
                create(*(&head), *(&tail), number, power);
           
            number = power = flag = 0;
            powerSign = 1;
            numberSign = 1;

            if (expression[i] == '-') {
                numberSign = -1;
            }
            
        } else if ((expression[i] == '-' || expression[i] == '+') && (expression[i-1] == '^')) {
                powerSign = 1;
            if (expression[i] == '-')
                powerSign = -1;        
        }
    }
    number *= numberSign;
    power *= powerSign;
    create(*(&head), *(&tail), number, power);
}

void display(Node *head) {
    Node *traverseNode = head;

    while (traverseNode != NULL) {
        if(traverseNode->data.number != 0) {
            if(traverseNode->data.number > 0) 
                printf("+");
            if (traverseNode->data.power == 0) {
                printf("%d", traverseNode->data.number);    
            } else {
                printf("%dx^", traverseNode->data.number);
                printf("%d ", traverseNode->data.power);
            }
        }
        traverseNode = traverseNode->next;
    }
}

void concatenate(Node *head1, Node *head2, Node **resultantHead, Node **resultantTail, int choice) {
    Node *traverseNode = head1;
    int flag = 0;
    int number;

    do{
        if (flag == 1 && choice == 2) {
            number = traverseNode->data.number * -1; 
            create(*(&resultantHead), *(&resultantTail), number, traverseNode->data.power);        
        } else {
            create(*(&resultantHead), *(&resultantTail), traverseNode->data.number, traverseNode->data.power);    
        }
        traverseNode = traverseNode->next;
        if (traverseNode == NULL && flag == 0) {
            traverseNode = head2;
            flag = 1;
        }
    } while (traverseNode != NULL);
}

void evaluatePolynomials(Node *head1,Node *head2,Node **resultantHead, int choice) {
    Node *resultantTail;
    *resultantHead = NULL;
    concatenate(head1, head2, *(&resultantHead), &resultantTail, choice);
    
    Node *traverseNode = *resultantHead, *currentNode, *previousNode;

    while (traverseNode != NULL) {
        currentNode = traverseNode;
        while (currentNode->next != NULL) {
            previousNode = currentNode;
            currentNode = currentNode->next;
            if (traverseNode->data.power == currentNode->data.power) {
                traverseNode->data.number += currentNode->data.number;
                previousNode->next = currentNode->next;
                free(currentNode);
                currentNode = previousNode; 
            }
        }
        traverseNode = traverseNode->next;   
    }
}
