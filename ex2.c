// Pedro Henrique Campos Dias - 1812130069
#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef LIMITS_H
#define LIMITS_H
#include <limits.h>
#endif

#define BUFFER_SIZE 16

typedef struct _array {
    char *array;
    unsigned int length;
} array;

typedef struct _node {
    char dest;
    struct _node *next;
} node;

typedef struct _list {
    array *chars;
    node **nodes;
} list;

array *get_unique_chars(char **connections) {
    array *a = malloc(sizeof(array));
    a->array = calloc(UCHAR_MAX, sizeof(char));
    int i, j, k, l = 0;
    for(i = 0; i < UCHAR_MAX; i++) a->array[i] = 0;
    for(i = 0; i < UCHAR_MAX; i++) {
        for(j = 0; j < 2; j++) {
            k = 0;
            while(a->array[k]
            && k < UCHAR_MAX) {
                if(a->array[k] == connections[i][j]) break;
                k++;
            }
            if(k < UCHAR_MAX
            && a->array[k] != connections[i][j]) {
                a->array[k] = connections[i][j];
                l++;
            }
        }
    }
    a->length = l;
    return a;
}

int get_char_index(char c, char *chars) {
    int i;
    for(i = 0; i < UCHAR_MAX; i++)
        if(chars[i] == c) return i;
    return -1;
}

node *new_node(char dest) {
    node *n = malloc(sizeof(node));
    n->dest = dest;
    n->next = NULL;
    return n;
}

void add_edge(list *g, char src, char dest) {
    int srcIndex = get_char_index(src, g->chars->array);
    int destIndex = get_char_index(dest, g->chars->array);
    
    node *n = new_node(destIndex);
    n->next = g->nodes[srcIndex];
    g->nodes[srcIndex] = n;

    n = new_node(srcIndex);
    n->next = g->nodes[destIndex];
    g->nodes[destIndex] = n;
}

list *new_list(char **connections) {
    list *g = malloc(sizeof(list));
    g->chars = get_unique_chars(connections);
    g->nodes = malloc(g->chars->length * sizeof(node*));

    int i;
    for(i = 0; i < g->chars->length; i++) g->nodes[i] = NULL;

    i = 0;
    while(connections[i][0]
        && connections[i][1]) {
        add_edge(g, connections[i][0], connections[i][1]);
        i++;
    }

    return g;
}

int main() {
    int e = -1, l = -1, t = 1;
    while(e != 0 && l != 0) {
        scanf("%d %d", &e, &l);
        if(e < 3 || e > 100 || l < e - 1 || l > e * (e - 1) / 2) return 0;
    }
}