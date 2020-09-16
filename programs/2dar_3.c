#include <stdio.h>
#include <stdlib.h>

void transpose(int *ar, int *m, int *n)
{
    int i;
    int j;
    //printf("%d", *ar);
    for (j = 0; j < *n; j++) {
        for (i = 0; i < *m; i++) {
            printf("%3d", *(ar + j * *m + i));
        }
        printf("\n");
    }
}

int main()
{
    int m;
    int n;
    scanf("%d", &m);
    scanf("%d", &n);

    int i;
    int j;
    int ar[m][n];
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &ar[i][j]);
        }
    }
    printf("%d\n", ar[0][0]);
    transpose(&ar[0][0], &m, &n);

    return 0;
}