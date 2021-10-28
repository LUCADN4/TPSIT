#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LUNG 50

bool Palindroma(char *s) {
    int n = 0, k = 0;
    bool ok = true;

    n = strlen(s);

    while(k < n/2 && ok == true) {
        if(*(s+k) != *(s+(n-1-k))) {
            ok = false;
            k++;
        }
    }
    return ok;
}

int main() {

    char * stringa=(char *)malloc (LUNG *sizeof (char*));
    printf("inserisci parola: ");
    scanf("%s", stringa);

    if(Palindroma(stringa) == true) {
        printf("Stringa palindroma\n");
    } else {
        printf("Stringa NON palindroma\n");
    }
    return 0;
}
