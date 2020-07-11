 // ES COMPLETO, ES LLENO

typedef ArBin Heap; // monticulo

// esmAI

ArBin hazCompleto(Elem e, ArBin a){
	if(esVacio(a))
		return cons(e,vacio(),vacio());
	else if(((altura(izq(a)) == altura(der(a))+1)&&(esLleno(izq(a))))||
		((altura(izq(a)) == altura(der(a))+1)&&(!esLleno(der(a))))){
		return cons(e,izq(a),hazCompleto(e,der(a)));
	}
	else
		return cons(raiz(a),hazCompleto(e,izq(a)),der(a));
}

// altura(i) - altura(d) <=1
Heap hazHeap(Elem e, Heap i, Heap d){ // es como insertar
	if(esVacio(i))
		return cons(e,vacio(),vacio());
	else if(esVacio(d)){
		if(raiz(i) <= e)
			return cons(e,i,vacio());
		else
			return cons(raiz(i),cons(e,vacio(),vacio()),vacio());
	}
	else if((esMayorI(e,raiz(i)))&&(esMayorI(e,raiz(d))))
		return cons(e,i,d);
	else if(esMayor(raiz(i),raiz(d)))
		return cons(raiz(i),hazHeap(e,izq(i),der(i)),d);
	else
		return cons(raiz(d),i,hazHeap(e,izq(d),der(d)));
}

Heap consHeap(ArBin a){ // este ArBin es completo  //
	if(esVacio(a))
		return a;
	else //((altura(izq(a))-altura(der(a))) <= 1)
		return hazHeap(raiz(a),consHeap(izq(a)),consHeap(der(a)));
}


ArBin insertElems(Lista l, ArBin a){
	if(esVacia(l))
		return a;
	else
		return insertElems(Resto(l),hazCompleto(Cabeza(l),a));
}

void impHeap(ArBin a, int c){
	if(esVacio(a))
		return;
	else{
		impHeap(der(a),c+1);
		for(int i=0; i<c; i++){
			printf("  ");
		}
		impElem(raiz(a));
		printf("\n");
		impHeap(izq(a),c+1);
	}
}




