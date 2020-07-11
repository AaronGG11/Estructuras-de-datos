

typedef char * Elem;

void impElem(Elem e){
	printf("%s\n", e);
}

int esMenor(Elem x, Elem y){
	return strcmp(x,y)<0; /// Checarla
}

int sonIguales(Elem x, Elem y){
	return strcmp(x,y) == 0;
}