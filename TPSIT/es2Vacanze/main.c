#include <stdio.h>
#include <stdlib.h>
/*
Esercizio 2
Scrivere un programma che legga una sequenza di caratteri e li stampi in ordine inverso. Usa una
pila.
*/

typedef struct nodo {
    char c;
    struct nodo * next;
} Nodo;

void stampa(Nodo * l) {//stampa del nodo
    if( l != NULL) {
        stampa(l->next);
        printf("%c\n", l->c);
    }
}

Nodo * listaF() {
    int n;
    printf("Numeri da inserire: ");
    scanf("%d", &n);
    Nodo* head;
    if(n > 0) {
        head=(Nodo*)malloc(sizeof(Nodo));//testa allocata dinamicamente
    } else {
        head=NULL;
    }
    Nodo * r=head;
    Nodo * c;
    for(int k=0; k< n; k++) {
        printf("Inserisci numero cella  [%d] : ", k+1);
        fflush(stdin);
        scanf("%c", &r->c);
        c=NULL;
        if(k<n-1) {
            c= (Nodo*)malloc(sizeof(Nodo));//coda allocata dinamicamente
        }
        r->next=c;
        r=c;
    }
    return head;
}

int main() {
    Nodo * head= listaF();
    printf(" Inversa: \n");
    stampa(head);//stmapa
    return 0;
}
