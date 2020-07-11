
typedef DicBin AVL;

AVL rotaDer(DicBin a){ // rota a la derecha 
	return cons(raiz(izq(a)),izq(izq(a)),cons(raiz(a),der(izq(a)),der(a)));
	//cons(raiz,izquierdo,derecho)
}

AVL rotaIzq(DicBin a){ // rota a la izquierda
	return cons(raiz(der(a)),cons(raiz(a),izq(a),izq(der(a))),der(der(a)));
}

AVL rotarDerIzq(DicBin a){ // primero izquierda y luego derecha -> eso explica lo anterior
	return rotaDer(cons(raiz(a),rotaIzq(izq(a)),der(a)));
}

AVL rotaIzqDer(DicBin a){ // primero derecho y luego izquierdo
	return rotaIzq(cons(raiz(a),izq(a),rotaDer(der(a))));
}

int isAVL(DicBin a){ // predicado, es avl el arbol binario ?, verifica la altura de la raiz y la de sus subarboles
	if(esVacio(a))
		return 1;
	else
		return ((abs(alturaArbol(izq(a))-alturaArbol(der(a)))<=1)&&(isAVL(izq(a))&&isAVL(der(a))));
}

int factBal(DicBin a){ // factor de balalnceo
	if(esVacio(a))
		return 0;
	else
		return alturaArbol(izq(a)) - alturaArbol(der(a));
}

AVL hazAVL(DicBin a){ // arreglar la funcion 
	if(isAVL(a))
		return a;
	else if(factBal(a)>=0){ // se desvalanceo por la izquierda , ocurrendos casos
		if(factBal(izq(a))>0) // der, der, rotacion a la derecha 
			a = rotaDer(a);
		else
			a = rotarDerIzq(a); // se hace primero el izquierdo 
	}
	else if(factBal(der(a))<=0)//
		a = rotaIzq(a);
	else
		a = rotaIzqDer(a);
	return hazAVL(cons(raiz(a),hazAVL(izq(a)),hazAVL(der(a)))); //
}

AVL consAVL(Elem e, AVL a){
		return hazAVL(insOrd(e,a));
}

void impAVL(AVL a, int c){
	if(esVacio(a))
		return;
	else{
		impAVL(der(a),c+1);
		for(int i=0; i<c; i++){
			printf("  ");
		}
		impElem(raiz(a));
		printf("\n");
		impAVL(izq(a),c+1);
	}
}


/// funcion que elimine un elemento del arbol 

int estaEn(Elem e, DicBin a){
	if(esVacio(a))
		return 0;
	else if(sonIguales(e,raiz(a)))
		return 1;
	else
		return (estaEn(e,izq(a))||estaEn(e,der(a)));
}

int minElem(AVL a){
	if(esHoja(a)||esVacio(izq(a)))
		return raiz(a);
	else
		return minElem(izq(a));
}


AVL borra(AVL a, Elem e){
	if(sonIguales(e,raiz(a))){
		if(esHoja(a))
			return vacio();
		else if(esVacio(der(a)))
			return izq(a);
		else if(esVacio(izq(a)))
			return der(a);
		else
			return hazAVL(cons(minElem(der(a)),izq(a),borra(der(a),minElem(der(a)))));
	}
	else if(esMenor(e,raiz(a)))
		return hazAVL(cons(raiz(a),borra(izq(a),e),der(a)));
	else
		return hazAVL(cons(raiz(a),izq(a),borra(der(a),e)));
}


/*
AVL hazAVL(DicBin a){ // arreglar la funcion 
	if(isAVL(a))
		return a;
	else if(factBal(a)>0){ // se desvalanceo por la izquierda , ocurrendos casos
		if(factBal(izq(a))>0) // der, der, rotacion a la derecha 
			a = rotaDer(a);
		else
			a = rotarDerIzq(a); // se hace primero el izquierdo 
	}
	else if(factBal(der(a))<0)
		a = rotaIzq(a);
	else
		a = rotaIzqDer(a);
	return cons(raiz(a),hazAVL(izq(a)),hazAVL(der(a)));
}
*/


// + + simple
// 
// generar numeros aleatorios del 1 - 100,000
// arreglo de numerorango 0 - 999,999, que jamas tenga negativo, 5 en 5+1, que pregunte cuantos quiere generar 

// d d
// d i
// i i
// i d
// 