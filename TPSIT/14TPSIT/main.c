#include <stdio.h>
#include <stdlib.h>
/*
Scrivere un programma per leggere e stampare
array bidimensionale di interi.
Il programma richiede all’utente il numero
di righe e di colonne dopo di che richiede ad uno ad uno gli elementi da inserire
nell'array.
Il programma inoltre deve gestire dinamicamente l'allocazione
e la deallocazione della memoria.
*/

void stampa(int ** mat,int rig, int col){  //stampata matrice
for(int r = 0; r < rig; r++) {
        for( int c = 0; c < col; c++) {
            printf("%d  ",mat[r][c]);
        }
        printf("\n");     //si va a capo ogni volta
    }
}

void caricaMat(int ** mat, int rig, int col){//funzione carica matrice di interi
for( int r = 0; r < rig; r++) {
        for(int c = 0; c < col; c++) {
           printf("cella [%d][%d]: ",r,c);
           scanf("%d",&mat[r][c]);
        }
    }
}


int main()
{
      int rig = 0, col = 0, r = 0, c = 0;

    printf("Inserisci righe: "); //inserito numero di righe
    scanf("%d",&rig);
    printf("Inserisci colonne: ");//inserite numero di colonne
    scanf("%d",&col);

    int ** mat = (int **)malloc(rig * sizeof(int*)); // matrice dinamica, create numero di righe della matrice

    for(int k = 0; k < rig; k++) {
         *(mat + k) = (int *)malloc(col * sizeof(int)); // vettore dinamico, creati per ogni riga della matrice
    }

    //printf("%d",sizeof(int)); //
    //printf("%d",sizeof(int*)); // occupa sull'architettura sulla tua macchina

    // caricato vettore
    caricaMat(mat,rig,col);
    // stampa
    stampa(mat,rig,col);

    free(mat);

    return 0;
}

