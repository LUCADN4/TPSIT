#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30
#define LUNG 100


typedef struct {
    char num[LUNG];
    char titFilm[LUNG];
    char genere[LUNG];
    char annoUscita[LUNG];
    char dispo[LUNG];
} Cinema;

void caricaVett(Cinema v[], int n, char nomeFilm[]) {
    FILE *fp;
    int c=0;
    char line[100]; // riga del file massima lunghezza

    fp = fopen(nomeFilm, "r"); //apertura del file

    for(int i = 0; i < n; i++) {
        fgets(line, 100, fp);
        char* pezzo = strtok(line, ",");  // solo alla riga
        //atoil si usa per gli interi quindi per anno e per annoUscita  atof per i float
        while(pezzo != NULL) {           // poi un NULL per ogni campo da prendere
            switch(c) {
            case 0:
                strcpy(v[i].num, pezzo); // fa una copia e la inserisce nella cella della struttura destinataria
                break;
            case 1:
                strcpy(v[i].titFilm, pezzo); // fa una copia e la inserisce nella cella della struttura destinataria
                break;
            case 2:
                strcpy(v[i].genere, pezzo); // fa una copia e la inserisce nella cella della struttura destinataria
                break;                      //per saltare e ricominciare il ciclo
            case 3:
                strcpy(v[i].annoUscita, pezzo); // fa una copia e la inserisce nella cella della struttura destinataria
                break;
            case 4:
                strcpy(v[i].dispo, pezzo);   // fa una copia e la inserisce nella cella della struttura destinataria
                break;
            }
            c++;
            pezzo = strtok(NULL, ",");
        }
        c=0;
    }
    fclose(fp); // chiusura file
}

void stampVett(Cinema v[], int n) {
    for(int k = 0; k < n; k++) {
        printf("%s      %s      %s      %s      %s", v[k].num, v[k].titFilm, v[k].genere, v[k].annoUscita, v[k].dispo);
    }
}

int contaRighe(Cinema v[], int n, char nomeFilm[]) {
    FILE *fp;
    int c = 0,k = 0;
    char line[100]; // riga del file massima lunghezza

    fp = fopen(nomeFilm, "r"); //apertura del file

    while(){ // usa while
        fgets(line, 100, fp);
        c++;
    }


    fclose(fp);
    return c;

}
int main() {
    int n,c;
    Cinema *film;

    c = contaRighe(film,LUNG, "listafilm.csv");

    film = (Cinema*)malloc( n * sizeof (Cinema));
                                                    // vettore di struttura
    caricaVett(film,c, "listafilm.csv"); // richiamo funzione leggi

    stampVett(film, c); // stampa il contenuto

    free(film); // livera area di memoria occupata array
    return 0;
}
