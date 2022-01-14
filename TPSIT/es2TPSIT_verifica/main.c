#include <stdio.h>
#include <stdlib.h>
#define DIM  20


void leggiDaFile(char nomeFile[], float *v, int n, int *nValori){
    FILE fp;
    int k = 0;

    fp = fopen(nomeFile, "r");      //apro il file in lettura

    if(fp == NULL){         //controllo che il file ci sia
        printf("Errore nel file");
    }else{
        while(k < n && fscanf(fp, "%d", &nValori) != EOF){     //leggo ogni elemento del file fino a che i dati saranno terminati
            for(int i = 0; i < *nValori; i++){
                fscanf(fp, "%f", (v+i));
            }
            k++;
        }
    }
    fclose(fp);
    return;
}

int main()
{
    float v;
    int nValori = 0;

    v = (float) malloc(DIM * sizeof(float));

    leggiDaFile("verifica.dat", v, DIM, &nValori);

    printf("Dal file si sono letti %d elementi float", nValori);
    for(int k = 0; k < nValori; k++){
        printf("%.2f | ", *(v+k));
    }

    free(v);
    printf("\n");
    return 0;
}
