#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;

    if (front == NULL) {
        front = rear = temp;
        temp->next = front;
    } else {
        rear->next = temp;
        rear = temp;
        rear->next = front;
    }
}

void dequeue() {
    if (front == NULL) return;

    if (front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        Node* temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display() {
    if (front == NULL) return;

    Node* temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
}

int main() {
    int n, m;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}
