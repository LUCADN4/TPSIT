#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct {
    int dim;
    int head;
    int num[MAX];
} Coda;
Coda CreaCoda() { //creo la cosa
    Coda coda;
    coda.dim = 0;
    coda.head = 0;
    return coda;
}
void enqueue(Coda *coda, int x) { //funzione enqueue
    coda->num[coda->dim] = x;
    coda->dim++;
}
int dequeue(Coda *coda) { //funzoine dequeue
    int num[MAX];
    int k = NULL;
    if (coda->dim == coda->head && coda->dim == 0) {
        printf("Errore coda vuota");
    } else {
        k = coda->num[coda->head];
        coda->num[coda->head] = NULL;
        //coda->head--;
        //printf("%d",k);
    }
    return k;
}
void stampa(Coda coda) { //stampa i numeri
    printf("Coda: ");
    for(int i = 0; i < coda.dim; i++) {
        if(coda.num[i] != NULL) {
            printf("%d ",coda.num[i]);
        }

    }
}
int prendiInteroPositivo() {
    int n = 0;
    do {
        printf("inserici il numero di numeri: ");
        scanf("%d",&n);
    } while(n < 0 || n > MAX);
    return n;
}
Coda inserisci() {
    Coda coda = CreaCoda();
    int num = 0;
    int dim=0;
    dim = prendiInteroPositivo();
    for(int i = 0; i < dim; i++) {
        printf("Inserisci il %d numero: ", i+1);
        scanf("%d",&num);
        enqueue(&coda,num);
    }
    return coda;
}
int main() {
    Coda coda = inserisci();
    stampa(coda);//stampa la pila
    int k = dequeue(&coda);
    stampa(coda);//stampa la pila
    return 0;
}
