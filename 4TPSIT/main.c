#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30

typedef struct {
    char num[DIM];
    char titFilm[DIM];
    char genere[DIM];
    char annoUscita[DIM];
    char dispo[DIM];
} Cinema;

void caricaVett(Cinema v[], int n, char nomeFilm[]) {
    FILE *fp;
    int c=0;
    char line[100];

    fp = fopen(nomeFilm, "r");

    for(int i = 0;i < n; i++){
        fgets(line, 100, fp);
        char* pezzo = strtok(line, ",");

        while(pezzo != NULL){
            switch(c){
            case 0:
                strcpy((*(v+i)).num, pezzo);
                break;
            case 1:
                strcpy((*(v+i)).titFilm, pezzo);
                break;
            case 2:
                strcpy((*(v+i)).genere, pezzo);
                break;
            case 3:
                strcpy((*(v+i)).annoUscita, pezzo);
                break;
            case 4:
                strcpy((*(v+i)).dispo, pezzo);
                break;
            }
            c++;
            pezzo = strtok(NULL, ",");
        }
        c=0;
    }
}

void stampVett(Cinema v[], int n){
    for(int k = 0;k < n;k++){
        printf("%s\t%s\t%s\t%s\t%s", (*(v+k)).num, (*(v+k)).titFilm, (*(v+k)).genere, (*(v+k)).annoUscita, (*(v+k)).dispo);
    }
}

int main() {
    Cinema film[DIM];
    caricaVett(film,DIM, "listafilm.csv");
    stampVett(film, DIM);
    return 0;
}
