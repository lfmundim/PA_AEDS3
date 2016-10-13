#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int m, n, count=0, i, j, digits, *num, aux;

    while((scanf("%d %d", &m, &n))!=EOF){
	//scanf("%d %d", &m, &n);

	for(i=m; i<=n; i++){
		digits = log10((float)i)+1;
		num = (int*)calloc(digits, sizeof(int));
		aux = i;
		for(j=0; j<digits; j++){
			num[j] = aux%10;
			aux /= 10;
		}
		if(digits==1)
			count++;
		else if(digits==2){
			if(num[0]!=num[1])
				count++;
		}
		else if(digits==3){
			if(num[0]!=num[1] && num[0]!=num[2] && num[1]!=num[2])
				count++;
		}
		else if(digits==4){
			if(num[0]!=num[1] && num[0]!=num[2] && num[0]!=num[3] && num[1]!=num[2] && num[1]!=num[3] && num[2]!=num[3])
				count++;
		}
		free(num);
	}
	//if(m==0) count++;
	printf("%d\n", count);
	count = 0;
    }
	return 0;
}
