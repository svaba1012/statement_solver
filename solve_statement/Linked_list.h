#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdlib.h>
#include <stdio.h>

#define EXITVALUE -1

typedef double item;
typedef struct node *linkedList;

linkedList makeList(int a[], int n);
linkedList readInList(void);
linkedList addOnFront(linkedList a, item b);
void printList(linkedList a);
struct node* searchList(linkedList a, item b);
void deleteFromList(linkedList qur, item b);
void addInOrder(linkedList qur, item a);

#endif // LINKED_LIST_H
