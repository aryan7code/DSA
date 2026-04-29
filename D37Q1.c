#include <stdio.h>
#include <string.h>

int arr[1000];
int size = 0;

void insert(int x) {
    arr[size] = x;
    size++;
}

int deleteElement() {
    if (size == 0)
        return -1;

    int minIndex = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIndex])
            minIndex = i;
    }

    int deleted = arr[minIndex];

    for (int i = minIndex; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    return deleted;
}

int peek() {
    if (size == 0)
        return -1;

    int minValue = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < minValue)
            minValue = arr[i];
    }

    return minValue;
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(op, "delete") == 0) {
            printf("%d\n", deleteElement());
        }
        else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}
