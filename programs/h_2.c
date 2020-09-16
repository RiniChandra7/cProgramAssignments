#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node *next;
};

struct hash {
	int key;
	struct node *value;
};

struct ohash {
	int key;
	char value;
};

struct node * push(struct node *h, char n)
{
	struct node *newnode;
	newnode = (struct node *) malloc(sizeof(struct node));
	newnode->data = n;
	newnode->next = NULL;

	if (h == NULL) {
		h = newnode;
	} else {
		newnode->next = h;
		h = newnode;
	}

	return h;
}

void printlist(struct node *h)
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
}

void hashchain(char s[])
{
	struct hash *ht[26];
	//printf("Declared hashtable\n");
	int i;
	for (i = 0; i < 26; i++) {
		ht[i] = malloc(sizeof(struct node));
		if (ht[i] == NULL) {
			break;
		}
		ht[i]->key = i;
		ht[i]->value = NULL;
	}
	//printf("Initialized Hashtable\n");

	int j;
	j = 0;
	for (i = 0; i < strlen(s); i++) {
		j = (s[i] - 'a') % 26;
		ht[j]->value = push(ht[j]->value, s[i]);
	}
	//printf("Filled hashtable\n");

	for (i = 0; i < 26; i++) {
		if (ht[i]->value != NULL) {
			printf("%c ", ht[i]->value->data);
		}
	}
	printf("\n");
}

void doubleHash(char s[])
{
	struct ohash *ht[26];
	int i;
	for (i = 0; i < 26; i++) {
		ht[i] = malloc(sizeof(struct node));
		if (ht[i] == NULL) {
			break;
		}
		ht[i]->key = i;
		ht[i]->value = '%';
	}

	int j;
	for (i = 0; i < strlen(s); i++) {
		j = (s[i] - 'a') % 26;
		j = (j + (23 - j % 23) * j) % 26;
		if (j == 26) {
			j = 0;
		}
		printf("%d %c\n", j, s[i]);
		ht[j]->value = s[i];
	}

	for (i = 0; i < 26; i++) {
		if (ht[i]->value != '%') {
			printf("%c ", ht[i]->value);
		}
	}
	printf("\n");
}

void directAddress(char s[])
{
	struct ohash *ht[26];
	int i;
	for (i = 0; i < 26; i++) {
		ht[i] = malloc(sizeof(struct node));
		if (ht[i] == NULL) {
			break;
		}
		ht[i]->key = i;
		ht[i]->value = '%';
	}

	int j;
	for (i = 0; i < strlen(s); i++) {
		j = (s[i] - 'a') % 26;
		ht[j]->value = s[i];
	}

	for (i = 0; i < 26; i++) {
		if (ht[i]->value != '%') {
			printf("%c ", ht[i]->value);
		}
	}
	printf("\n");
}

void linearProbing(char s[])
{
	struct ohash *ht[26];
	int i;
	for (i = 0; i < 26; i++) {
		ht[i] = malloc(sizeof(struct node));
		if (ht[i] == NULL) {
			break;
		}
		ht[i]->key = i;
		ht[i]->value = '%';
	}

	int j;
	int k;
	k = 0;
	for (i = 0; i < strlen(s); i++) {
		j = (s[i] - 'a') % 26;
		if (s[i] != ht[j]->value) {
			while (ht[j]->value != '%') {
				j = j + k;
				k++;
			}
			ht[j]->value = s[i];
		}
	}

	for (i = 0; i < 26; i++) {
		if (ht[i]->value != '%') {
			printf("%c ", ht[i]->value);
		}
	}
	printf("\n");
}

void quadraticProbing(char s[])
{
	struct ohash *ht[26];
	int i;
	for (i = 0; i < 26; i++) {
		ht[i] = malloc(sizeof(struct node));
		if (ht[i] == NULL) {
			break;
		}
		ht[i]->key = i;
		ht[i]->value = '%';
	}

	int j;
	int k;
	k = 0;
	for (i = 0; i < strlen(s); i++) {
		j = (s[i] - 'a') % 26;
		if (s[i] != ht[j]->value) {
			while (ht[j]->value != '%') {
				j = j + k * k;
				k++;
			}
			ht[j]->value = s[i];
		}
	}

	for (i = 0; i < 26; i++) {
		if (ht[i]->value != '%') {
			printf("%c ", ht[i]->value);
		}
	}
	printf("\n");
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

	for (i = 0; i < n; i++) {
		//hashchain(strs[i]);
		//doubleHash(strs[i]);
		//directAddress(strs[i]);
		//linearProbing(strs[i]);
		quadraticProbing(strs[i]);
	}

	return 0;
}
