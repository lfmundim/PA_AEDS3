#include <stdio.h>
#include <stdlib.h>

void dfs(int vertex, int vertex_count, int **graph, int depth, int *visit){
    int i, j, count=0;
    for(i=0; i<vertex_count; i++){
        if(graph[vertex][i]==0)
            count++;
    }
    for(i=0; i<vertex_count; i++){
        visit[vertex]=1;
        if(graph[vertex][i]==1){
            for(j=0; j<depth; j++)
                printf("  ");
            graph[vertex][i]=2;
            if(visit[i]==0){
                visit[i] = 1;
                printf("%d-%d pathR(G,%d)\n", vertex, i, i);
                dfs(i, vertex_count, graph, depth+1, visit);
            }
            else{
                printf("%d-%d\n", vertex, i);
            }
        }
    }
}

int main(){
    int cases, vertex, edges, i, j, k, **graph, a, b, count=0, size, *visit, **graphaux, *neighbour;
    scanf("%d", &cases);
    for(i=0; i<cases; i++){
        scanf("%d %d", &vertex, &edges);

        //aloca
        graph = (int**)calloc(vertex, sizeof(int*));
        for(j=0; j<vertex; j++){
            graph[j] = (int*)calloc(vertex, sizeof(int));
        }
        graphaux = (int**)calloc(vertex,sizeof(int*));
        for(j=0; j<vertex; j++)
            graphaux[j] = (int*)calloc(vertex, sizeof(int));
        visit = (int*)calloc(vertex,sizeof(int));
        neighbour = (int*)calloc(vertex,sizeof(int));


        //preenche matriz das arestas do grafo
        for(j=0; j<edges; j++){
            scanf("%d %d", &a, &b);
            graph[a][b] = 1;
        }

        for(j=0; j<vertex; j++){
            for(k=0; k<vertex; k++){
                if(graph[j][k]==1)
                    neighbour[j] = 1;
            }
        }

        printf("Caso %d:\n", i+1);
        for(j=0; j<vertex; j++){
            if(neighbour[j]==1 && visit[j]==0){
                dfs(j,vertex,graph,1, visit);
                printf("\n");
            }
        }

    }

    return 0;
}
