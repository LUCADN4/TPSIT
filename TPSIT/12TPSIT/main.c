#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 50
#define MIN 10
/*
Scrivere un programma che data una stringa in input dica se la stessa contiene almeno
una ‘A’ tra i primi 10 caratteri.
*/

bool controlla(char * s){//funzione controllo se nella parola presente la lettera a 
    int k = 0, n = 0;
    bool ok = false;


    while(k < MIN && ok == false){ //ciclo uscita presente una a o caratteri parola terminata
        if(*(s+k) == 'A' || *(s+k) == 'a'){//controllo presenza a nella parola
            ok = true;
        }else{
            k++;
        }
    }
    return ok;
}

int main()
{
   char * s = (char*)malloc(LUNG*sizeof(char));//caricata stringa dinamicamente

    printf("Inserisci una stringa: ");//stampa stringa
    scanf("%s",s);//scrivere la parola 

    if(controlla(s)){//verica se nella parola è presente una a o A
        printf("\nLa stringa contiene il carattere 'A' o 'a'\n");
    }else{
        printf("\nLa stringa NON contiene il carattere 'A' o 'a'\n");
    }

    printf("\n");
    return 0;
}

