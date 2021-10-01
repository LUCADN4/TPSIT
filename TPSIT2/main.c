#include <stdio.h>
#include <stdlib.h>
#define LUNG 50
#define MAX_STUDENTI 3

typedef struct{
    char nome[LUNG];
    char cognome[LUNG];
    float ita;
    float mate;
    float Info;
}Studente;

void caricaDati(Studente v[], int n){

    int k;

    for(k = 0; k < n; k++){
        printf("Inserisci nome sudente: ");
        scanf("%s", v[k].nome);
        printf("Inserisci cognome sudente: ");
        scanf("%s", v[k].cognome);
        printf("Inserisci voto Italiano: ");
        scanf("%f", &v[k].ita);
        printf("Inserisci voto Matematica: ");
        scanf("%f", &v[k].mate);
        printf("Inserisci voto Informatica: ");
        scanf("%f", &v[k].Info);
        printf("\n");
    }
}

void mediaMaggiore(Studente v[], int n){

    int k;
    float mIta, MMate, MInfo;
    float sIta, sMate, SInfo;

    sIta = 0;
    sMate = 0;
    SInfo = 0;

    for(k = 0; k < n; k++){
       sIta = sIta + v[k].ita;
       sMate = sMate + v[k].mate;
       SInfo = SInfo + v[k].Info;
    }

    mIta = sIta / n;
    MMate = sMate / n;
    MInfo = SInfo / n;

    if(mIta > MMate){
        if(mIta > MInfo){
            printf("La meteria con media piu' alta e': Italiano[%.2f]\n", mIta);
        }else{
            printf("La meteria con media piu' alta e': Informatica[%.2f]\n", MInfo);
        }
    }else if(MMate > MInfo){
        printf("La meteria con media piu' alta e': Matematica[%.2f]\n", MMate);
    }else{
        printf("La meteria con media piu' alta e': Informatica[%.2f]\n", MInfo);
    }
}
int main()
{
    Studente vett[MAX_STUDENTI];

    caricaDati(vett, MAX_STUDENTI);
    mediaMaggiore(vett, MAX_STUDENTI);

    return 0;
}
