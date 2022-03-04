#include <stdio.h>
#include <stdlib.h>

/*Implementare
le pile dei metodi pop() e push() utilizzando una coda con i suoi metodi
enqueue() e dequeue().*/


typedef struct nodo {
    int num;
    struct nodo * next;
} Nodo;

int denqueue(Nodo ** testa) {//funzione togliere dato
    int num=0;
    if(*testa==NULL) {
        printf("Coda Vuota!!!\n");
    } else {
        Nodo* t= *testa;
        num=t->num;
        *testa=t->next;
    }
    return num;
}

void enqueue(Nodo ** t, int num) {//funzione aggiungere data
    Nodo*tail=*t;
    if(tail==NULL) {
        tail=(Nodo*)malloc(sizeof(Nodo));
        tail->num=num;
        tail->next=NULL;
    } else {
        Nodo * n=(Nodo*)malloc(sizeof(Nodo));
        n->next=tail;
        n->num=num;
        tail=n;
    }
    *t=tail;
}


Nodo * formattaLista() {
    int n;
    printf("Quanti numeri vuole inserire: ");//inserimento degli elementi da mettere
    scanf("%d", &n);
    int num;
    Nodo * testa=NULL;
    for(int k=0; k< n; k++) {
        printf("Dammi un numero: ");//nuemro inserito
        scanf("%d", &num);
        if(testa==NULL) {
            testa=(Nodo*)malloc(sizeof(Nodo));
            testa->num=num;
            testa->next=NULL;
        } else {
            Nodo*next=testa;
            testa=(Nodo*)malloc(sizeof(Nodo));
            testa->num=num;
            testa->next=next;
        }
    }
    return testa;
}


void stampaLista(Nodo*l) {//stampa della pila
    printf("%d ",l-> num);
    if(l->next!=NULL)stampaLista(l->next);

}

void main() {
    Nodo* testa=formattaLista();
    enqueue(&testa, 12);
    enqueue(&testa, 13);
    denqueue(&testa);
    stampaLista(testa);
}
