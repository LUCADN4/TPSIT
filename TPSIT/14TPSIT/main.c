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

int main()
{
      int rig = 0, col = 0, r = 0, c = 0;

    printf("Inserisci righe: ");
    scanf("%d",&rig);
    printf("Inserisci colonne: ");
    scanf("%d",&col);

    int ** mat = (int **)malloc(rig * sizeof(int*)); /// nel int finale va * PER LE MATRICI
    for(int k = 0; k < rig; k++) {
         mat[k] = (int *)malloc(col * sizeof(int)); //è una riga
    }


    for( r = 0; r < rig; r++) {
        for(c = 0; c < col; c++) {
           printf("cella [%d][%d]: ",r,c);
           scanf("%d",&mat[r][c]);
        }
    }

    // stampa
    for(r = 0; r < rig; r++) {
        for( c = 0; c < col; c++) {
            printf("%d  ",mat[r][c]);
        }
        printf("\n");
    }

    free(mat);

    return 0;
}

