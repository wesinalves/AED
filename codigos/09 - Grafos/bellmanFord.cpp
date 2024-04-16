#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int src, dest, weight;
};

struct Graph{
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E){
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void displayShortestPath(int dist[], int n){
    cout << "Vertex" << "\t" << "distance from source" << endl;
    for(int i = 0; i < n; i++)
        cout << i << "\t" << dist[i] << endl;
}

void BellmanFord(struct Graph* graph, int src){
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    // initialization
    for(int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // process relax edges
    for(int i = 0; i <= V - 1; i++){
        for(int j=0; j<E; j++){
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // detect negative weight cycles
    for(int j = 0; j < E; j++){
        int u = graph->edge[j].src;
        int v = graph->edge[j].dest;
        int weight = graph->edge[j].weight;
        if(dist[u] != INT_MAX && dist[u] + weight < dist[v]){
            cout << "Aborting. Graph contains negative weight cycle";
            return;
        }
    }

    displayShortestPath(dist, V);

    return;
}

int main(){
    int V = 5;
    int E = 10;
    struct Graph* graph = createGraph(V, E);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 6;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 7;

    graph->edge[2].src = 1;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
 
    graph->edge[3].src = 1;
    graph->edge[3].dest = 2;
    graph->edge[3].weight = 8;
 
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = -4;
 
    graph->edge[5].src = 3;
    graph->edge[5].dest = 1;
    graph->edge[5].weight = -2;
 
    graph->edge[6].src = 2;
    graph->edge[6].dest = 3;
    graph->edge[6].weight = -3;
 
    graph->edge[7].src = 2;
    graph->edge[7].dest = 4;
    graph->edge[7].weight = 9;

    graph->edge[7].src = 4;
    graph->edge[7].dest = 0;
    graph->edge[7].weight = 2;

    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = 7;

    BellmanFord(graph, 0);

    return 0;
}