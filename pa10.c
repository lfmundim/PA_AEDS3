#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}
//ordenar, pegar os C ultimos, somar o valor do maior 2x
//Não foi possível com vetor dinâmico para os destinos (limite de memória do URI?), foi feito estático.

int main(){
    int tests, floors, capacity, crowd, i, j, k, energy;
    int destinations[50001], *passengers;
    scanf("%d", &tests);
    for(i=0; i<tests; i++){
        energy = 0;
        scanf("%d %d %d", &floors, &capacity, &crowd);
        // destinations = (int*)malloc(crowd* sizeof(int));
        for(j=0; j<crowd; j++)
            scanf("%d", &destinations[j]);
        qsort(destinations, crowd, sizeof(int), compare);

        passengers = (int*)malloc(capacity* sizeof(int));
        for(j=crowd-1; j>=0;){
            for(k=0; k<capacity; k++){
                passengers[k] = destinations[j];
                j--;
            }
            energy+=2*passengers[0];
        }
        printf("%d\n", energy);
        free(passengers);
        // free(destinations);
    }

    return 0;
}
