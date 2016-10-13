#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, *genome, i, inv, a, b, j, aux, cons, k=1, size;

	while(1){
		scanf("%d", &n);
		if(n==0){
			break;
		}
		genome = (int*)malloc(n*sizeof(int)); // 0 a n-1
		for(i=0; i<n; i++)
			genome[i] = i+1;
		scanf("%d", &inv);

		for(i=0; i<inv; i++){
			scanf("%d %d", &a, &b);
			size = (b-a)/2;
			aux = genome[a-1];
			genome[a-1] = genome[b-1];
			genome[b-1] = aux;
			for(j=1; j<=size; j++){
				aux = genome[a+j-1];
				genome[a+j-1] = genome[b-j-1];
				genome[b-j-1] = aux;
			}
		}
		scanf("%d", &cons);
		printf("Genome %d\n", k++);
		for(i=0; i<cons; i++){
			scanf("%d", &a);
			for(j=0; j<n; j++){
				if(genome[j]==a){
					printf("%d\n",j+1);
					break;
				}
			}
		}
	}
	return 0;
}
