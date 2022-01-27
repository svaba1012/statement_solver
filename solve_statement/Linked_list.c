#include "Linked_list.h"

struct node{
	item i;
	struct node *next;
};

linkedList makeList(int a[], int n){
	struct node *first = NULL;
	for(int i = n - 1; i >= 0; i--){
		first = addOnFront(first, a[i]);
	}
	return first;
}

linkedList readInList(void){
	struct node *first = NULL;
	item x;
	scanf("%lf", &x);
	while(x != EXITVALUE){
		first = addOnFront(first, x);
		scanf("%lf", &x);
	}
	return first;
}

linkedList addOnFront(linkedList a, item b){
	struct node *list;
	list = malloc(sizeof(*list));
	if(list == NULL){
		printf("Nema vise memorije");
		exit(0);
	}
	list -> i = b;
	list -> next = a;
	return list;
}

void printList(linkedList a){
	for(; a != NULL; a = a -> next)
		printf("%.3lf", a -> i);
}

struct node* searchList(linkedList a, item b){
	for(; (a != NULL) && (a -> i != b); a = a -> next)
		;
	return a;
}

void deleteFromList(linkedList qur, item b){
	struct node *prev = NULL;
	for(; (qur != NULL) && (qur -> i != b); prev = qur, qur = qur -> next)
		;
	if(qur == NULL){
		printf("Trazeni element za brisanje ne postoji");
		exit(0);
	}
	prev -> next = qur -> next;
	free(qur);
}

void addInOrder(linkedList qur, item a){
	struct node *prev = NULL;
	for(; (qur != NULL) && (qur -> i > a); prev = qur, qur = qur -> next)
		;
	if(qur -> i <= a){
		qur = prev -> next;
		prev -> next = malloc(sizeof(*prev));
		if(prev -> next == NULL){
			printf("Nema memorije");
			exit(0);
		}
		prev -> next -> next = qur;
	}else{
		qur -> next = malloc(sizeof(*qur));
		if(qur -> next == NULL){
			printf("Nema memorije");
			exit(0);
		}
		qur -> next -> next = NULL;
	}
}
