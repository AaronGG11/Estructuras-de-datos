
typedef char* String;

typedef struct tp{
	String nombre_personaje;
	String nombre_real; 
	String tipo_personaje;
	int edad_real;
	String nacionalidad;
	String salud;
} ElemHT;

ElemHT nuevoElemento(){
	ElemHT e;
	
	e.nombre_personaje = (String)malloc(sizeof(100));
	e.nombre_real      = (String)malloc(sizeof(100));
	e.tipo_personaje   = (String)malloc(sizeof(100));
	e.edad_real        = 0;
	e.nacionalidad     = (String)malloc(sizeof(100));
	e.salud            = (String)malloc(sizeof(100));

	return e;
}

void impElemHT(ElemHT e){
	printf("\n\nNombre de personaje: %s\nNombre real: %s\nTipo de personaje: %s\nEdad 2018: %d\nNacionalidad: %s\nSalud: %s\n\n",e.nombre_personaje,e.nombre_real,e.tipo_personaje,e.edad_real,e.nacionalidad,e.salud);
}

int esNumPrimo(int n){
	int c = 0;

	for(int i = 1; i<=n; i++){
		if(n%i == 0)
			c++;
	}

	if(c == 2)
		return 1;
	else
		return 0;
}

int numPrimoSig(int n){
	if(esNumPrimo(n))
		return n;
	else
		return numPrimoSig(n+1);
}

//La clave se tomara a partir del valor asciidel nombre de personaje 

String getNombrePersonaje(ElemHT e){
	return e.nombre_personaje;
}

int valueofASCII(String a){
	int value = 0;

	for(int i=0; i<strlen(a); i++){
		value += a[i];
	}

	return value;
}

int getKey(ElemHT e, int n){ // elemento y tamaño propuesto de la hash -> es la funcion de dispersion
	return (valueofASCII(getNombrePersonaje(e)))%numPrimoSig(n);
}

int sonIgualesNumeros(int m, int n){
	return n == m;
}

int sonIgualesCadenas(String a, String b){
	return strcasecmp(a,b);
}

int esMenorNumeros(int x, int y){
	return x<y;
}

int esMenorCadenas(String a, String b){
	return strcasecmp(a,b) < 0;
}








