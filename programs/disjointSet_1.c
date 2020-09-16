#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct set {
    int *rank;
    int *parent;
    int n;
};

void makeSet(struct set *s, int n)
{
    s->parent[n] = n;
    //s->rank[n] = n;
}

int findSet(struct set *s, int x)
{
    if (s->parent[x] != x) {
        s->parent[x] = findSet(s, s->parent[x]);
    }

    return s->parent[x];
}

void unionSet(struct set *s, int x, int y)
{
    int xPar;
    int yPar;
    int i;

    xPar = findSet(s, x);
    //printf("x:%d, xpar:%d\n", x, xPar);
    yPar = findSet(s, y);
    //printf("y:%d, ypar:%d\n", y, yPar);

    if (xPar == yPar) {
        return;
    } else if (xPar < yPar) {
        s->parent[yPar] = xPar;
        for (i = 0; i < s->n; i++) {
            if (s->parent[i] == yPar) {
                s->parent[i] = xPar;
            }
        }
        //printf("r:%d, rpar\n", xPar);
    } else if (yPar < xPar) {
        s->parent[xPar] = yPar;
        for (i = 0; i < s->n; i++) {
            if (s->parent[i] == xPar) {
                s->parent[i] = yPar;
            }
        }
                //printf("r:%d, rpar\n", xPar);
    }
}

int main()
{
    struct set *fullset;
    fullset = (struct set *) malloc(sizeof(struct set));
    int n;
    scanf("%d", &n);
    fullset->n = n;
    int parent[n];
    memset(parent, -1, sizeof(parent));
    fullset->parent = parent;

    int i;
    for(i = 0; i < n; i++) {
        makeSet(fullset, i);
    }

    for(i = 0; i < n; i++) {
        printf("%d ", fullset->parent[i]);
    }
    printf("\n");

    unionSet(fullset, 1, 5);
    unionSet(fullset, 3, 7);
    unionSet(fullset, 1, 4);
    unionSet(fullset, 5, 7);
    unionSet(fullset, 0, 8);
    unionSet(fullset, 6, 9);
    unionSet(fullset, 3, 9);
    for(i = 0; i < n; i++) {
        printf("%d ", fullset->parent[i]);
    }
    printf("\n");
    int j;
    for(i = 0; i < n; i++) {
        printf("\nTree with parent %d:\n", i);
        for(j = 0; j < n; j++) {
            if (fullset->parent[j] == i) {
                printf("%d ", j);
            }
            //printf("\n");
        }
    }
}