#include <stdio.h>

struct sparse {
    int row;
    int col;
    int val;
};

int main() {
    int m, n, val;
    printf("enter total rows col and val\n");
    scanf("%d%d%d", &m, &n, &val);

    struct sparse matrix[val + 1];
    struct sparse t[val + 1];

    matrix[0].row = m;
    matrix[0].col = n;
    matrix[0].val = val;

    t[0].row = n;
    t[0].col = m;

    printf("enter data (row col value):\n");
    for (int i = 1; i <= val; i++) {
        scanf("%d%d%d", &matrix[i].row, &matrix[i].col, &matrix[i].val);
    }

    int k = 1;
    for (int c = 0; c < matrix[0].col; c++) {
        for (int i = 1; i <= matrix[0].val; i++) {
            if (matrix[i].col == c) {
                t[k].row = matrix[i].col;
                t[k].col = matrix[i].row;
                t[k].val = matrix[i].val;
                k++;
            }
        }
    }
    t[0].val = k - 1;   
    printf("\nOriginal matrix \n");
    for (int i = 0; i <= matrix[0].val; i++) {
        printf("%d\t%d\t%d\n", matrix[i].row, matrix[i].col, matrix[i].val);
    }

    printf("\nTranspose matrix\n");
    for (int i = 0; i <= t[0].val; i++) {
        printf("%d\t%d\t%d\n", t[i].row, t[i].col, t[i].val);
    }

    return 0;
}
