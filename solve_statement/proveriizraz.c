#include "proveriizraz.h"
bool isOperator(char a){
    if((a == '+') || (a == '-') || (a == '*') || (a == '/') || (a == '^'))
        return true;
    return false;
}

bool isPiOrE(char a){
    if((a == 'p') || (a == 'e'))
        return true;
    return false;
}

void neispravanIzraz(void){
    puts("\nNeispravan izraz");
    exit(0);
}

void upisiBezRazmaka(char *a){
    char b, prev;
    Stack z = createStack();
    while((b = getchar()) == ' ')
        ;
    *a = b;
    if(*a == '(')
        z = pushOnStack(z, 1);
    if(*a == ')'){
        item *d = malloc(1);
        z = popFromStack(z, d);
    }
    if(!isdigit(*a) && (*a != '(') && (!isalpha(*a)))
        neispravanIzraz();
    for(b = getchar(), a++; b != '\n'; prev = b, b = getchar()){
        if((b != ' ') || (*(a - 1) == '.')){
            *a = b;
            if((prev == ' ') && ((*a == '.') || isdigit(*a)) && isdigit(*(a - 1)))
                neispravanIzraz();
            if((prev == ' ') && (isalpha(*a) && !isPiOrE(*a)) && (isalpha(*(a - 1)) && !isPiOrE(*(a - 1))))
                neispravanIzraz();
            if(*a == '(')
                z = pushOnStack(z, 1);
            if(*a == ')'){
                item *d = malloc(1);
                z = popFromStack(z, d);
            }
            proveraIspravnosti(a++);
        }
    }
    if(!isdigit(*(a - 1)) && (*(a - 1) != ')') && (!isPiOrE(*(a - 1))))
        neispravanIzraz();
    if(!isEmpty(z))
        neispravanIzraz();
    *a = '\0';
}

void proveraIspravnosti(char *c){
    char b = *(c - 1);
    char a = *c;
    if(!a){
        if((b != ')') && !isdigit(b) && !isPiOrE(b))
            neispravanIzraz();
        return;
    }
    if(a == '-'){
        if(!(isdigit(b)) && (b != ')') && (b != '(') && !isPiOrE(b))
            neispravanIzraz();
        return;
    }
    if(isOperator(a)){
        if(!(isdigit(b)) && (b != ')') && !isPiOrE(b))
            neispravanIzraz();
        return;
    }
    if(isdigit(a)){
        if((!isOperator(b)) && (!(isdigit(b)) && (b != '(') && (b != '.')))
            neispravanIzraz();
        return;
    }
    if(isPiOrE(a)){
        if(!isOperator(b) && (b != '('))
            neispravanIzraz();
        return;
    }
    if(isalpha(a)){
        if(!isOperator(b) && (b != '(') && !(isalpha(b) && !isPiOrE(b)))
            neispravanIzraz();
        return;
    }
    switch(a){
        case '.':   if(!isdigit(b))
                        neispravanIzraz();
                    break;
        case '(':   if(!isOperator(b) && (b != '(') && !(isalpha(b) && !isPiOrE(b)))
                        neispravanIzraz();
                    break;
        case ')':   if((!isdigit(b)) && (b != ')') && !isPiOrE(b))
                        neispravanIzraz();
                    break;
        default:    neispravanIzraz();
                    break;
    }
}
