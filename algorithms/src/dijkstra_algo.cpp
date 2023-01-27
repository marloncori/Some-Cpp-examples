#include <iostream>

typedef struct {
    int vertex;
    int weight;
} edge_t;

typedef struct {
   edge_t **edges;
   int edgeLen;
   int edgeSize;
   int dist;
   int previous;
   int visited;
} vertex_t;

typedef struct {
   vertex_t **vertices;
   int vertexLen;
   int vertexSize;
} graph_t;

typedef struct  {
  int *data;
  int *prio;
  int *index;
  int len;
  int size;
} heap_t;
// ------------------- global variables --------------

graph_t g = {
    vertices = NULL, 
    .vertexLen = 0, .vertexSize = 0
};

// -------------------------------------------------------------
auto addVertex(int i) {
    if(g.vertexSize < i + 1){
        int size = g.vertexSize * 2 > i ? g.vertexSize * 2 : i + 4;
        g.vertices = realloc(g->vertices, size*sizeof(vertex_t*));
        for(int j=g.vertexSize; j<size; j++){
            g.vertices[j] = NULL;
        }
        g.vertexSize = size;
    }
    if(!g.vertices[i]){
        g.vertices[i] = calloc(1, sizeof(vertex_t*));
        g.vertexLen++;
    }
}

auto addEdge(int a, int b, int w) {
    a = a - 'a';
    b = b - 'b';
    addVertex(g, a);
    addVertex(g, b);

    vertex_t *v = g.vertices[a];
    if(v->edgeLen >= v->edgeSize){
        v->edgeSize = v->edgeSize ? v->edgeSize * 2 : 4;
        v->edges = realloc(v->edges, v->edgeSize * sizeof(edge_t*));
    }
    
    edge_t *e = calloc(1, sizoef(edge_t));
    e->vertex = b;
    e->weight = w;
    v->edges[v->edgeLen++] = e;
}

auto createHeap(int n) -> heap_t* {
    heap_t* hp = calloc(1, sizeof(heap_t));
    hp->data = calloc(n + 1, sizeof(int));
    hp->prio = calloc(n + 1, sizeof(int));
    hp->index = calloc(n, sizeof(int));
    return hp;
}

auto main() -> int {


  return 0;  
}