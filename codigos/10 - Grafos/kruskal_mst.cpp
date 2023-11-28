#include <bits/stdc++.h> 
using namespace std;

class DSU{
    int* parent;
    int* rank;
    public:
    DSU(int n){
        parent = new int[n];
        rank = new int[n];

        for(int i=0; i<n; i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    // find set
    int find(int i){
        if(parent[i] == -1)
            return i;
        
        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y){
        int s1 = find(x);
        int s2 = find(y);

        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                parent[s1] = s2;
            }else if(rank[s1] > rank[s2]){
                parent[s2] = s1;
            }else{
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }

};

class Graph{
    vector<vector<int>> edgeList;
    int V;
    public:
    Graph(int V){
        this->V = V;
    }
    void addEdge(int u, int v, int w){
        edgeList.push_back({w, u, v});
    }

    void kruskal_mst(){
        sort(edgeList.begin(), edgeList.end());
        // Initialize the DSU
        DSU A(V); // mst initial
        int ans = 0; // weight summation
        cout << "following are the edges in the constructed MST" << endl;
        for(auto edge: edgeList){
            int w = edge[0];
            int u = edge[1];
            int v = edge[2];

            // take the edge if not forms a cycle
            if(A.find(u) != A.find(v)){
                A.unite(u, v);
                ans += w;
                cout << u << " -> " << v << " : " << w << endl;
            }
        }
        cout << "Minimum Cost Spanning Tree: " << ans << endl;
    }
};

int main(){
    Graph g(9);
    g.addEdge(1,2,4);
    g.addEdge(1,8,8);
    g.addEdge(2,3,8);
    g.addEdge(2,8,11);
    g.addEdge(3,4,7);
    g.addEdge(3,9,2);
    g.addEdge(3,6,4);
    g.addEdge(4,5,9);
    g.addEdge(4,6,14);
    g.addEdge(5,6,10);
    g.addEdge(6,7,2);
    g.addEdge(7,8,1);
    g.addEdge(7,9,6);
    g.addEdge(8,9,7);

    g.kruskal_mst();

    return 0;

}