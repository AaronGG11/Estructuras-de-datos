
// Recordemos que una hash sera un arreglo de listas por lo que se requerira de doble apuntador

typedef Lista * Hash;	

Hash htVacio(){
	return NULL;
}

int htEsVacia(Hash h){
	return h == htVacio();
}

Hash creaHashTable(int n){

	Hash ht = (Hash)malloc(sizeof(Lista)*n);
	Lista l = Vacia();
	
	for(int i = 0; i<n; i++){
		ht[i] = l;
	}

	return ht;
}

Hash htInsertar(Hash h, int n, ElemHT e){ // hash, tamaño final de la hash y un elemento
	int id = valueHash(valueOf(getNombre(e)), n); 
	h[id] = Cons(e,h[id]);

	return h;
}

ElemHT htRecupera(Hash h, int n, String id){ // hash, tamaño final de la hash y un identificar a buscar
	Lista l = h[valueHash(valueOf(id),n)];

	while((!sonLasMismas(getNombre(Cabeza(l)),id))&&(!esVacia(l))){
		l = Resto(l);
	}

	return Cabeza(l);
}

int estaEnHT(Hash h, int n, String id){ // hash, tamaño final de la hash y un identificador a buscar
	Lista l = h[valueHash(valueOf(id),n)];
	if(htEsVacia(h)||esVacia(l)) // si esta vacia la tabla o el indice 
		return 0;
	else{
		while(!esVacia(l)){
			if(sonLasMismas(getNombre(Cabeza(l)),id))
				return 1;
			else
				l = Resto(l); // la lista se altera pero no la tabla hash
		}
	}
	return 0; // Retornara el primer "return" que encuentre, si encuentra un " return 1" pues si esta en la tabla hash
}


Hash addFileToHash(FILE * in, Hash h, int n){
	while(!feof(in)){
		ElemHT e = nuevoElemento();

		fscanf(in,"%d",&e.numAtomico);
		fscanf(in,"%s",e.nombre);
		fscanf(in,"%s",e.simbolo);
		fscanf(in,"%d",&e.periodo);
		fscanf(in,"%s",e.grupo);
		fscanf(in,"%f",&e.masaAtomica);
		fscanf(in,"%s",e.fecha);
		fscanf(in,"%s",e.inventor);

		h = htInsertar(h,n,e);	
	}
	return h;
}

Hash deleteToHash(Hash h, int n, String id){
	Lista l = h[valueHash(valueOf(id),n)];
	Lista s = Vacia();

		while(!(sonLasMismas(getNombre(Cabeza(l)),id))&&!(esVacia(l))){
			s = Cons(Cabeza(l),s);
			l = Resto(l);
		}

		l = Resto(l);
		s = PegaListas(s,l);
		h[valueHash(valueOf(id),n)] = s;

		return h;
}







