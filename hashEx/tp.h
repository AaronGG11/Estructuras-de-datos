
ElemHT getKeyBoardElem(){
	ElemHT e = nuevoElemento();

	printf("Numero atomico: ");
		scanf("%d",&e.numAtomico);
			limpiaBuffer();
	printf("Nombre: ");
		scanf("%s",e.nombre);
			limpiaBuffer();
	printf("simbolo: ");
		scanf("%s",e.simbolo);
	printf("Periodo: ");
		scanf("%d",&e.periodo);
	printf("Grupo: ");
		scanf("%s",e.grupo);
			limpiaBuffer();
	printf("Masa atomica: ");
		scanf("%f",&e.masaAtomica);
			limpiaBuffer();
	printf("Fecha: ");
		scanf("%s",e.fecha);
			limpiaBuffer();
	printf("Inventor: ");
		scanf("%s",e.inventor);

	return e;
}

void Menu(FILE * in, Hash h, int n){
	char id[20];
	int selection;
	ElemHT e = nuevoElemento();

	strcpy(id,"");
	usleep(500000);
	limpiaPantalla();

	printf("\n\n\t\tTabla periodica de los elementos quimicos\n");
	printf("\t1. Buscar\n");
	printf("\t2. Borrar\n");
	printf("\t3. Insertar\n");
	printf("\t4. Salir\n");
	printf("\t   Seleccione una opcion: ");
	scanf("%d",&selection);

	switch(selection){
		case 1: 
			limpiaPantalla();
			printf("\n\tSelection : (Buscar)\n");
			printf("\tTeclee el nombre del elemento a buscar: ");
			scanf("%s",id);
			usleep(500000);
			if(estaEnHT(h,n,id)){
				impElemHT(htRecupera(h,n,id));
			}
			else
				printf("\tElemento no encontrado\n");
			break;
		case 2: 
			limpiaPantalla();
			printf("\n\tSelection : (Eliminar)\n");
			printf("\tTeclee el nombre del elemento atomica Borrar: ");
			scanf("%s",id);
			usleep(500000);
			if(estaEnHT(h,n,id)){
				h = deleteToHash(h,n,id);
				printf("\tcompleted removal\n");
			}
			else
				printf("\tElemento inexistente\n");
			break;
		case 3: 
			limpiaPantalla();
			printf("\n\tSelection : (Insertar)\n");
			e = getKeyBoardElem();
			if(estaEnHT(h,n,getNombre(e)))
				printf("\n\tElemento existente\n");
			else
				h = htInsertar(h,n,e);
			break;
		case 4:
			printf("\tEnding ...\n");
			exit(0);
		default:
			printf("\tOpcion no valida!\n");
			exit(0);
	}
}


void procesoEjecutable(FILE * input,Hash hash,int tam){
	char control; 

	do{
		Menu(input,hash,tam);
		limpiaBuffer();
		printf("\n\tRealizar otra operacion?(S/N): ");
		scanf("%c",&control);
	}while((control == 'S')||(control == 's'));
}



