#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sistema.h"
#include "Elem.h"
#include "Lista.h"

int main(int argc, char const *argv[]){
    Lista prueba = Vacia();
    prueba = Cons(1, prueba);
    prueba = Cons(5, prueba);
    prueba = Cons(2, prueba);
    prueba = Cons(9, prueba);
    prueba = Cons(6, prueba);
    prueba = Cons(4, prueba);

    ImpLista(prueba);
    
    prueba = InsInIndex(3, prueba, 3);
    printf("\n");
    ImpLista(prueba);

    return 0;
}
