// Problem: Write a program to check whether a given matrix is symmetric.
// A matrix is said to be symmetric if it is a square matrix and is equal to its transpose.
//
// Input:
// - First line: two integers m and n representing the number of rows and columns
// - Next m lines: n integers each representing the elements of the matrix
//
// Output:
// - Print "Symmetric Matrix" if the given matrix is symmetric
// - Otherwise, print "Not a Symmetric Matrix"
//
// Example:
// Input:
// 3 3
// 1 2 3
// 2 4 5
// 3 5 6
//
// Output:
// Symmetric Matrix

#include <stdio.h>

int main() {
    int m, n, i, j, flag = 1;

    scanf("%d %d", &m, &n);

    int a[m][n];

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    if(m != n) {
        flag = 0;
    } else {
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                if(a[i][j] != a[j][i]) {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
                break;
        }
    }

    if(flag == 1)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
