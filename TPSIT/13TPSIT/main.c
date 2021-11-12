#include <stdio.h>
#include <stdlib.h>

/*
si scrive una funzione malloc, in grado di allocare una matrice rettangolare di numeri
reali le cui dimensioni sono ricevute come parametri. La matrice viene inizializzata azzerando tutte le casele
*/

int main() {
    int rig = 0, col = 0, r = 0, c = 0;

    printf("Inserisci righe: ");
    scanf("%d",&rig);
    printf("Inserisci colonne: ");
    scanf("%d",&col);

    float ** mat = (float **)malloc(rig * sizeof(float*)); /// nel float finale va * PER LE MATRICI
    for(int k = 0; k < rig; k++) {
         mat[k] = (float *)malloc(col * sizeof(float)); //è una riga
    }

    //inizializza 0
    for( r = 0; r < rig; r++) {
        for(c = 0; c < col; c++) {
            mat[r][c] = 0;
        }
    }

    // stampa
    for(r = 0; r < rig; r++) {
        for( c = 0; c < col; c++) {
            printf("%.2f  ",mat[r][c]);
        }
        printf("\n");
    }

    return 0;
}
