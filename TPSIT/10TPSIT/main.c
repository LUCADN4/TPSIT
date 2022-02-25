#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define LUNG 100
/*
1.	Scrivere un programma che verifichi se la stringa data in input è palindroma o no.
*/
bool confronto(char * s) {
    int n = 0, k = 0;

    n = strlen(s);
    int  j = n-1;
    bool ok = true;

    while (ok == true && k < n ) {//controllo uscita finite lettere parola
        for( k = 0; k < n; k++) {
            if(*(s+k) != *(s+j)) {//
                ok = false;
            }
            j--;
        }
    }
    return ok;//ritorno booleano per vedere se è palindromo o no
}

int main() {
   char *s = (char *)malloc(LUNG *sizeof(char*));//allocazione dinamica

    printf("Inserisci parola:");//parola da inserire
    scanf("%s",s);//inserita parola

    if(confronto(s)) {//conrollo della funzione per vedere se la parola è palindroma
        printf("La parola %s e' palindroma",s);
    } else {
        printf("La parola %s NON e' palindroma",s);
    }

    return 0;
}
