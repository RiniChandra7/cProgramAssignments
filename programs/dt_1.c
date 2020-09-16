#include <stdio.h>
#include <stdlib.h>

void push_back(int *dynAr, int *capacity, int *size, int n)
{
    *size = *size + 1;

    if (*size > *capacity) {
        *capacity *= 2;
        realloc(dynAr, (*capacity) * sizeof(int));
    }

    *(dynAr + (*size - 1)) = n;
}

void pop_back(int *dynAr, int *capacity, int *size, int n)
{
    *size = *size - 1;

    if (*size <= (*capacity / 4)) {
        *capacity /= 2;
        realloc(dynAr, (*capacity) * sizeof(int));
    }
}

void delete_index(int *dynAr, int *capacity, int *size, int ind)
{
    int i;
    int j;
    if (ind >= 0 && ind < *size) {
        for (i = 0; i < *size; i++) {
            if (i == ind) {
               for (j = i; j < *size - 1; j++) {
                   *(dynAr + j) = *(dynAr + j + 1);
               } 
                *size = *size - 1;
                if (*size < (*capacity / 2)) {
                    *capacity = *capacity / 2;
                }
               break;
            }
        }
    }
}

void delete_first(int *dynAr, int *capacity, int *size, int first)
{
    int i;
    int j;
    {
        for (i = 0; i < *size; i++) {
            if (*(dynAr + i) == first) {
               for (j = i; j < *size - 1; j++) {
                   *(dynAr + j) = *(dynAr + j + 1);
               } 
                *size = *size - 1;
                if (*size < (*capacity / 2)) {
                    *capacity = *capacity / 2;
                }
               break;
            }
        }
    }  
}

void delete_all(int *dynAr, int *capacity, int *size, int first)
{
    int i;
    int j;
    int k;
    {
        for (i = 0; i < *size; i++) {
            if (*(dynAr + i) == first) {
               for (j = i; j < *size - 1; j++) {
                   if (*(dynAr + j) != *(dynAr + j + 1)) {
                        *(dynAr + j) = *(dynAr + j + 1);
                   } else {
                        /*for (k = j + 2; k < *size - 1; k++) {
                            if (*(dynAr + j) != *(dynAr + k)) {
                                *(dynAr + j) = *(dynAr + k);
                                j = k;
                                break;
                            }
                        }*/
                   }
               } 
                *size = *size - 1;
                if (*size < (*capacity / 2)) {
                    *capacity = *capacity / 2;
                }
            }
        }
    }  
}

int main()
{
    int *dynArray = malloc(sizeof(int));
    int n;
    int i;
    int capacity;
    int size;
    capacity = 1;
    size = 0;
    int j;
    int pop;
    int ind;
    int first;

    scanf("%d", &n);
    int elements[n];

    for(i = 0; i < n; i++) {
        scanf("%d", &elements[i]);
    }

    //scanf("%d", &pop);

    for(i = 0; i < n; i++) {
        push_back(dynArray, &capacity, &size, elements[i]);
        /*printf("capacity = %d, size = %d, elements = ", capacity, size);
        for(j = 0; j < size; j++) {
            printf("%d ", *(dynArray + j));
        }
        printf("\n");*/
    }

    /*for(i = 0; i < pop; i++) {
        pop_back(dynArray, &capacity, &size, elements[i]);
        printf("capacity = %d, size = %d, elements = ", capacity, size);
        for(j = 0; j < size; j++) {
            printf("%d ", *(dynArray + j));
        }
        printf("\n");
    }*/

    scanf("%d", &ind);
    scanf("%d", &first);
    delete_index(dynArray, &capacity, &size, ind);
    printf("capacity = %d, size = %d, elements = ", capacity, size);
    for(j = 0; j < size; j++) {
        printf("%d ", *(dynArray + j));
    }
    printf("\n");

    delete_first(dynArray, &capacity, &size, first);
    printf("capacity = %d, size = %d, elements = ", capacity, size);
    for(j = 0; j < size; j++) {
        printf("%d ", *(dynArray + j));
    }
    printf("\n");

    delete_all(dynArray, &capacity, &size, 4);
    delete_all(dynArray, &capacity, &size, 4);
    printf("capacity = %d, size = %d, elements = ", capacity, size);
    for(j = 0; j < size; j++) {
        printf("%d ", *(dynArray + j));
    }
    printf("\n");

    return 0;
}