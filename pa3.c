//Problema 1257 do URI

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *string;
    int tests, i, j, k, total=0, iter;
    string = (char*)malloc(51*sizeof(char));
    scanf("%d", &iter);
    for(k=0; k<iter; k++){
        total=0;
        scanf("%d", &tests);
        for(i=0; i<tests; i++){
            scanf("%s", string);
            for(j=0; j<strlen(string); j++){
                total = total+(int)string[j]+i-65+j;
            }
        }
        printf("%d\n", total);
    }
    return 0;
}
