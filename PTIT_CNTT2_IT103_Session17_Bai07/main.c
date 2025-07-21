#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed for Node\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addValueToTree(Node** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
        printf("Added %d to the tree\n", value);
        return;
    }

    Node* currentNode = *root;
    while (currentNode != NULL) {
        if (value < currentNode->data) {
            if (currentNode->left == NULL) {
                currentNode->left = createNode(value);
                printf("Added %d to the left of %d\n", value, currentNode->data);
                return;
            }
            currentNode = currentNode->left;
        } else {
            if (currentNode->right == NULL) {
                currentNode->right = createNode(value);
                printf("Added %d to the right of %d\n", value, currentNode->data);
                return;
            }
            currentNode = currentNode->right;
        }
    }
}

void printTree(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d\n", root->data);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    addValueToTree(&root, 6);
    printTree(root);
    return 0;
}
