#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define LUNG 100
/*
1.	Scrivere un programma che verifichi se la stringa data in input è palindroma o no.
*/
bool confronto(char s[]) {
    int n = 0, k = 0;

    n = strlen(s);
    int  j = n-1;
    bool continua = true;

    while (continua == true && k < n ) {
        for( k = 0; k < n; k++) {
            if(s[k] != s[j]) {
                continua = false;
            }
            j--;
        }
    }
    return continua;
}

int main() {
    char s[LUNG];

    printf("Inserisci parola:");
    fflush(stdin);
    gets(s);

    if(confronto(s) == true) {
        printf("La parola %s e' palindroma",s);
    } else {
        printf("La parola %s NON e' palindroma",s);
    }




    return 0;
}
