#include <iostream>
#include <vector> 
using namespace std ;

class Graph {
public:
    vector<vector<int>> adj;
    int V;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    void toposort(int curr, vector<bool>&vis,stack<int>&s){
        vis[curr]=true;
        for(auto v : adj[curr]){
            if(!vis[v]){
                toposort(v,vis,s);
            }
        }
        s.push(curr);
    }
    void dfs(int curr,vector<bool>&vis,vector<vector<int>>&transpose){
        vis[curr]=true;
        cout<< curr <<" " ;
        for(auto v : transpose[curr]){
            if(!vis[v]){
                dfs(v,vis,transpose);
            }
        }
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void kosaraju() {
        //step 1 is topological order => O(V+E)
        stack<int> s;
        vector<bool> vis(V,false) ;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                toposort(i,vis,s);
            }
        }

        //step 2 is to transpose the graph => O(V+E)
        vector<vector<int>> transpose(V);
        for(int u=0;u<V;u++){
            vis[u]=false;
            for(int v : adj[u]){
                transpose[v].push_back(u);
            }
        }

        //step 3 is dfs on transpose in the topo order => O(V+E)
        while(s.size()>0){
            int curr = s.top();
            s.pop();
            if(!vis[curr]){
                dfs(curr,vis,transpose);
                cout<<endl;
            }
        }
    }
};

int main() {

    Graph graph(5);

    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 0);
    graph.addEdge(2, 1);
    graph.addEdge(3, 4);

    graph.kosaraju();

    return 0;
}
//same tc as all dfs,topo etc 
// one of the most optimal approaches