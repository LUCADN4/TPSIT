#include <stdio.h>
#include <stdlib.h>
/*
Scrivere un programma che permette all’utente di inizializzare un array unidimensionale
di float e facendo uso dell’aritmetica dei puntatori:
- individui gli elementi con valore ripetuti
-sommi i numeri rimasti
*/

int chiediDim() {
    int n;
    do {
        printf("Inserisci la dimensione del vettore: ");
        scanf("%d", &n);
    } while(n <= 0);
    return n;
}

int main() {
    int n;

    float b;
    float somma=0;
    float *v;

    n = chiediDim();
    v=(float *)malloc(n*sizeof(float));


    for(int k=0; k<n; k++) {
        printf("Inserisci valore per la cella [%d]: ", k);
        scanf("%f", (v+k));
    }

    printf("\n");

    for(int k=0; k<n; k++) {
        printf("%.2f ", *(v+k));
    }


    for(int j=0; j<n; j++) { //1 1 1 3
        b=*(v+j); //1
        for(int a=j+1; a<n; a++) {
            if(*(v+a)==b) {// 1 == 1
                *(v+a)=0;
                *(v+j)=0;
            }
        }
    }

    printf("\n");

    for(int k=0; k<n; k++) { // somma dei valori presenti nel vettore
        somma=somma+*(v+k);
    }

    printf("\n");
    printf("Somma dei rimanenti: %2.f", somma); // stampati i


    return 0;
}
