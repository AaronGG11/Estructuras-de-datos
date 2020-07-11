
typedef Lista Conjunto;

Conjunto vacioC(){
	return Vacia();
}

int esVacioC(Conjunto s){
	return s == vacioC();
}

int estaEnC(Elem e, Conjunto s){
	if(esVacioC(s))
		return 0;
	else if(sonIguales(e,Cabeza(s)))
		return 1;
	else
		return estaEnC(e,Resto(s)); 
}

Conjunto insertaC(Elem e, Conjunto s){
	if(esVacioC(s))
		return Cons(e,s);
	else if(estaEnC(e,s))
		return s;
	else 
		return Cons(e,s);	 
}

Conjunto elimina(Elem e, Conjunto s){
	if(!estaEnC(e,s))
		return s;
	else if(sonIguales(e,Cabeza(s)))
		return Resto(s);
	else
		return Cons(Cabeza(s),elimina(e,Resto(s)));		
}

Conjunto Union(Conjunto s1, Conjunto s2){
	if(esVacioC(s1))
		return s2;
	else if(esVacioC(s2))
		return s1;
	else if(estaEnC(Cabeza(s1),s2))
		return Union(Resto(s1),s2);
	else
		return insertaC(Cabeza(s1),Union(s2,Resto(s1)));
}

Conjunto Interseccion(Conjunto s1, Conjunto s2){
	if(esVacioC(s1)||esVacioC(s2))
		return vacioC();
	else if(estaEnC(Cabeza(s1),s2))
		return insertaC(Cabeza(s1),Interseccion(elimina(Cabeza(s1),s2),s1));
	else 
		return Interseccion(Resto(s1),s2);
}

void ImpConjunto(Conjunto l){
	if(!esVacia(l)){
		ImpElem(Cabeza(l));
		ImpConjunto(Resto(l));
	}
}

Conjunto OrdConjunto(Conjunto l){
	if(esVacia(l)){
		return l;
	}
	else{
		return InsOrd(Cabeza(l),OrdConjunto(Resto(l)));
	}
}

Conjunto Diferiencia(Conjunto s1, Conjunto s2){
	if(esVacioC(s1))
		return vacioC();
	else if(estaEnC(Cabeza(s1),s2))
		return Diferiencia(Resto(s1),elimina(Cabeza(s1),s2));
	else
		return insertaC(Cabeza(s1),Diferiencia(Resto(s1),s2));
}

int Cardinalidad(Conjunto s){
	if(esVacioC(s))
		return 0;
	else
		return 1 + Cardinalidad(Resto(s));
}









