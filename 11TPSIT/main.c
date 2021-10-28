#include <stdio.h>
#include <stdlib.h>
#define DIM  100

/*
Scrivere un programma che chieda n valori
interi (massimo 100), li collochi in un vettore e inverta il vettore
(scambiando il primo elemento con l'ultimo, il secondo con il penultimo, etc.).
Si usi i puntatori.
*/

void caricaVett(int v[], int n) {
    int k;

    for(k = 0; k < n; k++) {
        printf("\nInserisci il valore della cella [%d]: ", k);
        scanf("%d", (v+k));
    }

}

void stampaVet(int v[], int n) {
    int k;

    for(k = 0; k < n; k++) {
        printf("%d | ", *(v+k));
    }
}

void inverti(int v[], int n) {
    int k, j = n - 1, x;

    for(k = 0; k < n/2; k++) {
        x = *(v+k);
        *(v+k) = *(v+j-k);
        *(v+j-k) = x;
    }
    return;
}

int dimVet() {
    int n;
    do {
        printf("Inserisci il numero di valori del vettore: ");
        scanf("%d", &n);
    } while(n < 0 || n > DIM);

    return n;
}

int main() {
    int n;
    n = dimVet();
    int *v =(int*)malloc(n*sizeof(int));

    caricaVett(v, n);
    printf("VETTORE NORMALE: \n");
    stampaVet(v, n);

    inverti(v, n);
    printf("\nVETTORE INVERTITO: \n");
    stampaVet(v, n);

    printf("\n");
    return 0;
}
