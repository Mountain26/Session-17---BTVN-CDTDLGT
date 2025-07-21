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
int findValueInTree(Node* root, int value) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == value) {
        return root->data;
    }
    int foundInLeft = findValueInTree(root->left, value);
    if (foundInLeft != -1) {
        return foundInLeft;
    }
    int foundInRight = findValueInTree(root->right, value);
    if (foundInRight != -1) {
        return foundInRight;
    }
    return -1;
}
int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    int valueToFind = 3;
    int result = findValueInTree(root, valueToFind);
    if (result != -1) {
        printf("Value %d found in the tree.\n", result);
    } else {
        printf("Value %d not found in the tree.\n", valueToFind);
    }
    return 0;
}
