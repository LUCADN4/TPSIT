#include <stdio.h>
#include <stdlib.h>
#define LUNG 50
/*
Concatenare due stringhesenza stract
*/

void fusione(char *s1, char *s2) {
    int n1 = 0, n2 = 0;

    n1 = strlen(s1);
    n2 = strlen(s2);

    for(int k = 0; k < n2; k++) {
        *(s1+n1+k) = *(s2+k);
    }
    *(s1+n1+n2)= '\0';

}

int main() {
    char *s1 = (char*)malloc(LUNG*sizeof(char));
    char *s2 = (char*)malloc(LUNG*sizeof(char));

    printf("Inserisci prima stringa:");
    scanf("%s",s1);

    printf("Inserisci seconda stringa:");
    scanf("%s",s2);

    fusione(s1,s2);

    return 0;
}
