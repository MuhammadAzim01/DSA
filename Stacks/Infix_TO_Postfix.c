#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define SIZE 50
#define emptyStackSize -1

void push(char val, int *top, char arr[]);
char pop(int *top, char arr[]);
void scanInput(char symbol);
int opPriority(char symbol);
int psnSolve(char psnStack[]);

static int psnTop = emptyStackSize;
static int opTop = emptyStackSize;

char psn[SIZE];
char operator[SIZE];

int main(void) {
    char infix[SIZE];
    int result, opLastElement;

    printf("Enter the expression:"); 
    gets(infix);

    for (int i = 0; i < strlen(infix); i++) {
        scanInput(infix[i]);
    }
    while(opTop >= 0) {
        opLastElement = pop(&opTop, operator);
        push(opLastElement, &psnTop, psn);
    }
	
	printf("PSN EXPRESION: ");
    puts(psn);
    result = psnSolve(psn);
    printf("Result: %d", result);
    return 0;
}

void push(char val, int *top, char arr[]) {
    if (*top >= SIZE - 1) {
        printf("Stack Is Full");
        exit(0);
    }
    (*top)++;
    arr[*top] = val;
}

char pop(int *top, char arr[]) {
    if (*top < 0) {
        printf("Stack is empty");
    }
    char pop = arr[*top];
    (*top)--;
    return pop;
}

void scanInput(char symbol) {
    char popElement;
    switch(symbol) {
        case '0' ... '9':
            push(symbol, &psnTop, psn);
            break;
        case '(':
            push(symbol, &opTop, operator);
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (opPriority(symbol) <= opPriority(operator[opTop])) {
                popElement = pop(&opTop, operator);
                push(popElement, &psnTop, psn);
            }
            push(symbol, &opTop, operator);
            break;
            
        case ')':            
			while(operator[opTop] != '(') { 
                popElement = pop(&opTop, operator);
                push(popElement, &psnTop, psn);
            }
            pop(&opTop, operator);
            break;
    }
}

int opPriority(char symbol) {
    if (symbol == '^') {
        return 3;
    } else if (symbol == '*' || symbol == '/') {
        return 2;
    } else if (symbol == '+' || symbol == '-') {
        return 1;
    } else {
        return 0;
    }
}

int psnSolve(char psnStack[]) {
    int result[SIZE], a, b;
    int resultTop = -1;

    for(int i = 0; i < strlen(psnStack); i++) {
        if ( isdigit(psnStack[i]) )
        {
            resultTop++;
            result[resultTop] = psnStack[i] - '0';
        }
        a = result[resultTop - 1];
        b = result[resultTop];

        if (psnStack[i] == '+') {
            result[resultTop - 1] = a + b;
            resultTop--;
        } else if (psnStack[i] == '-') {
            result[resultTop - 1] = a - b;
            resultTop--;
        } else if (psnStack[i] == '/') {
            result[resultTop - 1] = a / b;
            resultTop--;
        } else if (psnStack[i] == '*') {
            result[resultTop - 1] = a * b;
            resultTop--;
        } else if (psnStack[i] == '^') {
            result[resultTop - 1] = pow(a, b);
            resultTop--;
        }
    }

    return result[0];
}