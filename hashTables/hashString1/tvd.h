// Main y formularip de registro de nuevos personajes



ElemHT getKeyBoardElem(){
	ElemHT e = nuevoElemento();

	printf("Numero personaje: ");
		scanf("%s",e.nombre_personaje);
			limpiaBuffer();
	printf("Nombre real: ");
		scanf("%s",e.nombre_real);
			limpiaBuffer();
	printf("Tipo de criatura: ");
		scanf("%s",e.tipo_personaje);
	printf("Edad real 2018: ");
		scanf("%d",&e.edad_real);
	printf("Nacionalidad: ");
		scanf("%s",e.nacionalidad);
			limpiaBuffer();
	printf("Salud: ");
		scanf("%s",e.salud);
			limpiaBuffer();

	return e;
}

void Menu(FILE * in, Hash h, int n){
	String id;
	int selection;
	ElemHT e = nuevoElemento();

	printf("\tPersonajes: The vampire Diares\n");
	printf("1. Buscar\n");
	printf("2. Borrar\n");
	printf("3. Insertar\n");
	printf("4. Salir\n");
	printf("   Seleccione una opcion: ");
	scanf("%d",&selection);

	switch(selection){
		case 1: 
			limpiaPantalla();
			printf("\n\tSelection : (Buscar)\n");
			printf("   Teclee el nombre del personaje a buscar: ");
			scanf("%s",id);
			limpiaBuffer();
			if(estaEnHT(h,n,id)){
				impElemHT(htRecupera(h,n,id));
			}
			else
				printf("Personaje no encontrado\n");
			break;
		case 2: 
			limpiaPantalla();
			printf("\n\tSelection : (Eliminar)\n");
			printf("Teclee el nombre del personaje Borrar: ");
			scanf("%s",id);
			if(estaEnHT(h,n,id)){
				h = deleteToHash(h,n,id);
				printf("completed removal\n");
			}
			else
				printf("Elemento inexistente\n");
			break;
		case 3: 
			limpiaPantalla();
			printf("\n\tSelection : (Insertar)\n");
			e = getKeyBoardElem();
			if(estaEnHT(h,n,getNombrePersonaje(e)))
				printf("\nPersonaje existente\n");
			else
				h = htInsertar(h,n,e);
			break;
		case 4:
			printf("Ending ...\n");
			exit(0);
		default:
			printf("Opcion no valida!\n");
			exit(0);
	}
}