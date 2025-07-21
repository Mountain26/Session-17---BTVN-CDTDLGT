#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
typedef struct Queue {
    Node* data[100];
    int front, rear;
} Queue;
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}
int isEmpty(Queue* q) {
    return q->front == q->rear;
}
void enqueue(Queue* q, Node* node) {
    if (q->rear < 100) {
        q->data[q->rear++] = node;
    }
}
Node* dequeue(Queue* q) {
    if (!isEmpty(q)) {
        return q->data[q->front++];
    }
    return NULL;
}
int findValueBFS(Node* root, int value) {
    if (root == NULL) return 0;
    Queue q;
    initQueue(&q);
    enqueue(&q, root);
    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);
        if (current->data == value) {
            return 1;
        }
        if (current->left != NULL) enqueue(&q, current->left);
        if (current->right != NULL) enqueue(&q, current->right);
    }

    return 0;
}
int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int valueToFind = 3;
    printf("Phan tu ban muon tim: %d\n", valueToFind);

    if (findValueBFS(root, valueToFind)) {
        printf("true");
    } else {
        printf("false");
    }
    return 0;
}