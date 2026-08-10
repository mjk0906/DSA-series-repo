class Solution {
  public:
    bool isCyclehelper(int src,int par,vector<vector<int>>&adj,vector<bool>&vis){
        //code here
        vis[src]=true ;
        for(auto v : adj[src]){
            if(!vis[v]){
                if(isCyclehelper(v,src,adj,vis)){
                    return true;
                };
            }else if(v!=par){
                return true;
            }
        }
        return false ;
    }
    bool isCycle(int&V,vector<vector<int>>&edges){
        vector<bool>vis(V,false);
        vector<vector<int>> adj(V) ;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int src = 0 ;src<V;src++){
            if(!vis[src]){
                if(isCyclehelper(src,-1,adj,vis)){
                    return true ;
                };
            }
        }
        return false;
    }
};

//go through multiple times, needs focus