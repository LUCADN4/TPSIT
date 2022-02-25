#include <stdio.h>
#include <stdlib.h>
/*
Es 1
Sia data una struttura dati dinamica di tipo lista semplicemente concatenata.
Ogni nodo della lista contiene un numero intero come valore.  Si scriva la funzione che, dato un vettore di
N numeri interi, restituisce la lista contenente gli N elementi del vettore;
l’elemento di indice 0 va in testa alla lista, ecc.
*/

typedef struct node { //struttura dati dinamica
    struct node *next;
    int num;
} Node;

Node *createNode(int val,Node *nodo) {
    Node *succ=(Node*) malloc(sizeof(Node));
    /*
    if(succ==NULL) {
        printf("Errore di allocazione");
        //non essenziale;
        exit(1);
    }
    */
    if(nodo != NULL) nodo->next=succ; //nodo == NULL non stampa nulla perche nel main
    succ->num=val;
    succ->next=NULL;
    return succ;
}

int main() {
    int array[]= {1,2,3,4,5,6};

    Node *head=NULL; //testa
    Node *cur=NULL; // coda

    for(int i=0; i<6; i++) {
        cur=createNode(array[i],cur);
        if(head==NULL) head=cur; // porta haed sempre a null e  non stampa nulla
    }

    cur=head;
    while(cur != NULL) {
        printf("%d\n",cur->num);
        cur=cur->next;
}

    printf("\n");
    return 0;
}
