#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == NULL) return 0;
    Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int isOperator(char* token) {
    return (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'));
}

int main() {
    char expr[1000];
    fgets(expr, sizeof(expr), stdin);

    char* token = strtok(expr, " \n");

    while (token != NULL) {
        if (!isOperator(token)) {
            push(atoi(token));
        } else {
            int b = pop();
            int a = pop();
            char op = token[0];

            if (op == '+') push(a + b);
            else if (op == '-') push(a - b);
            else if (op == '*') push(a * b);
            else if (op == '/') push(a / b);
        }
        token = strtok(NULL, " \n");
    }

    printf("%d", pop());

    return 0;
}
