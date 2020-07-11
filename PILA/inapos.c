#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Elem.h"
#include "Pila.h"

int esParI(Elem);
int esParD(Elem);
int esOps (Elem);
int prior (Elem);

int main(int argc, char *argv[]){

	char * pal = *++argv;
	Pila ops = empty();	
	char c;

	while(*pal){
		c = *pal;
		if(esParI(c))
			ops = Push(c,ops);
		else if(esParD(c)){
			while(!esParI(Top(ops))){
				ImpElem(Top(ops));
				ops = Pop(ops);
			}
			ops = Pop(ops);
		}
		else if(esOps(c))
			if(isEmpty(ops)||(prior(c)>prior(Top(ops))))
				ops = Push(c,ops);
			else{
				while(!isEmpty(ops)&&(prior(c)<=prior(Top(ops)))){
					ImpElem(Top(ops));
					ops = Pop(ops);
				}
				ops = Push(c,ops);
			}
		else ImpElem(c);
		pal++;	
	}	
	while(!isEmpty(ops)){
		ImpElem(Top(ops));
		ops = Pop(ops);
	}

	putchar('\n');

	return 0;
}


int esParI(Elem e){
	return e == '(';
}
	
int esParD(Elem e){
	return e == ')';
}

int esOps(Elem e){
	return (e=='^'||e=='*'||e=='/'||e=='+'||e=='-');
}

int prior(Elem e){
	switch(e){
		case '^': return 3;	break;
		case '*': return 2;	break;
		case '/': return 2; break;
		case '+': return 1;	break;
		case '-': return 1; break;
		default: return 0;
	}
}


















/*
	¿Como lo mando a la terminal?
	putchar(*pal++);
	1. gcc nombre.c
	2. ./a.out "cadena"

*/