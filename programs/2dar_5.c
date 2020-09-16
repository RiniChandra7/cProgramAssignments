#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    char names[n][20];
    int i;
    for (i = 0; i < n; i++) {
        scanf("%s", &names[i]);
    }

    char temp[20];
    int j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    printf("Sorted:\n");
    for (i = 0; i < n; i++) {
        printf("%s\t", names[i]);
    }
    printf("\n");

    for (i = 0; i < n - 1; i++) {
        if (strcmp(names[i], names[i + 1]) == 0) {
            for (j = i + 1; j < n - 1; j++) {
                //names[j] = names[j + 1];
                strcpy(names[j], names[j + 1]);
            }
            //names[n - 1] = "999";
            strcpy(names[n - 1], "999");
        }
    }

    printf("Unique:\n");
    for (i = 0; i < n; i++) {
        if (strcmp(names[i], "999") != 0) {
            printf("%s\t", names[i]);
        }
    }
    printf("\n");
}