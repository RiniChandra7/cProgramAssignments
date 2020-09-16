#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node * push(struct node *head, int n)
{
	struct node *newnode = (struct node *) malloc(sizeof(struct node));
	newnode->data = n;
	//newnode->power = p;
	newnode->next = NULL;
	if (head == NULL)
	{
		head = newnode;
		//printf("%d, %d", head->coeff, head->power);
	} else {
		struct node *temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
		//printf("%d, %d", temp->next->coeff, temp->next->power);
	}
	return head;
}

void printList(struct node *head)
{
	struct node *temp = head;

	if (temp == NULL) {
		printf("No elements to display.\n");
	} else {
		while (temp != NULL)
		{
			printf("%d->", temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

struct node * sortedInsert(struct node *head, int elem)
{
	struct node *t = head;
	struct node *newnode = (struct node *) malloc(sizeof(struct node));
	newnode->data = elem;
	newnode->next = NULL;

	if (head == NULL || head->data >= elem) {
		newnode->next = head;
		//printf("%d\n", newnode->data);
		head = newnode;	
	} else {
		while (t->next != NULL && t->next->data < elem) {
				t = t->next;	
		}
		//printf("%d\n", newnode->data);	
		newnode->next = t->next;
		t->next = newnode;
	}

	return head;
}

struct node * insertionSort(struct node *head)
{
	struct node *t = head;
	struct node *sorted = NULL;

	if (t == NULL) {
		sorted = NULL;
	} else {
		while (t != NULL) {
			//printf("source:%d\n", t->data);
			sorted = sortedInsert(sorted, t->data);
			t = t->next;
		}
	}

	return sorted;
}

int main()
{
	struct node *head = NULL;
	//struct node *eqn2 = NULL;
	struct node *sorted = NULL;
	int ch;
	int num;
	//int num, power;
	ch = 0;

	printf("Enter elements: \n");
	while (ch == 0)
	{
		printf("Enter element:\n");
		scanf("%d", &num);

		//printf("\nEnter power:\n");
		//scanf("%d", &power);

		head = push(head, num);

		printf("More elements? 0 - Yes, 1 - No: ");
		scanf("%d", &ch);
	}	
	
	printList(head);
	sorted = insertionSort(head);
	printList(sorted);

	return 0;
}
