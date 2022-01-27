#ifndef IZRACUNAJ_IZRAZ
#define IZRACUNAJ_IZRAZ
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "stack.h"
#define starostOperacije(a) ((a) / 2)
#define MAKSZAGRADA 50
#define PI 3.141592653589793
#define E 2.718281828459045
#define MAKSDUZINAIZRAZA 100

struct vrstaPodatka{
    char vrsta;
    double podatak;
};

enum Vrsta{NISTA, BROJ, OZAGRADA, ZZAGRADA, OPERATOR, KRAJ = 100};
enum operacija{PLUS, MINUS, PUTA, PODELJENO, STEPEN};

double resenjeIzraza(char* izraz);
double izracunajIzraz(struct vrstaPodatka* p);
char* strToNumber(char* str, double* number);
void izrazDesifruj(char* a, struct vrstaPodatka* p);
void resiStekove(Stack *a, Stack *b, double c);
void resiZagrade(struct vrstaPodatka* p);

#endif // IZRACUNAJ_IZRAZ
