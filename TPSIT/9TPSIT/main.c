#include <stdio.h>
#include <stdlib.h>
#define LUNG 50
/*
Concatenare due stringhesenza stract
*/

void fusione(char *s1, char *s2) {
    int n1 = 0, n2 = 0;

    n1 = strlen(s1);//lunghezza caratteri prima parola
    n2 = strlen(s2);//lunghezza caratteri seconda parola

    for(int k = 0; k < n2; k++) {
        *(s1+n1+k) = *(s2+k);
    }
    *(s1+n1+n2)= '\0';

}

int main() {
    //due parole allocate dinamicamente
    char *s1 = (char*)malloc(LUNG*sizeof(char));
    char *s2 = (char*)malloc(LUNG*sizeof(char));

    printf("Inserisci prima stringa:");//inserimento prima parola
    scanf("%s",s1);//scritta prima parola

    printf("Inserisci seconda stringa:");//inserita seconda parola
    scanf("%s",s2);//scritta la seconda parola

    fusione(s1,s2);//fusione delle due parole

    return 0;
}
