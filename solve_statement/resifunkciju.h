#ifndef RESI_FUNKCIJU
#include "izracunajizraz.h"
#include "proveriizraz.h"
#include "stack.h"
#include <string.h>
#include <math.h>
#define RESI_FUNKCIJU
#define DUZINAIMENAFUNKCIJE 10
#define BROJFUNKCIJA 9

char* izracunajFunkciju(char* str, double* number);
double ctg(double a);
double actg(double a);
char* resiFunkciju(char* str, double* number, double(*f)(double));

const char* postojeceFunkcije[BROJFUNKCIJA] = {"sin", "cos", "tg", "ctg", "asin", "acos", "atg", "actg", "ln"};
double (*pokazivaciNaFunkcije[BROJFUNKCIJA])(double) = {sin, cos, tan, ctg, asin, acos, atan, actg, log};




#endif // RESI_FUNKCIJU
