#include <stdio.h>
#include <stdlib.h>
/*
Scrivere un programma che permette all’utente di inizializzare un array unidimensionale
di float e facendo uso dell’aritmetica dei puntatori:
- individui gli elementi con valore ripetuti
-sommi i numeri rimasti
*/

int chiediDim() {
    int val;
    do {
        printf("Inserire la dimensione del Vettore: ");
        scanf("%d", &val);
    } while(val <= 0);

    return val;
}



int noNd(int vett[], int n,int x) {
    int nx,k;

    nx = 0;
    for(k = 0; k < n; k++) {
        if(x == vett[k]) {
            nx++;
        }

    }
    return nx;
}

int controllo(int v[], int n) {
    int nx = 0;
    int j = 0;
    for(int k = 0; k < n; k++) {
        for(int j = 0; j < n; j++) {
            if(v[k] == v[j]) {
                nx = noNd(v,n,v[j]);
            }

        }
        if(nx >= 2 && v[k-1] != v[k]) printf("\nIl numero %d e' stato trovato : %d volte",v[k],nx);

    }
}

void caricaVettore(int v[],int n) {
    int k;

    for(k = 0; k < n; k++) {
        printf("Inserire nella cella [%d]: ",k);
        scanf("%d",&v[k]);
    }
}

int main() {
    int n = chiediDim();
    float* v1 = (float*)malloc(n*sizeof(float));

    caricaVettore(v1,n);
    //controllo(v1,n);

    for(int k = 0; k < n; k++) {
        printf("%d",v1[k]);
    }


    return 0;
}
