#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct set {
    int *parent;
    int length;
};

void makeSet(struct set *s, int n)
{
    s->parent[n] = n;
}

int findSet(struct set *s, int n)
{
    if (s->parent[n] != n) {
        s->parent[n] = findSet(s, s->parent[n]);
    }

    return s->parent[n];
}

void unionSet(struct set *s, int x, int y)
{
    int xPar;
    int yPar;
    int i;

    xPar = findSet(s, x);
    yPar = findSet(s, y);
    //printf("x:%d, xpar: %d, y:%d, ypar: %d\n", x, xPar, y, yPar);

    if (xPar == yPar) {
        return;
    } else if (xPar < yPar) {
        s->parent[yPar] = xPar;
        for (i = 0; i < s->length; i++) {
            if (s->parent[i] == yPar) {
                s->parent[i] = xPar;
            }
        }
    } else if (yPar < xPar) {
        s->parent[xPar] = yPar;
        for (i = 0; i < s->length; i++) {
            if (s->parent[i] == xPar) {
                s->parent[i] = yPar;
            }
        }
    }
}

int hasChild(struct set *s, int n)
{
    int i;
    for (i = 0; i < s->length; i++) {
        if (s->parent[i] == n) {
            return 1;
        }
    }

    return 0;
}

void connectedComponents()
{
    {
        int n;
        scanf("%d", &n);
        struct set *set;
        set = (struct set *) malloc(sizeof(struct set));
        set->length = n;
        int parent[n];
        set->parent = parent;
        int j;
        for (j = 0; j < n; j++) {
            makeSet(set, j);
        }

        int Adj[n][n];
        int k;
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                scanf("%d", &Adj[j][k]);
                if (Adj[j][k] == 1) {
                    unionSet(set, j, k);
                }
            }
        }

        /*for(j = 0; j < n; j++) {
            printf("%d ", set->parent[j]);
        }
        printf("\n");*/

        int connectedComp;
        connectedComp = 0;
        int conPar[n];
        k = 0;
        for (j = 0; j < n; j++) {
            if (hasChild(set, j) == 1) {
                connectedComp += 1;
                conPar[k] = j;
                k += 1;
            }
        }

        /*int x = 0;
        for (j = 0; j < n; j++) {
            if (x == n - 1) {
                connectedComp += 1;
                conPar[k] = j;
                k += 1;
            }
            if (Adj[j][x] == 0) {
                x += 1;
            }

        }*/

        printf("%d\n", connectedComp);
        for (j = 0; j < connectedComp; j++) {
            printf("%d\t", conPar[j] + 1);
        }
        printf("\n");
    }
}

int isSamePar(struct set *s)
{
    int i;

    for (i = 0; i < s->length - 1; i++) {
        if (s->parent[i] == s->parent[i + 1]) {
            continue;
        } else {
            return 0;
        }
    }

    return 1;
}

void isGraphConnected()
{
    int n;
    scanf("%d", &n);
    struct set *set;
    set = (struct set *) malloc(sizeof(struct set));
    set->length = n;
    int parent[n];
    set->parent = parent;
    int j;
    for (j = 0; j < n; j++) {
        makeSet(set, j);
    }
    /*for(j = 0; j < n; j++) {
        printf("%d ", set->parent[j]);
    }
    printf("\n");*/
    int Adj[n][n];
    int k;
    for (j = 0; j < n; j++) {
        for (k = 0; k < n; k++) {
            scanf("%d", &Adj[j][k]);
            if (Adj[j][k] == 1) {
                unionSet(set, j, k);
            }
        }
    }

    /*for(j = 0; j < n; j++) {
        printf("%d ", set->parent[j]);
    }
    printf("\n");*/

    if (isSamePar(set) == 1) {
        printf("Connected\n");
    } else {
        printf("Disconnected\n");
    }
}

int present(int *vis, int x, int y, int n)
{
    int f1;
    f1 = 0;
    int i;

    for (i = 0; i < n; i++) {
        if (*(vis + i) == x) {
            f1 = 1;
            break;
        }
        if (*(vis + i) == -1) {
            break;
        }
    }

    int f2 = 0;
    for (i = 0; i < n; i++) {
        if (*(vis + i) == y) {
            f2 = 1;
            break;
        }
        if (*(vis + i) == -1) {
            break;
        }
    }

    if (f1 == 1 && f2 == 1) {
        return 1;
    } else {
        return 0;
    }
}

void detectCycle()
{
    int n;
    scanf("%d", &n);
    struct set *set;
    set = (struct set *) malloc(sizeof(struct set));
    set->length = n;
    int parent[n];
    set->parent = parent;
    int j;
    for (j = 0; j < n; j++) {
        makeSet(set, j);
    }
    /*for(j = 0; j < n; j++) {
        printf("%d ", set->parent[j]);
    }
    printf("\n");*/
    int Adj[n][n];
    int k;
    for (j = 0; j < n; j++) {
        for (k = 0; k < n; k++) {
            scanf("%d", &Adj[j][k]);
            /*if (Adj[j][k] == 1) {
                unionSet(set, j, k);
            }*/
        }
    }

    int vis[n];
    memset(vis, -1, sizeof(vis));
    int h;
    h = 0;
    int x;
    for (j = 0; j < n; j++) {
        for (k = j; k < n; k++) {
            if (Adj[j][k] == 1) {
                if (present(vis, j, k, n) == 1) {
                    printf("Yes\n");
                    return;
                }
                /*for (x = 0; x < h; x++) {
                    printf("%d\t", vis[x]);
                }*/
                //printf("\n");
                unionSet(set, j, k);
                vis[h] = j;
                vis[h + 1] = k;
                h = h + 2;
            }
        }
    }
    printf("No\n");
}

int main()
{
    //connectedComponents();
    //isGraphConnected();
    detectCycle();
    
    return 0;
}