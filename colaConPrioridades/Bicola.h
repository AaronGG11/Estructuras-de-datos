
typedef struct Nodo{
		Elem dato;
		struct Nodo * siguiente;
		struct Nodo * anterior;
} *ApNodo;

typedef struct CNodo{
	ApNodo salida;
	ApNodo entrada;
} *Bicola;


Bicola nuevaB(){ // lista
	Bicola temporal = (Bicola)malloc(sizeof(struct CNodo));
	temporal -> salida = temporal -> entrada = NULL;
	return temporal;
}

Elem primeroD(Bicola c){ // solo de un lado -- cambiar nombre
	return c -> salida -> dato;
}

Elem primeroI(Bicola c){ // solo de un lado -- cambiar nombre
	return c -> entrada -> dato;
}

int esNuevaB(Bicola c){ // lista 
	return ((c -> salida == NULL) && (c -> entrada == NULL));
}


Bicola formarD(Bicola c,  Elem e){ // lista
	ApNodo temporal = (ApNodo)malloc(sizeof(struct Nodo));
	temporal -> dato = e; 
	temporal -> siguiente = NULL;

	if(esNuevaB(c)){
		c -> salida = c->entrada = temporal; // o es vacia o solo tiene un elemento 
		temporal -> anterior = temporal -> siguiente = NULL;
	}
	else{
		c -> salida -> siguiente = temporal;
		temporal -> anterior = c -> salida;
		c -> salida = temporal;
	}
	return c;
}


Bicola desformarD(Bicola c){ // lista
	c -> salida = c -> salida -> anterior;
	c -> salida -> siguiente = NULL;
	return c;
}


Bicola formarI(Elem e, Bicola c){ // lista
	ApNodo temporal = (ApNodo)malloc(sizeof(struct Nodo));
	temporal -> dato = e;
	temporal -> anterior = NULL;

	if(esNuevaB(c)){
		c -> salida = c -> entrada = temporal;
		temporal -> anterior = temporal -> siguiente = NULL;
	}
	else{
		c -> entrada -> anterior = temporal;
		temporal -> siguiente = c -> entrada;
		c -> entrada = temporal;
	}
	return c;
}

Bicola desformarI(Bicola c){ // lista
	if(c -> salida == c -> entrada)
		c -> salida = c -> entrada = NULL;
	else{
		c -> entrada = c -> salida = c -> entrada -> siguiente;
		c -> entrada -> anterior = NULL;
	}
	return c;
}

void ImpColaI(Bicola c){ // Lista
	ApNodo Nodo_Temporal = (ApNodo)malloc(sizeof(struct Nodo)); 
	Bicola temporal = nuevaB(); 
	temporal -> entrada = c -> entrada;
	Nodo_Temporal -> siguiente = c -> entrada;
	Nodo_Temporal -> anterior = NULL;
	Nodo_Temporal -> dato = c -> entrada -> dato;

	if(esNuevaB(c))
		printf("\n");
	else if(temporal -> entrada -> siguiente == NULL){
		ImpElem(primeroI(c));
		temporal -> entrada = temporal -> salida = NULL;
	}
	else{
		temporal -> entrada = c -> entrada -> siguiente;
		ImpElem(Nodo_Temporal -> dato);
		ImpColaI(temporal);
	}
	free(temporal);
}

void ImpColaD(Bicola c){ // Lista
	ApNodo Nodo_Temporal = (ApNodo)malloc(sizeof(struct Nodo)); 
	Bicola temporal = nuevaB(); 
	temporal -> salida = c -> salida;
	Nodo_Temporal -> anterior = c -> salida;
	Nodo_Temporal -> siguiente = NULL;
	Nodo_Temporal -> dato = c -> salida -> dato;

	if(esNuevaB(c))
		printf("\n");
	else if(temporal -> salida -> anterior == NULL){
		ImpElem(primeroD(c));
		temporal -> salida = temporal -> entrada = NULL;
	}
	else{
		temporal -> salida = c -> salida -> anterior;
		ImpElem(Nodo_Temporal -> dato);
		ImpColaD(temporal);
	}
	free(temporal);
}

Bicola formarConPrioridad(Elem e, Bicola c){ // lista
	ApNodo temporal = (ApNodo)malloc(sizeof(struct Nodo));
	temporal -> dato = e;
	temporal -> anterior = NULL;
	Bicola b = nuevaB();
	b -> entrada = c -> entrada;
	b -> salida = c -> salida;

	if(esNuevaB(c)){
		c -> salida = c -> entrada = temporal;
		temporal -> anterior = temporal -> siguiente = NULL;
	}
	else if(primeroD(b)>=e)
		formarD(c,e);
	else if(primeroI(b)<=e)
		formarI(e,c);
	else{
		while(primeroI(b)>e)
			b->entrada = b->entrada->siguiente;
		temporal->siguiente = b->entrada;
		b->entrada = b->entrada->anterior;
		temporal->anterior = b->entrada;
		b->entrada->siguiente = temporal;
		temporal->siguiente->anterior = temporal;
	}
	return c;
}
