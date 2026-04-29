// Problem: Merge Two Sorted Linked Lists
// Implement using linked list with dynamic memory allocation.
//
// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)
//
// Output:
// - Print the merged linked list elements, space-separated
//
// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 35 45
//
// Output:
// 10 15 20 25 30 35 40 45 50
//
// Explanation:
// Compare nodes of both lists, append smaller to result,
// continue until all nodes are merged.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node *newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

int main() {
    int n, m, i, value;

    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;
    struct Node *result = NULL, *tail = NULL;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node *newnode = createNode(value);

        if(head1 == NULL) {
            head1 = tail1 = newnode;
        } else {
            tail1->next = newnode;
            tail1 = newnode;
        }
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        scanf("%d", &value);
        struct Node *newnode = createNode(value);

        if(head2 == NULL) {
            head2 = tail2 = newnode;
        } else {
            tail2->next = newnode;
            tail2 = newnode;
        }
    }

    while(head1 != NULL && head2 != NULL) {
        struct Node *temp;

        if(head1->data < head2->data) {
            temp = head1;
            head1 = head1->next;
        } else {
            temp = head2;
            head2 = head2->next;
        }

        temp->next = NULL;

        if(result == NULL) {
            result = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    if(head1 != NULL)
        tail->next = head1;

    if(head2 != NULL)
        tail->next = head2;

    while(result != NULL) {
        printf("%d ", result->data);
        result = result->next;
    }

    return 0;
}
