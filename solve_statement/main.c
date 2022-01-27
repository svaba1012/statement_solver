#include "proveriizraz.h"
#include "izracunajizraz.h"

int main(){
    double x;
    puts("Unesite izraz");
    char izraz[MAKSDUZINAIZRAZA];
    x = resenjeIzraza(izraz);
    printf("%lf\n", x);
    return 0;
}


