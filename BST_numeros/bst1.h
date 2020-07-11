#include <stdio.h>
#include <stdlib.h>
#include "ArbolBinario.h"


typedef ArBin DicBin;

DicBin insOrd(Elem e, DicBin a){
	if(esVacio(a))
		return conA(e,vacio(),vacio());
	else if(esmenor(e,raiz(a)))
		return consA(raiz(a),insOrd(e,izq(a)),der(a));
	else
		return consA(raiz(a),izq(a),insOrd(e,der(a)));
}