#include <stdio.h>
#include <stdlib.h>
#define DIM 20
/*
Esercizio 3
Per descrivere i pazienti di una clinica disponi del seguente tipo di dato:
 Paziente
typedef struct
{
char nome[256] ;
char cognome[256] ;
int matricola;
int pressione[2]; // minima e massima
int temp[3]; // temp della mattina e pomeriggio e sera
float parcella; // in euro quello che deve al dottore
} Paziente; // Iniziale maiuscola
Scrivi i Prototipi,le chiamate e il codice delle seguenti specifiche:
1. definisci una variabile rossi di tipo paziente;
2. definisci un array di 20 pazienti di nome clinica e di tipo paziente;
3. imposta una procedura (prototipo) con il corretto passaggio dei parametri che permetta ad
un utente di inserire tutti dati di un paziente che è stato passato alla procedura;
4. imposta una procedura (prototipo) che stampa la pressione e la temperatura di un
paziente;
5. imposta una procedura (prototipo) che dato l&#39;indirizzo dell&#39;array clinica ed il numero di
pazienti che vi sono sulla lista, calcola il saldo totale della clinica;
6. imposta tutte le chiamate nel main che realizzino in sequenza i punti precedenti;
7. facoltativo: ora completa l&#39;esercizio scrivendo il codice di tutte le procedure.
*/

typedef struct {
    char nome[256];
    char cognome[256] ;
    int matricola;
    int pressione[2];
    int temp[3];
    float parcella;
} Paziente;

void addPaziente(Paziente v[]) {//funzione caricare il paziente con i suoi dati

        printf("Dammi il nome: ");//inserito nome
        scanf("%s", v[k].nome);
        printf("Dammi il cognome: ");//inserito cognome
        scanf("%s", v[k].cognome);
        printf("Dammi la matricola: ");//inserita matricola della persona
        scanf("%d", &v[k].matricola);
        printf("Dammi le pressioni(1): ");//pressione presa per la prima volta
        scanf("%d", &v[k].pressione[0]);
        printf("Dammi le pressioni(2): ");//pressione presa per la seconda volta
        scanf("%d",&v[k].pressione[1]);
        printf("Dammi le temp(1): ");//temperatura presa per la prima volta
        scanf("%d", &v[k].temp[0]);
        printf("Dammi le temp(2): ");//temperatura presa per la seconda volta
        scanf("%d",&v[k].temp[1]);
        printf("Dammi le temp(3): ");//temperatura presa per la terza volta
        scanf("%d",&v[k].temp[2]);
        printf("Dammi la parcella: ");//parcella finale
        scanf("%f", &v[k].parcella);
    }


float getSomma(Paziente v[], int n) {//somma delle parcelle finali
    float somma=0;
    for(int k=0; k< n; k++) {
        somma+=v[k].parcella;
    }
}

int main() {
    Paziente rossi;
    Paziente clinica[DIM];
    int nPazienti=2;
    addPaziente(clinica, nPazienti);//caricato paziente
    nPazienti++;
    printf("Saldo totale: %.2f", getSomma(clinica, nPazienti));

    return 0;
}
