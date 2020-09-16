#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node * insert(struct node *head, int n) 
{
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        head->next = head;
    } else {
        struct node *t;
        t = head;

        do {
            t = t->next;
        } while (t->next != head);

        t->next = newnode;
        newnode->next = head;
    }

    return head;
}

void printList(struct node *head)
{
    struct node *t;
    t = head;

    if (head != NULL) {
        do {
            printf("%d->", t->data);
            t = t->next;
        } while (t != head);
    }

    printf("NULL\n");
}

void printMul(struct node *head, int k, int n)
{
    struct node *t;
    t = head;
    int c;
    c = 0;
    int flag = 0;

    do {
        if (n % 2 == 0 && c == n && c % k == 0) {
            t = t->next;
        }
        if (c % k == 0) {
            printf("%d->", t->data);
        }
        c++;
        t = t->next;
    } while (c != k * n);

    printf("NULL\n");
}

struct node * maxFolMax(struct node *h1, struct node *h2)
{
    struct node *t1;
    struct node *t2;
    t1 = h1;
    t2 = h2;

    if (h1 == NULL && h2 != NULL) {
        return h2;
    } else if (h1 != NULL && h2 == NULL) {
        return h1;
    } else if (h1 == NULL && h2 == NULL) {
        return NULL;
    } 
    else {
        struct node *max1;
        struct node *temp1;
        struct node *result = NULL;
        max1 = (struct node *) malloc(sizeof(struct node));
        max1->data = 0;
        max1->next = NULL;
        do {
            if (t1->data > max1->data) {
                max1 = t1;
            }
            t1 = t1->next;
        } while (t1 != h1);
        struct node *part;
        part = NULL;
        temp1 = max1->next;
        do {
            part = insert(part, temp1->data);
            temp1 = temp1->next;
        } while (temp1 != h1);
        //printList(part);

        temp1 = h1;
        do {
            result = insert(result, temp1->data);
            temp1 = temp1->next;
        } while (temp1 != max1->next);

        struct node *max2;
        max2 = t2;
        struct node *prev = t2;
        t2 = t2->next;
        do {
            if (t2->data > max2->data) {
                max2 = t2;
            }
            prev = prev->next;
            t2 = t2->next;
        } while (t2->next != h2);
        struct node *temp2;
        temp2 = h2;
        struct node *part2 = NULL;
        while (temp2->next->next != prev) {
            part2 = insert(part2, temp2->data);
            temp2 = temp2->next;
        }
        printList(part2);

        temp2 = max2;
        do {
            result = insert(result, temp2->data);
            temp2 = temp2->next;
        } while (temp2 != max2);

        temp1 = max1->next;
        do {
            result = insert(result, temp1->data);
            temp1 = temp1->next;
        } while (temp1 != h1);

        printList(result);

        /*temp1 = part;
        do {
            part2->next = insert(part2->next, temp1->data);
            temp1 = temp1->next;
        } while (temp1 != part);
        //part2->next = part;
        printList(part2->next);

        temp1 = part2;
        do {
            max2->next = insert(max2->next, temp1->data);
            temp1 = temp1->next;
        } while (temp2 != part2);
        //max2->next = part2;
        printList(max2->next);

        temp1 = max2;
        do {
            max1->next = insert(max1->next, temp1->data);
            temp1 = temp1->next;
        } while (temp1 != max2);
        //max1->next = max2;
        printList(max1);
        */
        return max1;
    }
}

int main()
{
    struct node *head1, *head2;
    head1 = NULL;
    head2 = NULL;
    struct node *res = NULL;
    int n;
    int ele;
    int i;
    int k;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ele);
        head1 = insert(head1, ele);
    }

    printList(head1);

    for (i = 0; i < n; i++) {
        scanf("%d", &ele);
        head2 = insert(head2, ele);
    }

    printList(head2);

    //scanf("%d", &k);
    //printMul(head, k, n);

    res = maxFolMax(head1, head2);
    //printList(res);

    return 0;
}