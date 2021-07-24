

/*
//	Para elementos string 

typedef char*Elem;

void ImpElem(Elem e){
	printf("%s\n", e);
}

int esMenor(Elem x, Elem y){
	return strcmp(x,y)<0; /// Checarla
}

int sonIguales(Elem x, Elem y){
	return strcmp(x,y) == 0;
}
*/



typedef int Elem;

void ImpElem(Elem e){
	printf("%d\n", e);
}

int esMenor(Elem x, Elem y){
	return x < y;
}

int sonIguales(Elem x, Elem y){
	return x == y;
}