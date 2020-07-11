
// Recordemos que una hash sera un arreglo de listas por lo que se requerira de doble apuntador

typedef Lista * Hash;	

Hash htVacio(){
	return NULL;
}

int htEsVacia(Hash h){
	return h == htVacio();
}

Hash creaHashTable(int n){
	int i;
	int tam = numPrimoSig(n);
	Hash ht = (Hash)malloc(sizeof(Lista)*tam);
	Lista l = Vacia();
	
	for(i = 0; i<tam; i++){
		ht[i] = l;
	}

	return ht;
}


Hash htInsertar(Hash h, int n, ElemHT e){
	int id = getKey(e);
	h[id] = InsOrd(e,h[id]);

	return h;
}

ElemHT htRecupera(Hash h, int n){ // Donde n es el id que del elemento que buscamos, 
	Lista l = h[n];

	while((!(sonIguales(getKey(Cabeza(l)),n)))&&(!esVacia(l))){
			l = Resto(l);
	}

	return Cabeza(l);
}

int estaEnHT(Hash h, int n){
	Lista l = h[n];
	if(htEsVacia(h)||esVacia(l)) // si esta vacia la tabla o el indice 
		return 0;
	else{
		while(!esVacia(l)){
			if(sonIguales(getKey(Cabeza(l)),n))
				return 1;
			else
				l = Resto(l); // la lista se altera pero no la tabla hash
		}
	}
	return 0; // Retornara el primer "return" que encuentre, si encuentra un " return 1" pues si esta en la tabla hash
}


ElemHT buscarElemTP(Hash h, int id){
		return Cabeza(h[id]);
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

Hash deleteToHash(Hash h, int n){
	Lista l = h[n];
	Lista s = Vacia();

		while(!(sonIguales(Cabeza(l).numAtomico,n))&&!(esVacia(l))){
			s = Cons(Cabeza(l),s);
			l = Resto(l);
		}
		l = Resto(l);
		s = PegaListas(s,l);
		h[n] = s;

		return h;
}






