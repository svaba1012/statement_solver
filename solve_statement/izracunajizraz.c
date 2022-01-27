#include "izracunajizraz.h"

double izracunajIzraz(struct vrstaPodatka* p){
    Stack brojevi = createStack();
    Stack oper = createStack();
    double starostPrethodne = -1;
    for(;p -> vrsta != ZZAGRADA && p -> vrsta != KRAJ; p++){
        if(p -> vrsta == NISTA)
            continue;
        if(p -> vrsta == BROJ)
            brojevi = pushOnStack(brojevi, p -> podatak);
        else if((p -> vrsta == OPERATOR) && !(((p - 1) -> vrsta == OZAGRADA) && (p -> podatak == MINUS))){
            if(starostPrethodne >= starostOperacije(p -> podatak)){
                resiStekove(&brojevi, &oper, p -> podatak);
            }
            oper = pushOnStack(oper, p -> podatak);
            starostPrethodne = starostOperacije(p -> podatak);
        }
    }
    if(!isEmpty(oper))
       resiStekove(&brojevi, &oper, PLUS);
    brojevi = popFromStack(brojevi, &starostPrethodne);
    return starostPrethodne;
}

char* strToNumber(char *str, double* number){
    *number = 0;
    double j = 1;
    if((*(str - 1) == '-') && (*(str - 2) == '(')){
        j = -1;
    }
    if(isPiOrE(*str)){
        if(*str == 'e')
            *number = E;
        if(*str == 'p')
            *number = PI;
        *number *= j;
        return str + 1;
    }
    if((*str == '0') && (*(str + 1) != '.'))
        neispravanIzraz();
    while(isdigit(*str)){
        *number = *number * 10 + *str - '0';
        str++;
    }
    if(*str == '.'){
        str++;
        double i = 0.1;
        while(isdigit(*str)){
            *number += (*str - '0') * i;
            i /= 10;
            str++;
        }
    }
    *number *= j;
    return str;
}

void izrazDesifruj(char* a, struct vrstaPodatka* p){
    for(; *a; p++){
        if(isdigit(*a) || isPiOrE(*a)){
            double x;
            a = strToNumber(a, &x);
            p -> vrsta = BROJ;
            p -> podatak = x;
        }else if(isOperator(*a)){
            p ->vrsta = OPERATOR;
            if(*a == '+')
                p ->podatak = PLUS;
            else if(*a == '-')
                p -> podatak = MINUS;
            else if(*a == '*')
                p -> podatak = PUTA;
            else if(*a == '/')
                p -> podatak = PODELJENO;
            else if(*a == '^')
                p -> podatak = STEPEN;
            a++;
        }else if(isalpha(*a) && !isPiOrE(*a)){
            double x;
            a = izracunajFunkciju(a, &x);
            p -> vrsta = BROJ;
            p -> podatak = x;
            a++;
        }else{
            switch(*a){
                case '(':   p -> vrsta = OZAGRADA;
                            p -> podatak = 0;
                            break;
                case ')':   p -> vrsta = ZZAGRADA;
                            p -> podatak = 0;
                            break;
            }
            a++;
        }
    }
    p -> vrsta = KRAJ;
    p -> podatak = 0;
}

void resiStekove(Stack *brojevi, Stack *oper, double c){
    double drugi, prvi = 1;
    double operacija = MINUS;
    *brojevi = popFromStack(*brojevi, &drugi);
    while(!isEmpty(*oper)){
                    *oper = popFromStack(*oper, &operacija);
                    if(starostOperacije(c) > starostOperacije(operacija)){
                        *oper = pushOnStack(*oper, operacija);
                        break;
                    }
                    *brojevi = popFromStack(*brojevi, &prvi);
                    if(operacija == PLUS)
                        drugi = prvi + drugi;
                    else if(operacija == MINUS)
                        drugi = prvi - drugi;
                    else if(operacija == PUTA)
                        drugi = prvi * drugi;
                    else if(operacija == PODELJENO)
                        drugi = prvi / drugi;
                    else if(operacija == STEPEN)
                        drugi = pow(prvi, drugi);
                }
                *brojevi = pushOnStack(*brojevi, drugi);
}

void resiZagrade(struct vrstaPodatka* p){
    struct vrstaPodatka *pozicijaZagrada[MAKSZAGRADA];
    struct vrstaPodatka *q;
    double x;
    for(int i = 0; p -> vrsta != KRAJ; p++){
        if(p -> vrsta == OZAGRADA){
            pozicijaZagrada[i++] = p;
        }else if(p -> vrsta == ZZAGRADA){
            q = pozicijaZagrada[--i];
            x = izracunajIzraz(q + 1);
            q -> podatak = x;
            q -> vrsta = BROJ;
            while(q < p){
                q++;
                q -> vrsta = NISTA;
            }
        }
    }
}

double resenjeIzraza(char* izraz){
    struct vrstaPodatka a[MAKSDUZINAIZRAZA];
    upisiBezRazmaka(izraz);
    izrazDesifruj(izraz, a);
    double x;
    resiZagrade(a);
    x = izracunajIzraz(a);
    return x;
}

