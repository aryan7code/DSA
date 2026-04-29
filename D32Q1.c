#include <stdio.h>

int stack[100000];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

void pop() {
    if (top != -1) {
        top--;
    }
}

void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i != 0) printf(" ");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        push(x);
    }

    int m;
    scanf("%d", &m);

    while (m-- && top != -1) {
        pop();
    }

    display();

    return 0;
}
