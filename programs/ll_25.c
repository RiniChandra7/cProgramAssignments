#include <stdio.h>
#include <stdlib.h>

struct node {
	int coeff;
	int power;
	struct node *next;
};

struct node * push(struct node *head, int n, int p)
{
	struct node *newnode = (struct node *) malloc(sizeof(struct node));
	newnode->coeff = n;
	newnode->power = p;
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
			printf("%d, %d ->", temp->coeff, temp->power);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

int searchPow(int pow, struct node *head)
{
	struct node *t = head;

	while (t != NULL)
	{
		if (pow == t->power) {
			return 1;
		}
		else {
			t = t->next;
		}
	}
	return 0;
}

struct node * addEqns(struct node *head1, struct node *head2)
{
	struct node *t1 = head1;
	struct node *t2 = head2;
	int flag = 0;
	struct node *sum = (struct node *) malloc(sizeof(struct node));

	while (t1 != NULL && t2 != NULL) {
			if (t1->power > t2->power) {
				sum = push(sum, t1->coeff, t1->power);
				//printf("%d, %d\n", t1->coeff, t2->coeff);
				//flag = 1;
				t1 = t1->next;
			} else if (t1->power < t2->power) {
				sum = push(sum, t2->coeff, t2->power);
				t2 = t2->next;
			} else {
				sum = push(sum, t1->coeff + t2->coeff, t1->power);
				//printf("%d, %d\n", t1->coeff, t2->coeff);
				t1 = t1->next;
				t2 = t2->next;
			}


			/*if (searchPow(t1->power, head2) == 0) {
				sum = push(sum, t1->coeff, t1->power);
			}

			if (searchPow(t2->power, head1) == 0) {
				sum = push(sum, t2->coeff, t2->power);
			}
			t2 = t2->next;
		}*/
		//t1 = t1->next;
	}

	while (t1 != NULL) {
		sum = push(sum, t1->coeff, t1->power);
		t1 = t1->next;
	}

	while (t2 != NULL) {
		sum = push(sum, t2->coeff, t2->power);
		t2 = t2->next;
	}

	return sum;
}

int main()
{
	struct node *eqn1 = NULL;
	struct node *eqn2 = NULL;
	struct node *sum = NULL;
	int ch;
	int num, power;
	ch = 0;

	printf("Enter Equation 1: \n");
	while (ch == 0)
	{
		printf("Enter coefficient:\n");
		scanf("%d", &num);

		printf("\nEnter power:\n");
		scanf("%d", &power);

		eqn1 = push(eqn1, num, power);

		printf("More elements? 0 - Yes, 1 - No: ");
		scanf("%d", &ch);
	}

	ch = 0;
	printf("Enter Equation 2: \n");
	while (ch == 0)
	{
		printf("Enter coefficient:\n");
		scanf("%d", &num);

		printf("\nEnter power:\n");
		scanf("%d", &power);

		eqn2 = push(eqn2, num, power);

		printf("More elements? 0 - Yes, 1 - No: ");
		scanf("%d", &ch);
	}

	printList(eqn1);
	printList(eqn2);
	sum = addEqns(eqn1, eqn2);
	printList(sum);

	return 0;
}
