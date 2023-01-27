#include<iostream>
#define INT_MAX 2147483647

struct Graph {
    int vertexNum;
    int** edges;
};

Graph graph = {.vertexNum = 0, .edges = NULL};

auto createGraph(int vert){
    graph.edges = new int *[vert];
    for(int i=0; i<vert; i++){
        graph.edges[i] = new int[vert];
    }
    for(int i=0; i<vert; i++){
        for(int j=0; j<vert; j++){
            graph.edges[i][j] = 0;
        }
    }
    graph.vertexNum = vert;
}

auto addEdge(int src, int dest, int weight){
    graph.edges[src][dest] = weight;
}

auto minDistance(int mdist[], bool vset[], int v) -> int {
   int minVal = INT_MAX;
   int minInd = 0;
   for(int i=0; i<v; i++){
       if(!vset[i] && (mdist[i] < minVal)){
           minVal = mdist[i];
           minInd = i;
       }
   }
   return minInd;
}

auto showDistances(int dist[], int v){
    std::string line("\n\033[1;32m----------------------------------------\033[0m\n");
    std::cout << line << " ---> Vertex distance \n\t" << std::endl;
    for(int i=0; i<v; i++){
        if(dist[i] < INT_MAX){
            std::cout << i << "\t" << dist[i] << std::endl;
        }
        else {
            std::cout << i << "\tINFINITY" << std::endl;
        }
    }
}

auto Dijkstra(const Graph& graph, int src){
    int v = graph.vertexNum;
    // store updated distances to vertex
    int mdist[v];
    // vset[i] is true if the vertex i is included
    // in the shortest path tree
    bool vset[v];

    for(int i=0; i<v; i++){
        mdist[i] = INT_MAX;
        vset[i] = false;
    }
    mdist[src] = 0;
    // iterate to find shortest path
    for(int count=0; count<v-1; count++){
        int u = minDistance(mdist, vset, v);
        vset[u] = true;
        for(int k=0; k<v; k++){
            if(!vset[k] && (graph.edges[u][k] && mdist[u] + graph.edges[u][k] < mdist[k])){
                mdist[k] = mdist[u] + graph.edges[u][k];
            }
        }
    }
    showDistances(mdist, v);
}

auto main() -> int {
   int vertices, edges, weight;
   int src, dest, graphSource;
   
   std::cout << "\n Enter the number of vertices: ";
   std::cin >> vertices;
   std::cout << "\n Enter the number of edges: ";
   std::cin >> edges;
   createGraph(vertices);
   
   for(int i = 0; i<edges; i++){
       std::cout << "\n [ Edge " << (i+1) << " ]\n\t Enter source: ";
       std::cin >> src;
       std::cout << "\n\t Enter destination: ";
       std::cin >> dest;
       std::cout << "\n\t Enter weight: ";
       std::cin >> weight;

       if(src >=0 && src < vertices && dest >= 0 && dest < vertices){
           addEdge(src, dest, weight);
       }
       else {
           std::cout << " Source and/or destination is out of bounds!" << std::endl;
           i--;
           continue;
       }
   }
   std::cout << " Now enter starting point: ";
   std::cin >> graphSource;
   Dijkstra(graph, graphSource);

  return 0;
}