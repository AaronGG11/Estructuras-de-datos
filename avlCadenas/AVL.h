
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
		return ((abs(alturaArbol(izq(a))-alturaArbol(der(a))) <= 1)&&isAVL(izq(a)) && isAVL(der(a)));
}

int factBal(DicBin a){ // factor de balalnceo
	if(esVacio(a))
		return 0;
	else
		return alturaArbol(izq(a)) - alturaArbol(der(a));
}

AVL hazAVL(DicBin a){
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

AVL consAVL(Elem e, AVL a){
		return hazAVL(insOrd(e,a));
}

// + + simple
// 
// generar numeros aleatorios del 1 - 100,000
// arreglo de numerorango 0 - 999,999, que jamas tenga negativo, 5 en 5+1, que pregunte cuantos quiere generar 

// d d
// d i
// i i
// i d
// 