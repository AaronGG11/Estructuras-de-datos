#include<stdio.h>
#include<stdlib.h>
#include "Elem.h"
#include "Pila.h"

Pila LlenaCaracter(Pila,Elem);

int main(int argc, char const *argv[]){
	char l = 'Z';
	Pila p = empty();

	p = LlenaCaracter(p,l);

	while(!isEmpty(p)){
		ImpElem(Top(p));
		p = Pop(p);
	}

	return 0;
}




// 	La siguiente fucnionmete caracter a caracter a la Pila 
Pila LlenaCaracter(Pila p, Elem e){
	if(e > 'A'){
		return LlenaCaracter(Push(e,p),e-1);
	}
	else{
		return Push(e,p);
	}
}