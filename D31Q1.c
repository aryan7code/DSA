#include <stdio.h>

int stack[1000];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) return;

    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i != 0) printf(" ");
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int x;
            scanf("%d", &x);
            push(x);
        } else if (type == 2) {
            pop();
        } else if (type == 3) {
            display();
        }
    }

    return 0;
}
