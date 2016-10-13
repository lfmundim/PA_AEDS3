//Problema 2049 do URI

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int search(char *signature, char *pannel){
    char *aux, *aux2;
    unsigned int i, j=0, size;
    aux = (char*)calloc(strlen(signature),sizeof(char));
    aux2 = (char*)calloc(strlen(signature),sizeof(char));
    size = strlen(pannel);
    strcpy(aux2, signature);
    while(1){
        for(i=0; i<strlen(signature); i++){
            aux[i]=pannel[j+i];
        }
        if(strcmp(aux, aux2)==0){
            free(aux);
            free(aux2);
            return TRUE;
        }
        else if(strlen(signature)>size || j+1>strlen(pannel))
            break;
        j++;
    }
    j=0;
    free(aux);
    free(aux2);
    return FALSE;
}

int main(){
    int instance=1, end;
    char *signature, *pannel;
    signature = (char*)malloc(9*sizeof(char));
    pannel = (char*)calloc(300001,sizeof(char));

    while(1){
        scanf("%s", signature);
        end = atoi(signature);
        if(end==0) break;
        if(instance>1)printf("\n");
        scanf("%s", pannel);
        printf("Instancia %d\n", instance++);
        if(search(signature, pannel)==TRUE)
            printf("verdadeira\n");
        else
            printf("falsa\n");
    }

    free(signature);
    free(pannel);
    return 0;
}
