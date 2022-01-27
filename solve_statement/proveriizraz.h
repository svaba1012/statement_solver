#ifndef PROVERI_IZRAZ
#define PROVERI_IZRAZ

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"


void neispravanIzraz(void);
void proveraIspravnosti(char *c);
bool isOperator(char a);
void upisiBezRazmaka(char* a);
bool isPiOrE(char a);
#endif // PROVERI_IZRAZ
