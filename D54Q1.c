#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n) {
    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if (l < n)
                nodes[i]->left = nodes[l];
            if (r < n)
                nodes[i]->right = nodes[r];
        }
    }

    return nodes[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* queue[1000];
    int front = 0, rear = 0;

    struct Node* root = buildTree(arr, n);

    if (root == NULL)
        return 0;

    queue[rear++] = root;

    int leftToRight = 1;

    while (front < rear) {
        int levelSize = rear - front;
        int level[levelSize];

        for (int i = 0; i < levelSize; i++) {
            struct Node* temp = queue[front++];
            level[i] = temp->data;

            if (temp->left)
                queue[rear++] = temp->left;
            if (temp->right)
                queue[rear++] = temp->right;
        }

        if (!leftToRight) {
            for (int i = levelSize - 1; i >= 0; i--)
                printf("%d ", level[i]);
        } else {
            for (int i = 0; i < levelSize; i++)
                printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
    }

    return 0;
}
