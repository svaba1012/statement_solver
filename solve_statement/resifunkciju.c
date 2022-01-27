#include "resifunkciju.h"

char* izracunajFunkciju(char* str, double* number){
    char funkcija[DUZINAIMENAFUNKCIJE];
    int i;
    char *p;
    for(p = funkcija; *str != '('; *p++ = *str++)
        ;
    *p = '\0';
    for(i = 0; i < BROJFUNKCIJA ; i++){
        if(strcmp(funkcija, postojeceFunkcije[i]) == 0)
            break;
    }
    if(i == BROJFUNKCIJA)
        neispravanIzraz();
    str = resiFunkciju(str, number, pokazivaciNaFunkcije[i]);
    return str;
}

double ctg(double a){
    return 1 / tan(a);
}

double actg(double a){
    return atan(1 / a);
}

char* resiFunkciju(char* str, double* number, double(*f)(double)){
    struct vrstaPodatka a[MAKSDUZINAIZRAZA];
    Stack zagrade = createStack();
    zagrade = pushOnStack(zagrade, 1);
    str++;
    char *p;
    for(p = str; !isEmpty(zagrade); p++){
        if(*p == '(')
            zagrade = pushOnStack(zagrade, 1);
        if(*p == ')')
            zagrade = popFromStack(zagrade, number);
    }
    *(--p) = '\0';
    izrazDesifruj(str, a);
    resiZagrade(a);
    *number = f(izracunajIzraz(a));
    return p;
}
