#include "stack.h"

struct node{
	item i;
	struct node *next;
};

Stack createStack(void){
    item* b = malloc(0);
    Stack a = makeList(b, 0);
    return a;
}

bool isEmpty(Stack a){
    if(a == NULL)
        return true;
    return false;
}

Stack pushOnStack(Stack a, item b){
    a = addOnFront(a, b);
    return a;
}

Stack popFromStack(Stack a, item* b){
    Stack c;
    if(isEmpty(a)){
        stackOverflow("\nNeispravan izraz");
    }
    *b = a -> i;
    c = a -> next;
    free(a);
    return c;
}

void stackOverflow(const char* str){
    printf(str);
    exit(0);
}
