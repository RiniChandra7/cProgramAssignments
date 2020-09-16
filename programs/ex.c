#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}node;

void check(node *head, int unique) 
{
	node *temp = NULL;
	node *temp2 = NULL;
	node *before = NULL;
	node *after = NULL;
	node *p = NULL;
	node *q = NULL;
	node *r = NULL;
	int k;
	int j;
	int value1;
	int value2;
	
	r = head;
	temp = head;
	if (temp == NULL) {
		printf("No element");
		
		return;
	}
	temp2 = temp;
	while (temp) {
		if (temp->data == unique && temp2 == temp) {
			before = NULL;
			after = temp->next;
			break;
		} else if (temp->data == unique){
			before = temp2;
			after = temp->next;
			break;
		} 
		temp2 = temp;
		temp = temp->next;			
	}
	while ((r) && (r != temp)) {
		q = r->next;
		r->next = p;
		p = r;
		r = q;
	}
	before = p;
	k = 0;
	while (before) {
		k++;		
		if ((before->data % 2) == 1) {
			value1 = before->data;	
			break;
		}
		before = before->next;
	}
	j = 0;
	while (after) {
		j++;
		if ((after->data % 2) == 1) {
			value2 = after->data;
			break;
		}	
		after = after->next;
	}
	if ((k < j) || ((j == 0) && k != 0)) {
		printf("\n%d", value1);
	} else if ((j < k) || ((k == 0 && j != 0))) {
		printf("\n%d", value2);
	} else if (k == 0 && j == 0){
		printf("\nOnly one element");
	}
}

int main() 
{
	int nos;
	int unique;
	int data;
	int i;
	node *temp = NULL;
	node *temp2 = NULL;
	node *head = NULL;
	scanf("%d%d", &nos, &unique);
	for (i = 0; i < nos; i++) {
		temp = (node *) malloc(sizeof(node));
		if (temp == NULL) {
			printf("Memory Overflow");
			exit(1);
		}
		scanf("%d", &data);
		temp->data = data;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			temp2 =temp;
		} else {	
			temp2->next = temp;
			temp2 = temp;
		}
	}
	check(head, unique);	
}