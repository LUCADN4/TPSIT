#include <stdio.h>
#include <stdlib.h>

/*Scrivere una
funzione che inverta una coda, ovvero
produca degli elementi  della coda
di partenza. Suggerimento: utilizzare una pila*/

typedef struct nodo
{
    int num;
    struct nodo * next;
} Nodo;

Nodo * formattaLista(Nodo** coda)
{
    int n;
    printf("Quanti numeri vuole inserire: ");
    scanf("%d", &n);
    int num;
    Nodo * testa=NULL;
    Nodo * r=(Nodo*)malloc(sizeof(Nodo));
    Nodo * cur=testa;
    for(int k=0; k< n; k++)
    {
        printf("Dammi un numero: ");
        scanf("%d", &num);
        if(r==NULL)r=(Nodo*)malloc(sizeof(Nodo));
        r->num=num;
        if(testa==NULL)
        {
            testa= r;
            cur=r;
        }
        cur->next=r;
        cur=r;
        cur->next=NULL;
        r=NULL;
    }
    *coda=cur;
    return testa;
}

void enqueue(Nodo ** t, int num)
{
    Nodo*coda=*t;
    if(coda==NULL)
    {
        coda=(Nodo*)malloc(sizeof(Nodo));
        coda->num=num;
        coda->next=NULL;
    }
    else
    {
        coda->next=(Nodo*)malloc(sizeof(Nodo));
        coda=coda->next;
        coda->num=num;
        coda->next=NULL;
    }
    *t=coda;
}

int denqueue(Nodo ** testa)
{
    int num=0;
    if(*testa==NULL)
    {
        printf("Coda Vuota!!!\n");
    }
    else
    {
        Nodo* t= *testa;
        num=t->num;
        *testa=t->next;
    }
    return num;
}

void stampaLista(Nodo*l)
{
    if(l->next!=NULL)stampaLista(l->next);
    printf("%d ",l-> num);
}

Nodo* push(Nodo * l, int c)
{
    Nodo * n= (Nodo*)malloc(sizeof(Nodo));
    n->num=c;
    n->next=NULL;
    if(l!=NULL)
    {
        n->next=l;
    }
    return n;
}

int pop(Nodo ** l)
{
    Nodo * n= (Nodo*)malloc(sizeof(Nodo));
    n=*l;
    int num=0;
    if(*l==NULL)
    {
        printf("Non ci sono nodi nella lista!!\n");
    }
    else
    {
        num=n->num;
        n=n->next;
        *l=n;
    }
    return num;
}

Nodo* invertiCoda(Nodo ** testa)
{
    Nodo * pila=NULL;
    Nodo*t=*testa;
    while(t!=NULL)
    {
        pila=push(pila,denqueue(&t));
    }
    while(pila!=NULL){
        if(t==NULL){
          enqueue(&t,pop(&pila));
          *testa=t;
        }
        enqueue(&t,pop(&pila));
    }
    return t;

}

int main()
{
    Nodo* coda=NULL;
    Nodo* testa=formattaLista(&coda);
    stampaLista(testa);
    printf("Coda invertita: ");
    coda=invertiCoda(&testa);
    stampaLista(testa);
    denqueue(&testa);
    printf("\n");

}
