#include <stdio.h>
#include <stdlib.h>
#define DIM  100

/*
Scrivere un programma che chieda n valori
interi (massimo 100), li collochi in un vettore e inverta il vettore
(scambiando il primo elemento con l'ultimo, il secondo con il penultimo, etc.).
Si usi i puntatori.
*/

void caricaVett(int v[], int n) {//funzione carica del vettore
    int k;

    for(k = 0; k < n; k++) {
        printf("\nInserisci il valore della cella [%d]: ", k);
        scanf("%d", (v+k));
    }

}

void stampaVet(int v[], int n) {//funzione stampa del vettore
    int k;

    for(k = 0; k < n; k++) {
        printf("%d | ", *(v+k));
    }
}

void inverti(int v[], int n) {//funzione per invertire il vettore
    int k, j = n - 1, x;

    for(k = 0; k < n/2; k++) {
        x = *(v+k);
        *(v+k) = *(v+j-k);
        *(v+j-k) = x;
    }
  
}

int dimVet() {//funzione per definire la dimensione vettore
    int n;
    do {
        printf("Inserisci il numero di valori del vettore: ");
        scanf("%d", &n);
    } while(n < 0 || n > DIM);//la dimensione deve essere compresa tra 0 e 100

    return n;
}

int main() {
    int v[DIM];//inizializzato vettore con una dimensione fissa
    int n;


    n = dimVet();//dimensione del vettore intero

    caricaVett(v, n);//caricato vettore
    printf("VETTORE NORMALE: \n");
    stampaVet(v, n);//stampa del vettore

    inverti(v, n);//vettore invertito
    printf("\nVETTORE INVERTITO: \n");
    stampaVet(v, n);//stampa vettore invertito

    printf("\n");
    return 0;
}
