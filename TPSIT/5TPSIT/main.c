#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
1.	Scrivere un programma che verifichi se la stringa data in input è palindroma o no.
*/
bool confronto(char * s) {//funzione per vedere se la parola è palindroma
    int n = 0, k = 0;

    n = strlen(s);//lunghezza caratteri parola
    int  j = n-1;
    bool ok = true;

    while (ok == true && k < n ) {
        for( k = 0; k < n; k++) {
            if(*(s+k) != *(s+j)) {
                ok = false;//parola non palindroma
            }
            j--;
        }
    }
    return ok;
}

int main() {
   char *s = (char *)malloc(LUNG *sizeof(char*));//allocazione dinamica parola

    printf("Inserisci parola:");//inserisci la parola
    scanf("%s",s);//inserita parola

    if(confronto(s)) {//confronto se la parola è palindroma
        printf("La parola %s e' palindroma",s);
    } else {
        printf("La parola %s NON e' palindroma",s);
    }

    return 0;
}
