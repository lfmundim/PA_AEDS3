#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, *mag, sentido=0, i, peaks;

    while (1) {
        peaks=0;
        scanf("%d", &n);
        if(n==0) break;
        mag = (int*)malloc(n*sizeof(int));
        for(i=0; i<n; i++){
            scanf("%d", &mag[i]);
        }
        for(i=0; i<n; i++){
            if(i==0){
                if(mag[i]>mag[i+1]){
                    if(mag[i]<mag[n-1])
                        sentido=-1;
                    else{
                        sentido=-1;
                        peaks++;
                    }
                }
                else if(mag[i]<mag[i+1]){
                    if(mag[i]>mag[n-1])
                        sentido=1;
                    else{
                        sentido=1;
                        peaks++;
                    }
                }
            }

            else if(i>0 && i<n-1){
                if(mag[i]>mag[i+1] && sentido!=-1){
                    sentido=-1;
                    peaks++;
                }
                else if(mag[i]<mag[i+1] && sentido!=1){
                    sentido=1;
                    peaks++;
                }
            }

            else if(i==n-1){
                if(mag[i]>mag[0] && sentido!=-1){
                    sentido=-1;
                    peaks++;
                }
                else if(mag[i]<mag[0] && sentido!=1){
                    sentido=1;
                    peaks++;
                }
            }
            // printf("PEAKS: %d\n", peaks);

        }
        printf("%d\n", peaks);
        free(mag);
    }

    return 0;
}
