#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Linked_list.h"

typedef linkedList Stack;

bool isEmpty(Stack a);
Stack pushOnStack(Stack a, item b);
Stack popFromStack(Stack a, item* b);
void stackOverflow(const char* str);
Stack createStack(void);
#endif // STACK_H
