#include <stdio.h>

int a[10][10], i, j, m, n, count = 0;
int c[100][100];

void main() {
    int row, col;
    printf("Enter row: ");
    scanf("%d", &row);
    printf("Enter Column: ");
    scanf("%d", &col);
    printf("Enter Element of Matrix1:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &a[i][j]);
      }
    }
    int k = 1;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (a[i][j] != 0) {
                c[k][0] = i;
                c[k][1] = j;
                c[k][2] = a[i][j];
                count++;
                k++;
        }
      }
    }
    c[0][0] = row;
    c[0][1] = col;
    c[0][2] = count;
    printf("The triple matrix:\n");
    for (i = 0; i <= c[0][2]; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}
