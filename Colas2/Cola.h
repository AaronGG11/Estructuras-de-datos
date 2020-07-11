
typedef struct Nodo{
		Elem dato;
		struct Nodo * siguiente;
} *ApNodo;

typedef struct CNodo{
	ApNodo salida;
	ApNodo entrada;
} *Cola;


Cola nueva(){
	Cola temporal = (Cola)malloc(sizeof(struct CNodo));
	temporal -> salida = temporal -> entrada = NULL;
	return temporal;
}

Elem primero(Cola c){
	return c -> salida -> dato;
}

int esNueva(Cola c){
	return ((c -> salida == NULL) && (c -> entrada == NULL));
}


Cola formar(Cola c,  Elem e){
	ApNodo temporal = (ApNodo)malloc(sizeof(struct Nodo));
	temporal -> dato = e; 
	temporal -> siguiente = NULL;

	if(esNueva(c))
		c -> salida = c->entrada = temporal;
	else
		c -> entrada = c -> entrada -> siguiente = temporal;
	return c;
}


Cola desformar(Cola c){
	if(c -> salida == c -> entrada)
		c -> salida = c -> entrada = NULL;
	else
		c -> salida = c -> salida -> siguiente;
	return c;
}

void ImpCola(Cola c){
	Cola temporal = nueva(); 
	temporal -> entrada = c -> entrada;
	temporal -> salida = c -> salida;

	// Ahora, temporal es una copia de C, que no la modificara

	if(esNueva(c))
		printf("\n");
	else{
		ImpElem(primero(temporal));
		ImpCola(desformar(temporal));
		/*Cada vez que imprime un elemento, se desforma ese elemento 
		de la copia temporal, y al ser recursiva, vuelve a llamar a la
		funcion pero ahora con parametro copia de temporal, y crea 
		nuevos temporales hasta que no se cumpla la funcion recursiva  */
	}
	free(temporal);
}



