#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    int mat[n][n];
    int diagSum[n];
    memset(diagSum, 0, sizeof(diagSum));
    int i;
    int j;
    int k;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int max;
    max = 0;
    int ind;
    ind = -1;

    for (i = 0; i < n; i++) {
        if (i == 0) {
            diagSum[i] = mat[0][1] + mat[1][1] + mat[1][0];
        } else if (i == n - 1) {
            diagSum[i] = mat[n - 2][n - 2] + mat[n - 1][n - 2] + mat[n - 2][n - 1];
        } else {
            for (j = -1; j <= 1; j++) {
                for (k = -1; k <= 1; k++) {
                    diagSum[i] += mat[i + j][i + k];
                }
            }
            diagSum[i] -= mat[i][i];
        }

        if (max < diagSum[i]) {
            max = diagSum[i];
            ind = i;
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d: %d\n", mat[i][i], diagSum[i]);
    }
    printf("index: %d", ind + 1);

    return 0;
}