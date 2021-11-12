#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 50
/*
Scrivere un programma che data una stringa in input dica se la stessa contiene almeno
una ‘A’ tra i primi 10 caratteri.
*/

bool controlla(char s[], int n){
    int k = 0;
    bool ok = false;

    while(k < n && ok == false){
        if(s[k] == 'A' || s[k] == 'a'){
            ok = true;
        }else{
            k++;
        }
    }
    return ok;
}

int main()
{
    char s[LUNG];
    int n = 10;

    printf("Inserisci una stringa: ");
    fflush(stdin);
    gets(s);

    if(controlla(s, n)){
        printf("\nLa stringa contiene il carattere 'A' o 'a'\n");
    }else{
        printf("\nLa stringa NON contiene il carattere 'A' o 'a'\n");
    }

    printf("\n");
    return 0;
}

