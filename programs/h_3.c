#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash {
    int key;
    struct node *value;
};

struct node {
    struct node *next;
    char data[];
};

struct node * push(struct node *h, char n[])
{
	struct node *newnode;
	newnode = (struct node *) malloc(sizeof(struct node));
    strcpy(newnode->data, n);
	newnode->next = NULL;

	if (h == NULL) {
		h = newnode;
	} else {
		newnode->next = h;
		h = newnode;
	}

	return h;
}

/*void printlist(struct node *h)
{
	if (h != NULL) {
		struct node *t;
		t = h;

		while (t != NULL) {
			printf("%d->", t->data);
			t = t->next;
		}
		printf("NULL\n");
	}
}*/

int charSum(char str[])
{
    int s;
    s = 0;

    int i;
    for (i = 0; i < strlen(str); i++) {
        s += str[i];
    }

    return s;
}

int getKey(char str[])
{
    return charSum(str) % 23;
}

int hasher(char str[][30], int n)
{
    struct hash *ht[23];
    int i;
    for (i = 0; i < 23; i++) {
		ht[i] = malloc(sizeof(struct node));
		if (ht[i] == NULL) {
			break;
		}
		ht[i]->key = i;
		ht[i]->value = NULL;
    }

    int k;
    int count;
    count = 0;
    for (i = 0; i < n; i++) {
        k = getKey(str[i]);
        if (ht[k]->value == NULL) {
            count++;
        } 
        /*else {
            if (strcmp(ht[k]->value->data, str[i]) != 0) {
                k = i * k;
                if (k >= 23) {
                    k = k - 23;
                }
            }
        }*/

        ht[k]->value = push(ht[k]->value, str[i]);
    }

    return count;
}

int main()
{
	int n;
	scanf("%d", &n);

	char strs[n][30];
	int i;
	for (i = 0; i < n; i++) {
		scanf("%s", strs[i]);
	}

    printf("%d\n", hasher(strs, n));

    return 0;
}