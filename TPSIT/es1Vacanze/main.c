#include <stdio.h>
#include <stdlib.h>
/*
Esercizio pila
Considerate una sequenza di interi letti da input e definite una funzione C che li
stampa
in modo tale che tutti i pari precedano i dispari, nello stesso ordine in cui vengono
letti.
Ad esempio, se la sequenza è:
1 , 20 , 35 , 40 , 62 , 51 , 66
La stampa che si vuole ottenere e&#39;
20 , 40 , 62 , 66 , 1 , 35 , 51
*/
typedef struct nodo {
    int num;
    struct nodo * next;
} Nodo;

void modificaLista(Nodo * l) {
    Nodo * head=l;
    while(l!=NULL) {
        if(l->num % 2 ==0)printf("%d\n", l->num);
        l=l-> next;
    }
    l=head;
    while(l!=NULL) {
        if(l->num % 2 !=0)printf("%d\n", l->num);
        l=l-> next;
    }
}

Nodo * listaF() {
    int n;
    printf("Numeri da inserire:");
    scanf("%d", &n);
    Nodo* head;
    if(n> 0) {
        head=(Nodo*)malloc(sizeof(Nodo));
    } else {
        head=NULL;
    }
    Nodo* r=head;
    Nodo* c;
    for(int k=0; k< n; k++) {
        printf("Inserisci numero cella  [%d] : ", k+1);
        scanf("%d", &r->num);
        c=NULL;
        if(k < n-1) {
            c= (Nodo*)malloc(sizeof(Nodo));
        }
        r->next=c;
        r=c;
    }
    return head;
}

void stampaLista(Nodo * l) {
    if(l!=NULL) {
        printf("%d\n", l->num);
        stampaLista(l->next);
    }
}



int main() {
    Nodo * head= listaF();
    printf("Stampa Lista: \n");
    stampaLista(head);
    printf("Stampa Lista modificata: \n");
    modificaLista(head);
    return 0;
}
