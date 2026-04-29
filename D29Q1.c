#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, k;
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        struct Node* newNode = createNode(x);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);

    if (head == NULL || k == 0) {
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d", temp->data);
            if (temp->next != NULL) printf(" ");
            temp = temp->next;
        }
        return 0;
    }

    tail->next = head;

    int len = 1;
    struct Node* temp = head;
    while (temp->next != head) {
        len++;
        temp = temp->next;
    }

    k = k % len;

    int steps = len - k;
    struct Node* newTail = head;

    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    temp = newHead;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }

    return 0;
}
