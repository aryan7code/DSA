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

void verticalOrderUtil(struct Node* root, int hd, int *min, int *max) {
    if (root == NULL)
        return;

    if (hd < *min)
        *min = hd;
    if (hd > *max)
        *max = hd;

    verticalOrderUtil(root->left, hd - 1, min, max);
    verticalOrderUtil(root->right, hd + 1, min, max);
}

void printVertical(struct Node* root, int targetHd, int currentHd) {
    if (root == NULL)
        return;

    if (currentHd == targetHd)
        printf("%d ", root->data);

    printVertical(root->left, targetHd, currentHd - 1);
    printVertical(root->right, targetHd, currentHd + 1);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    int min = 0, max = 0;

    verticalOrderUtil(root, 0, &min, &max);

    for (int hd = min; hd <= max; hd++) {
        printVertical(root, hd, 0);
        printf("\n");
    }

    return 0;
}
