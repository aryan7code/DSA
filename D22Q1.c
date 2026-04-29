// Problem: Count Nodes in Linked List
//
// Input:
// - First line: integer n
// - Second line: n space-separated integers
//
// Output:
// - Print the total number of nodes in the linked list
//
// Example:
// Input:
// 5
// 10 20 30 40 50
//
// Output:
// 5

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, i, value, count = 0;

    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newnode = NULL;

    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    temp = head;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("%d", count);

    return 0;
}
