#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 50
/*
Scrivere un programma che data una stringa in input dica se la stessa contiene almeno
una ‘A’ tra i primi 10 caratteri.
*/

bool controlla(char s[], int n){ //funzione controllo se all'interno della parola sono presenti i caratteri a o A
    int k = 0;
    bool ok = false;

    while(k < n && ok == false){
        if(s[k] == 'A' || s[k] == 'a'){
            ok = true;//presenza del carattere
        }else{
            k++;
        }
    }
    return ok;
}

int main()
{
    char s[LUNG];//dimensione massima del carattere
    int n = 10;//controllo se nei primi 10 caratteri presente la a o A

    printf("Inserisci una stringa: ");//insetita la stringa
    fflush(stdin);
    gets(s);//inserita la parola

    if(controlla(s, n)){//controllo presenza di a o A
        printf("\nLa stringa contiene il carattere 'A' o 'a'\n");
    }else{
        printf("\nLa stringa NON contiene il carattere 'A' o 'a'\n");
    }

    printf("\n");
    return 0;
}

