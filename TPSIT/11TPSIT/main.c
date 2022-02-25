#include <stdio.h>
#include <stdlib.h>
#define DIM  100

/*
Scrivere un programma che chieda n valori
interi (massimo 100), li collochi in un vettore e inverta il vettore
(scambiando il primo elemento con l'ultimo, il secondo con il penultimo, etc.).
Si usi i puntatori.
*/

void caricaVett(int *v, int n) {//funzione carica vettore
    int k;

    for(k = 0; k < n; k++) {
        printf("Inserisci il valore della cella [%d]: ", k);
        scanf("%d", v+k);
    }

}

void stampaVet(int *v, int n) {//funzione stampa vettore
    int k;

    for(k = 0; k < n; k++) {
        printf("%d | ", *(v+k));
    }
}

void inverti(int *v, int n) {
    int k, j = n - 1, x;

    for(k = 0; k < n/2; k++) { // 0 1 2 3 //3 1 2 3 //3 1 2 0
        x = *(v+k);//0
        *(v+k) = *(v+j-k);//0 -> 3
        *(v+j-k) = x;//3 -> 0
    }

}

int dimVet() {//controllo dimensione vettore
    int n;
    do {
        printf("Inserisci il numero di valori del vettore: ");
        scanf("%d", &n);
    } while(n < 0 || n > DIM);//numero non minore di 0 e maggiore di 100

    return n;
}

int main() {
    int n;
    n = dimVet();

    int *v =(int*)malloc(n*sizeof(int)); //allocazione dinamica del vettore

    caricaVett(v, n);//caricato vettore
    printf("VETTORE NORMALE: \n");
    stampaVet(v, n);//stampa vettore caricato

    inverti(v, n);//invertito vettore
    printf("\nVETTORE INVERTITO: \n");
    stampaVet(v, n);//stampa vettore invertito

    printf("\n");
    return 0;
}
