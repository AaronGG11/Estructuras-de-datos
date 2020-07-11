

typedef char * Elem;

void impElem(Elem e){
	printf("%s\n", e);
}

int esMenor(Elem x, Elem y){
	return strcasecmp(x,y) < 0; /// Checarla
}

int esMayor(Elem x, Elem y){
	return strcasecmp(x,y) > 0;
}

int sonIguales(Elem x, Elem y){
	return strcasecmp(x,y) == 0;
}