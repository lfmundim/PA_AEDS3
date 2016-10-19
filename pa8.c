#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(int vertex, int vertex_count, int **graph, int *visit){
    int i, j;
    for(i=0; i<vertex_count; i++){
        visit[vertex]=1;
        if(graph[vertex][i]==1){
            // graph[vertex][i]=2;
            if(visit[i]==0){
                visit[i] = 1;
                dfs(i, vertex_count, graph, visit);
            }
        }
    }
}

int main(){
    int intersec, streets, vertex1, vertex2, ways, **graph, *visited, **transp, *visitedTransp;
    int i, j, go, goback, count;

    while(1){
        count = 0;
        go = 0;
        goback = 0;
        scanf("%d %d", &streets, &intersec);
        //condição de parada
        if(intersec==0 && streets==0)
            break;

        //aloca grafo
        graph = (int**)calloc(streets,sizeof(int*));
        for(i=0; i<streets; i++){
            graph[i] = (int*)calloc(streets,sizeof(int));
        }
        transp = (int**)calloc(streets, sizeof(int*));
        for(i=0; i<streets; i++){
            transp[i] = (int*)calloc(streets,sizeof(int));
        }
        visited = (int*)calloc(streets,sizeof(int));
        visitedTransp = (int*)calloc(streets, sizeof(int));

        //preenche grafo
        for(i=0; i<intersec; i++){
            scanf("%d %d %d", &vertex1, &vertex2, &ways);
            graph[vertex1-1][vertex2-1] = 1;
            transp[vertex2-1][vertex1-1] = 1;
            if(ways==2){
                graph[vertex2-1][vertex1-1] = 1;
                transp[vertex1-1][vertex2-1] = 1;
            }
        }

        //confere possibilidade de interconexão
        dfs(0, streets, graph, visited);
        for(i=0; i<streets; i++){
            // printf("[%d]", visited[i]);
            if(visited[i]==0){
                go = 0;
                break;
            }
            else{
                go = 1;
            }
        }
        // printf("\n");
        if(go==1){
            dfs(0, streets, transp, visitedTransp);
            for(i=0; i<streets; i++){
                if(visitedTransp[i]==0){
                    goback = 0;
                    break;
                }
                else
                    goback = 1;
            }
        }
        if(go!=1 || goback != 1)
            printf("0\n");
        else
            printf("1\n");
    }
    // printf("\n");
    return 0;
}
