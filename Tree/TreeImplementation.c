#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int data;
    struct Tree *leftLink, *rightLink;
} Tree;

void insert(Tree **root, int data);
void displayInOrder(Tree *root);
void displayPostOrder(Tree *root);
void displayPreOrder(Tree *root);
bool searchNode(Tree *root, Tree **currentNode, Tree **previousNode, int searchItem);
void deleteNode(Tree *root, int delItem);
Tree *searchMinNode(Tree *root);
Tree *searchMaxNode(Tree *root);

int main() {
    Tree *rootNode = NULL, *lastSearchNode = NULL;
    Tree *tempNode;
    int num;

    insert(&rootNode, 45);
    insert(&rootNode, 15);
    insert(&rootNode, 60);
    insert(&rootNode, 12);
    insert(&rootNode, 97);
    insert(&rootNode, 4);
    insert(&rootNode, 30);
    insert(&rootNode, 150);
    insert(&rootNode, 11);
    insert(&rootNode, 55);
    insert(&rootNode, 85);
    insert(&rootNode, 37);
    insert(&rootNode, 32);


    while (true) {
        printf("\n\n\t\t\tBST Implementation\n\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search any Node\n");
        printf("4. Search Min Node\n");
        printf("5. Search Max Node\n");
        printf("6. Exit\n");

        printf("Choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter any Number to Insert: ");
                scanf("%d", &num);

                insert(&rootNode, num);
                break;
            case 2:
                printf("\nEnter any Number to Delete: ");
                scanf("%d", &num);

                deleteNode(rootNode, num);

                break;
            case 3:
                printf("\nEnter any Number to search: ");
                scanf("%d", &num);

                Tree *previousNode, *currentNode;
                bool isFound = searchNode(rootNode,&currentNode,&previousNode,num);

                isFound ? printf("\nFound\n") : printf("\nNot Found\n");
                break;
            case 4:
                tempNode = searchMinNode(rootNode);

                printf("\nMin Node: %d\n", tempNode->data);
                break;
            case 5:
                tempNode = searchMaxNode(rootNode);

                printf("\nMax Node: %d\n", tempNode->data);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Error ! Enter Again\n");
        }

        printf("\nInorder: ");
        displayInOrder(rootNode);

        printf("\nPostorder: ");
        displayPostOrder(rootNode);

        printf("\nPreorder: ");
        displayPreOrder(rootNode);

    }


}

void insert(Tree **root, int data) {
    Tree *newNode = *root;
    if (*root == NULL) {
        newNode = (Tree *) malloc (sizeof (Tree));
        newNode->data = data;
        newNode->leftLink = NULL;
        newNode->rightLink = NULL;
        *root = newNode;
    }
    if (newNode->data > data) {
        insert(&newNode->leftLink, data);
    } else if (newNode->data < data) {
        insert(&newNode->rightLink, data);
    }
}

void displayInOrder(Tree *root) {
    if (root!= NULL) {
        displayInOrder(root->leftLink);
        printf("%d\t", root->data);
        displayInOrder(root->rightLink);
    }
}

void displayPostOrder(Tree *root) {
    if (root!= NULL) {
        displayPostOrder(root->leftLink);
        displayPostOrder(root->rightLink);
        printf ("%d\t", root->data);
    }
}

void displayPreOrder(Tree *root) {
    if (root != NULL) {
        displayPreOrder(root->leftLink);
        printf ("%d\t", root->data);
        displayPreOrder(root->rightLink);
    }
}

bool searchNode(Tree *root, Tree **currentNode, Tree **previousNode, int searchItem) {
    while (root != NULL) {
        if (searchItem == root->data) {
            *currentNode = root;
            return true;
        }
        else if (searchItem > root->data) {
            *previousNode = root;
            root = root->rightLink;

        } else if (searchItem < root->data) {
            *previousNode = root;
            root = root->leftLink;

        }
    }
    return false;
}

void deleteNode(Tree *root, int delItem) {
    Tree *targetNode, *previousNode;
    if(!(searchNode(root, &targetNode, &previousNode, delItem))){
        printf("Searched Value(%d) not found\n", delItem);
        return;
    }

    if (targetNode->leftLink == NULL && targetNode->rightLink == NULL) {
        if (previousNode->data > delItem)
            previousNode->leftLink = NULL;
        else
            previousNode->rightLink = NULL;

    } else if (targetNode->leftLink == NULL) {
        if (previousNode->data > delItem)
            previousNode->leftLink = targetNode->rightLink;
        else
            previousNode->rightLink = targetNode->rightLink;

    } else if (targetNode->rightLink == NULL) {
        if (previousNode->data > delItem)
            previousNode->leftLink = targetNode->leftLink;
        else
            previousNode->rightLink = targetNode->leftLink;

    } else if (targetNode->leftLink != NULL && targetNode->rightLink != NULL) {
        int flag = 0;
        Tree *temp = targetNode;

        previousNode = targetNode;
        targetNode = targetNode->rightLink;

        while (targetNode->leftLink != NULL) {
            previousNode = targetNode;
            targetNode = targetNode->leftLink;
            flag = 1;
        }
        temp->data = targetNode->data;
        if (flag == 1)
            previousNode->leftLink = NULL;
        else
            previousNode->rightLink = NULL;

    }
    free (targetNode);

}

Tree *searchMinNode(Tree *root) {
    while (root->leftLink != NULL) {
        root = root->leftLink;
    }
    return root;
}

Tree *searchMaxNode(Tree *root) {
    while (root->rightLink != NULL) {
        root = root->rightLink;
    }
    return root;
}
