#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contains(int *ar, int x, int n)
{
    int i;
    //i = 0;
    for (i = 0; i < n; i++) {
        if (x == *(ar + i)) {
            return 1;
        }
    } 

    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);

    int mat[n][n];
    int i;
    int j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("Along rows:\n");
    for (i = 0; i < n; i++) {
        int uniqRC[n];
        int k;
        k = 0;
        memset(uniqRC, 999, sizeof(uniqRC));

        for (j = 0; j < n; j++) {
            if (contains(uniqRC, mat[i][j], n) == 0) {
                uniqRC[k] = mat[i][j];
                k++;
            }
        }

        //k = 0;
        int x;
        for (x = 0; x < k; x++) {
                printf("%d ", uniqRC[x]);
        }
        printf("\n");
    }

    printf("Along columns:\n");
    for (i = 0; i < n; i++) {
        int uniqRC[n];
        int k;
        k = 0;
        memset(uniqRC, 999, sizeof(uniqRC));

        for (j = 0; j < n; j++) {
            if (contains(uniqRC, mat[j][i], n) == 0) {
                uniqRC[k] = mat[j][i];
                k++;
            }
        }
        int x;
        for (x = 0; x < k; x++) {
            printf("%d ", uniqRC[x]);
        }
        printf("\n");
    }

}