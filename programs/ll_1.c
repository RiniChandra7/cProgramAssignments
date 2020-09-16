#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void printList(struct node *head);

struct node * insertBeg(struct node *head, int n)
{
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }

    return head;
}

struct node * insertLast(struct node *head, int n)
{
    struct node *t = head;
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = newnode;
    }

    return head;
}

struct node * insertCustom(struct node *head, int n, int pos)
{
    struct node *t;
    struct node *temp;
    t = head;
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    int c;
    c = 0;
    newnode->data = n;

    if (head == NULL) {
        printf("Insertion in empty list.\n");
        head = newnode;
    } else {
        if (pos > 0) {
            if (pos == 1) {
                newnode->next = head;
                head = newnode;
            } else {
                while (t->next != NULL) {
                    c++;

                    if (c == pos) {
                        //printf("%d", t->data);
                        temp = t->next;
                        t->next = newnode;
                        newnode->next = temp;

                        break;
                    }

                    t = t->next;
                }

            }
        }
    }

    return head;
}

struct node * reverseList(struct node *head, int groupSize)
{
    /*struct node *t = head;
    struct node *reverse = NULL;

    if (head != NULL) {
        while (t != NULL) {
            reverse = insertBeg(reverse, t->data);
            t = t->next;
        }
    }*/
    //printList(reverse);
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    struct node *rev = NULL;
    int count = 0;

    while (current != NULL && count != groupSize) {
            next = current->next;

            current->next = prev;

            prev = current;
            current = next;

            count++;
    }

    if (next != NULL)
        head->next = reverseList(next, groupSize);
    //head = prev;

    return prev;
}

void printList(struct node *head)
{
    struct node *t;
    t = head;

    if (head == NULL) {
        printf("Empty list!\n");
    } else {
        while (t != NULL) {
            printf("%d->", t->data);
            t = t->next;
        }
        printf("NULL\n");
    }
}

void checkPalindrome(struct node *h)
{
    struct node *t;
    t = h;
    struct node *rev = NULL;
    int f = 0;

    while (t != NULL) {
        rev = insertBeg(rev, t->data);
        t = t->next;
    }

    t = h;
    //printList(rev);
    while (t != NULL && rev != NULL) {
        //printf("%d, %d\n", t->data, rev->data);
        if (t->data != rev->data) {
            f = 1;
            printf("Not palindrome!\n");
            break;
        } else {
            t = t->next;
            rev = rev->next;
        }
    }

    if (f == 0) {
        printf("Palindrome!\n");
    }
}

struct node * deleteDuplicates(struct node *head) 
{
    struct node *t;
    t = head;
    struct node *h, *temp;
    int c = 0;

    while (t != NULL) {
        //head->next = findRemove(t->next, t->data);
        c = 1;
        h = t;
        printf("Freq(%d): ", t->data);
        while (h->next != NULL) {
            if (t->data == h->next->data) {
                c++;
                temp = h->next;
                h->next = h->next->next;
                free(temp);
            }
            h = h->next;
        }
        printf("%d\n", c);
        t = t->next;
    }

    printList(head);

    return head;
}

int main()
{
    struct node *h = NULL;
    struct node *reverse = NULL;
    int num;
    int pos;

    for (pos = 0; pos < 5; pos++) {
        printf("Enter element to form a linked list :\n");
        scanf("%d", &num);
        h = insertLast(h, num);
    }
    /*printf("Enter element to form a linked list :\n");
    scanf("%d", &num);
    h = insertLast(h, num);
    printf("Enter element to form a linked list :\n");
    scanf("%d", &num);
    h = insertLast(h, num);

    printList(h);

    /*printf("Enter element to be inserted in the beginning: \n");
    scanf("%d", &num);
    h = insertBeg(h, num);
    printList(h);

    printf("Enter element to be inserted: \n");
    scanf("%d", &num);
    printf("Enter position: \n");
    scanf("%d", &pos);
    h = insertCustom(h, num, pos);
    printList(h);*/

    /*printf("Reverse of the list is: \n");
    h = reverseList(h, 4);
    printList(h);*/

    //checkPalindrome(h);
    printList(deleteDuplicates(h));
    return 0;
}