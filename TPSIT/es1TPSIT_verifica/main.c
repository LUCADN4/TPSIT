#include <stdio.h>
#include <stdlib.h>
///LUCA DI NICOLA es1


void stampa(float ** mat,int rig, int col) {//stampata matrice
    for(int r = 0; r < rig; r++) {
        for( int c = 0; c < col; c++) {
            printf("%.2f  ",mat[r][c]);// stampato valore della cella puntata
        }
        printf("\n");//si va a capo per il prossimo array da stampare
    }
}

void caricaMat(float ** mat, int rig, int col) {// la matrice viene caricata
    for( int r = 0; r < rig; r++) {
        for(int c = 0; c < col; c++) {
            printf("cella [%d][%d]: ",r,c);
            scanf("%f",&mat[r][c]);// inserito valore nella cella associata
        }
    }
}

int dim() {
    int n;
    do {
        printf("\nInserisci volare: ");
        scanf("%d", &n);
    } while(n <= 0);  // controllo dimensione per riga e collonne non inferiore a 0

    return n; // ritorno del numero inserito per numero di righe e colenne
}

void maggiore(float ** mat,int rig, int col,float *v) {//cercato valore maggiore per ogni riga della matrice
    float max = 0;

    for( int r = 0; r < rig; r++) {
        max = mat[r][0];// inserito come valore massimo la prima cella per ogni colonna
        for(int c = 0; c < col; c++) {
            if(max < mat[r][c]) {// confronto per trovare il maggiore nella riga
                max = mat[r][c];
            }
        }
        v[r] = max; // inserito il numero maggiore per riga nel vettore
    }
}

void stampaV(float *v, int rig) {
    for(int k=0; k < rig; k++) {
        printf("%.2f |", *(v+k));
    }
}

int main() {
    int rig = 0, col = 0;


    printf("Righe");
    rig = dim();// controllo numero di riche non sia inferiore di 0
    printf("Colonne");
    col = dim();// controllo numero di colonne non sia inferiore di 0

    float ** mat = (float **)malloc(rig * sizeof(float*)); // matrice dinamica, create numero di righe della matrice

    for(int k = 0; k < rig; k++) {
        *(mat + k) = (float *)malloc(col * sizeof(float)); // vettore dinamico, creati per ogni colonne della matricde
    }

    caricaMat(mat,rig,col);
    stampa(mat,rig,col);

    float *v = (float*)malloc(rig*sizeof(float));

    maggiore(mat,rig,col,v); // passata matrice e vettore dove viene fatto il controllo per trovare il maggiore per ogni riga
    printf("\n VETTORE CARICATO\n");
    stampaV(v,rig);
    // stampa del vettore caricato

    free(mat);
    // pulito, tolto lo spazio occupato dalla matrice
    free(v);
    // pulito, tolto lo spazio occupato dal vettore


    return 0;
}
