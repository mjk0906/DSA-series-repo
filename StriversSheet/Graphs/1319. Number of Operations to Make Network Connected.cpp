class Solution {
public:
    void dfs(int &i,vector<vector<int>>&graph,vector<bool>&vis){
        for(auto neigh : graph[i]){
            if(!vis[neigh]){
                vis[neigh] = true ;
                dfs(neigh,graph,vis) ;
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int noofedges = connections.size() ;
        if(noofedges< n-1){
            return -1 ;
        }
        vector<vector<int>> graph(n) ;
        for(auto edge : connections){
            int u = edge[0] ;
            int v = edge[1] ;
            graph[u].push_back(v) ;
            graph[v].push_back(u) ;
        }
        vector<bool> vis(n,false) ;
        int components = 0 ;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                components++ ;
                dfs(i,graph,vis) ;
            }
        }
        return components-1 ;
    }
};
//easy problem simple approach, also can be solved using DSU