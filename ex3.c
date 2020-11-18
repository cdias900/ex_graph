// Pedro Henrique Campos Dias 1812130069
#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

typedef struct _test{
    int *res;
    int c;
    int l;
}test;

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

void sort_array(int *arr, int length) {
    int i, j;
    int aux;
    for(i = 1; i < length; i++) {
        aux = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > aux) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = aux;
    }
}

void dfs(int **graph, int *res, int c, int l, int p) {
    if(p < 0 || !array_push(res, l, c)) return;
    int i;
    for(i = 0; i < c; i++) {
        if(graph[l][i]) dfs(graph, res, c, graph[l][i], p - 1);
    }
}

test new_test(int *res, int c, int l) {
    test *t = malloc(sizeof(test));
    t->res = res;
    t->c = c;
    t->l = l;
    return *t;
}

int main() {
    test tests[100];
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
        int *res = calloc(c, sizeof(int));
        dfs(graph, res, c, l, p);
        sort_array(res, c);
        tests[t] = new_test(res, c, l);
        t++;
    }
    for(i = 0; i < t; i++) {
        printf("Teste %d\n", i + 1);
        for(j = 0; j < tests[i].c; j++) {
            if(tests[i].res[j] && tests[i].res[j] != tests[i].l) {
                printf("%d ", tests[i].res[j]);
            }
        }
        printf("\n\n");
    }
}