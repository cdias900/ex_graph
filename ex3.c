// Pedro Henrique Campos Dias 1812130069
#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

int array_push(int *arr, int n, int l) {
    int i;
    for(i = 0; i < l; i++) {
        if(arr[i] == n) return 0;
        if(!arr[i]) {
            arr[i] = n;
            return 1;
        }
    }
    return 0;
}

void bfs(int **graph, int l, int p) {
    if(!p) return;
    
}

int main() {
    int c, e, l, p, i, j, x, y, t = 0;
    int **graph;
    while(1) {
        scanf("%d %d %d %d", &c, &e, &l, &p);
        if(!c && !e && !l && !p) break;
        graph = calloc(c, sizeof(int**));
        for(i = 1; i <= c; i++) {
            graph[i] = calloc(c, sizeof(int*));
        }
        for(i = 0; i < e; i++) {
            scanf("%d %d", &x, &y);
            j = 0;
            while(graph[x][j] && graph[x][j] != y) j++;
            graph[x][j] = y;
            j = 0;
            while(graph[y][j] && graph[y][j] != x) j++;
            graph[y][j] = x;
        }
        bfs(graph, l, p);
        t++;
    }
    for(i = 1; i <= c; i++) {
        printf("%d -> ", i);
        for(j = 0; j < c; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}