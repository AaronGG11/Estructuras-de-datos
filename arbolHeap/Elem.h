
typedef char * Elem;

/*
void impElem(ElemNum x){
	printf("%d\t",x);
}

int esMayorI(ElemNum e, ElemNum d){
	return e >= d;
}

int esMayor(ElemNum e, ElemNum d){
	return e > d;
}
*/

int sonIguales(Elem x, Elem y){
	return strcasecmp(x,y) == 0;
}

void impElem(Elem x){
	printf("%s\n",x);
}

int esMenor(Elem x, Elem y){
	return strcasecmp(x,y)<0; /// Checarla
}

int esMayorI(Elem e, Elem d){
	if (strcasecmp(e,d) >= 0)
		return 1;
	else
		return 0;
}

int esMayor(Elem e, Elem d){
	if (strcasecmp(e,d) > 0)
		return 1;
	else
		return 0;
}