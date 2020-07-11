
typedef ArBin DicBin;

DicBin insOrd(Elem e, DicBin a){
	if(esVacio(a))
		return cons(e,vacio(),vacio());
	else if(esMenor(e,raiz(a)))
		return cons(raiz(a),insOrd(e,izq(a)),der(a));
	else if(esMayor(e,raiz(a)))
		return cons(raiz(a),izq(a),insOrd(e,der(a)));
	else{
		a -> contador += 1;
		return a;
	}
}

// 2^n -1, n -> altura
// nievl, la raiz esta en el nivel 0
// arbol degerado, solo crece de un lado 
// trace potting, meter al arbol un archivo con las palabras ordenadas de manera lexicografica 