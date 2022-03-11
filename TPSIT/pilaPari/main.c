//Usa una pila per l'inserimento dei dati e stampa solamente i numeri pari e li sommi stampando il risultato
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
typedef struct {
    int dim;
    int array[MAX];
} Stack;
Stack CreaStack() { //restituisce uno stack(pila) e inizializza la dimensione della pila a 0 perché non sono presenti numeri
    Stack pila;
    pila.dim = 0;
    return pila;
}
bool IsEmpty(Stack *stack) {
    return stack->dim==0;
}
bool IsFull(Stack *stack) {
    return stack->dim==MAX;
}
void push(Stack *stack, int x) { //funzione push = inserimento numeri
    if(IsFull(stack) != true) {
        stack ->array[stack->dim] = x;//mette il numero nell;ultima posizione = aggiunge al fondo il numero
        stack->dim++;//aumenta la dimensione
    } else {
        printf("Pila piena");
    }
}
int pop(Stack *stack) { //funzione push = rimuove l'ultimo numero
    int k = 0;
    if(IsEmpty(stack) != true) {
        int k = stack->array[stack->dim-1];//toglie l'ultimo elemento della pila
        stack->dim--;//diminuiscce la dimensione
    } else {
        printf("Pila vuota");
        k = NULL;
    }
    return k;
}
void stampa(Stack pila) { //stampa i numeri
    printf("Numeri pari: ");
    for(int i = 0; i < pila.dim; i++) {
        if(pila.array[i]%2 == 0)//solo i numeri pari vengono stampati
            printf("%d ",pila.array[i]);
    }
}
int sommaPari(Stack pila) { //somma solo i numeri pari
    int somma = 0;
    for(int i = 0; i < pila.dim; i++) {
        if(pila.array[i]%2 == 0)//somma solo i numeri pari
            somma += pila.array[i];
    }
    return somma;
}
int main() {
    Stack pila = CreaStack();
    int n = 0;
    int num = 0;
    do { //controlla che il numero di numeri che si vuole inserire sia corretto = non negativo
        printf("Inserisci il numero di numeri: ");
        scanf("%d",&n);
    } while(n < 0 || n > MAX);

    for(int i = 0; i < n; i++) { //inserisce i numeri
        printf("Inserisci il %d numero: ",i+1);
        scanf("%d",&num);
        push(&pila,num);
    }
    stampa(pila);//stampa la pila
    printf("\nLa somma di tutti i numeri pari e': %d",sommaPari(pila));//stampa solo i numeri pari
    return 0;
}
