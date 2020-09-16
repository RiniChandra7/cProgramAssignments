#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node * push(struct node *h, int n)
{
	struct node *t;
	t = h;
	struct node *newnode = (struct node *) malloc(sizeof(struct node));
	newnode->data = n;
	newnode->next = NULL;

	if (h != NULL) {
		while (t->next != NULL) {
			t = t->next;
		}
		t->next = newnode;
	} else {
		h = newnode;
	}

	return h;
}

void printList(struct node *h)
{
	struct node *t;
	t = h;

	if (h == NULL) {
		printf("Empty List!\n");
	} else {
		while (t != NULL) {
			printf("%d->", t->data);
			t = t->next;
		}
		printf("NULL\n");
	}
}

int oddFinder(struct node *h, int x)
{
	struct node *t;
	t = h;
	struct node *target;
	int odd1;
	int odd2;
	int pos1;
	int pos2;
	int targetPos;
	odd1 = -1;
	odd2 = -1;
	pos1 = 0;
	pos2 = 0;
	targetPos = 0;

	if (h == NULL) {
		return -999;
	} else {
		while (t != NULL && t->data != x) {
			targetPos++;
			t = t->next;
		}
		target = t;

		if (target == NULL || target->data != x) {
			return -999;
		}

		//printf("Targetpos: %d\n", targetPos);

		if (h == target && h->next == NULL) {
			return h->data;
		}

		t = h;
		while (t->next != NULL && t->next != target) {
			if (t->data % 2 == 1) {
				odd1 = t->data;
			}
			pos1++;
			t = t->next;
		}
		//printf("POs1:%d\n", pos1);

		t = target->next;
		pos2 = targetPos;
		while (t != NULL) {
			if (t->data % 2 == 1) {
				odd2 = t->data;
				break;
			}
			pos2++;
			t = t->next;
		}
		//printf("Pos2:%d\n", pos2);
		
		if (target->next == NULL) {
			return odd1;
		}

		if (targetPos - pos1 <= pos2 - targetPos) {
			return odd1;
		} else {
			return odd2;
		}
	}
}

int main()
{
	struct node *head = NULL;
	int n;
	int x;
	int ele;

	printf("Enter desired size of linked list:\n");
	scanf("%d", &n);

	for (x = 0; x < n; x++) {
		printf("Enter an element:\n");
		scanf("%d", &ele);
		head = push(head, ele);
	}

	printf("Enter the value of x:\n");
	scanf("%d", &x);

	printf("The input list is:\n");
	printList(head);

	printf("The closest odd number is:\n");
	if (oddFinder(head, x) != -999) {
		printf("%d\n", oddFinder(head, x));
	} else {
		printf("Number not found!\n");
	}

	return 0;
}