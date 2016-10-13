//Problema 1632 URI

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    unsigned int tests, i, j, *count, *answer;
    char *password;
    password = (char*)calloc(17,sizeof(char));
    count = (unsigned int*)calloc(17,sizeof(unsigned int));

    scanf("%d", &tests);
    //getchar();
    answer = (unsigned int*)calloc(tests, sizeof(unsigned int));

    for(i=0; i<tests; i++){
        //fgets(password, 17, stdin);
        scanf("%s", password);
        for(j=0; j<17; j++)
            count[j]=0;
        answer[i]=1;
        for(j=0; j<strlen(password); j++)
            password[j] = toupper(password[j]);
        for(j=0; j<strlen(password); j++){
            if(password[j]=='A' || password[j]=='E' || password[j]=='I' || password[j]=='O' || password[j]=='S') count[j]=3;
            else if(password[j]=='\0' || password[j]=='\n') count[j]=0;
            else count[j]=2;
        }
        for(j=0; j<17; j++){
            if(count[j]!=0)
                answer[i]=answer[i]*count[j];
        }

    }
    for(i=0; i<tests; i++){
        printf("%d\n", answer[i]);
    }
    free(password);
    free(count);
    free(answer);

    return 0;
}
