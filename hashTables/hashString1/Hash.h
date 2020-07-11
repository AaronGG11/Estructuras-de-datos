
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


Hash htInsertar(Hash h, int n, ElemHT e){ // hash, tamaño propuesto de la hash y un elemento
	int id = getKey(e,n);
	h[id] = Cons(e,h[id]);

	return h;
}

ElemHT htRecupera(Hash h, int n, String id){ // hash, tamaño propuesto de la hash y un nombre a buscar
	Lista l = h[(valueofASCII(id))%numPrimoSig(n)];

	while((!sonIgualesNumeros(valueofASCII(getNombrePersonaje(Cabeza(l))),valueofASCII(id)))&&(!esVacia(l)))
		l = Resto(l);

	return Cabeza(l);
}

int estaEnHT(Hash h, int n, String id){ // hash, tamaño propuesto de la hash y un nombre a buscar
	Lista l = h[(valueofASCII(id))%numPrimoSig(n)];
	if(htEsVacia(h)||esVacia(l)) // si esta vacia la tabla o el indice 
		return 0;
	else{
		while(!esVacia(l)){
			if(sonIgualesNumeros(valueofASCII(getNombrePersonaje(Cabeza(l))),valueofASCII(id)))
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

		fscanf(in,"%s",e.nombre_personaje);
		fscanf(in,"%s",e.nombre_real);
		fscanf(in,"%s",e.tipo_personaje);
		fscanf(in,"%d",&e.edad_real);
		fscanf(in,"%s",e.nacionalidad);
		fscanf(in,"%s",e.salud);

		h = htInsertar(h,n,e);	
	}
	return h;
}

Hash deleteToHash(Hash h, int n, String id){
	Lista l = h[(valueofASCII(id))%numPrimoSig(n)];
	Lista s = Vacia();

		while(!(sonIgualesNumeros(valueofASCII(getNombrePersonaje(Cabeza(l))),valueofASCII(id)))&&!(esVacia(l))){
			s = Cons(Cabeza(l),s);
			l = Resto(l);
		}
		l = Resto(l);
		s = PegaListas(s,l);
		h[(valueofASCII(id))%numPrimoSig(n)] = s;

		return h;
}






