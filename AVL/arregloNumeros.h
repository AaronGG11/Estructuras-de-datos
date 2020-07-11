


void generaNumeros(int numeroAleatorio[], int numeros){

     //Indices de 0 a 9, resultan 10 numeros
    int i, j;
    int hayRepeticiones = 1;

    for (i=0; i<=numeros; i++) {
        numeroAleatorio[i] = 1 + rand()%100000;
    }

//Comprobar repeticiones
    while (hayRepeticiones == 1) {
        hayRepeticiones = 0;
        for (i=0; i<=numeros; i++) {
            for (j=i+1; j<=numeros; j++) {

                if (numeroAleatorio[i] == numeroAleatorio[j] && numeroAleatorio[i] !=numeros) { //Repetición
                    numeroAleatorio[i] = numeroAleatorio[i] +1;
                    hayRepeticiones = 1;
                }
                if (numeroAleatorio[i] == numeroAleatorio[j] && numeroAleatorio[i] ==numeros) { //Repetición
                    numeroAleatorio[i] = numeroAleatorio[i] +1 + rand()%100000;
                    hayRepeticiones = 1;
                }
            }
        }
    }

/*
    for (i=0; i<=numeros; i++) {
        printf("%d\n", numeroAleatorio[i]);
    }
*/
}

