#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int adj_matrix[MAX_SIZE][MAX_SIZE], visited[MAX_SIZE];
int queue[MAX_SIZE], front = -1, rear = -1, top = -1, stack[MAX_SIZE];

void dfs(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for(int i=0; i<n; i++) {
        if(adj_matrix[v][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

void bfs(int v, int n) {
    visited[v] = 1;
    queue[++rear] = v;
    while(front != rear) {
        int u = queue[++front];
        printf("%d ", u);
        for(int i=0; i<n; i++) {
            if(adj_matrix[u][i] && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int choice, n, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    while(1) {
        printf("\n1. DFS\n2. BFS\n3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("DFS traversal: ");
                for(int i=0; i<n; i++) {
                    visited[i] = 0;
                }
                dfs(source, n);
                printf("\n");
                break;
            case 2:
                printf("BFS traversal: ");
                for(int i=0; i<n; i++) {
                    visited[i] = 0;
                }
                front = rear = -1;
                bfs(source, n);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
