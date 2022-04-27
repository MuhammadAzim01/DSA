#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

struct Coordinates{
    int x;
    int y;
};

typedef struct{
   char ch;
   struct Coordinates coordinate;
   struct Node* next;
}Node;

void displayBoard();
void gotoXY(int x, int y);
void hidecursor();
void createRandNode();
void displayCharacters();
void deleteAlphabet(char ch);
void updateLinkList();

int hit = 0, miss = 0 ;
int startX = 20, endX = 90;
int startY = 8, endY = 32;
Node *head, *last;

void main() {
    srand(time(NULL));

    while (miss != 30) {
        hidecursor();
        system("cls");
        createRandNode();
        displayBoard();
        displayCharacters();
        updateLinkList();
        if (kbhit()) {
            char ch = getch();
            deleteAlphabet(ch);
        }
        Sleep(1000);
    }

}

void createRandNode(){
    int charUpperBound = 90, charLowerBound = 65;
    char c = (rand()%(charUpperBound - charLowerBound + 1))+ charLowerBound; //65 is ASCII for capital A, 90 is ASCII for capital Z

    Node *newNode =(Node *) malloc (sizeof(Node));
    newNode->ch = c;
    newNode->coordinate.x = (rand() %( 24 - 80 + 1)) + 24;
    newNode->coordinate.y = startY + 1;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        last = newNode;
    } else {
       last->next = newNode;
       last = newNode;
    }
}

void displayCharacters() {
    Node *current = head;
    while(current != NULL){
       gotoXY(current->coordinate.x, current->coordinate.y);
       printf("%c ", current->ch);
       current = current->next;
    }
}

void deleteAlphabet(char ch) {
    Node *pre = NULL, *current = head;

    while(current != NULL) {
        if(current->ch == toupper(ch)) {
            if(pre == NULL) {
                head = current->next;
                free(current);

            } else {
                pre->next = current->next;
                free(current);
            }

            hit++;
            break;
        }

        pre = current;
        current = current->next;
    }
}

void updateLinkList() {
    Node *current = head;

    while (current != NULL) {
        if(current->coordinate.y >= endY) {
            head = current->next;
            free(current);
            current = head;
            miss++;
            continue;
        }

        current->coordinate.y += 1;
        current = current->next;
    }
}

void displayBoard() {
    char verticalBoardCharacter = 219;
    char horizontalBoardCharacter = 220;

    gotoXY(43, 6);
    printf("Typing Tutor game");
    // upper horizontal line
    for(int i = startX; i <= endX; i++) {
        gotoXY(i, startY);
        printf("%c", horizontalBoardCharacter);
    }
    // vertical lines
    for(int i = startY; i < endY; i++) {
        gotoXY(startX, i + 1);
        printf("%c", verticalBoardCharacter);
        gotoXY(endX, i + 1);
        printf("%c", verticalBoardCharacter);
    }
    //lower horizontal line
    for(int i = startX + 2; i <= endX; i++) {
        gotoXY(i - 1, endY);
        printf("%c", horizontalBoardCharacter);
    }
    gotoXY(20, endY+1);
    printf("HIT: %d                                MISS: %d", hit, miss);
}

void gotoXY(int x, int y) {
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
