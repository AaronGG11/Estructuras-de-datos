typedef struct  Nodo{
	Elem dato;
	struct Nodo*sig;
}*ApNodo;

typedef struct cNodo{
	ApNodo sal;
	ApNodo ent;
}*Cola;

Cola Nueva(){
	Cola t = (Cola)malloc(sizeof(struct cNodo));
	t->sal = t->ent = NULL;
}

int EsNueva(Cola q){
	return ((q->sal == NULL)&&(q->ent == NULL));
}

Cola Formar (Cola q, Elem e){
	ApNodo t= (ApNodo)malloc(sizeof(struct Nodo));
	t -> dato = e; t -> sig = NULL;
	if(EsNueva(q))
		q->sal = q -> ent = t;
	else q->ent->sig = q->ent=t;
	
	return q;
}

Elem Primero(Cola q){
	return q->sal->dato;
}

Cola Desformar (Cola q){
	ApNodo t;
	if(q->sal == q->ent)
		return Nueva();
	else {
		t = q->sal;
		q->sal = q->sal->sig;
		free(t);
		return q;
	}
}

//Funcion que imprima la cola sin alterar la original 

void ImpCola (Cola q){
	Cola t = Nueva();
	t-> sal;
	t-> ent; 

	ImpElem(Primero(t));
	ImpCola(Desformar(t));
	free(t);
}