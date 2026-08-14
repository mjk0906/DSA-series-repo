class Solution {
  public:
    bool dfs(int i,vector<bool>&inPath,vector<bool>&vis , vector<vector<int>>&adj){
       vis[i]=true;
       inPath[i]=true ;
       for(auto v : adj[i]){
           if(!vis[v]){
               if(dfs(v,inPath,vis,adj)){
                   return true ;
               }
           }
           else if(inPath[v]){
               return true ;
           }
       }
       inPath[i]=false ;
       return false ;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<bool>inPath(V,false);
        vector<bool>vis(V,false);
        vector<vector<int>> adj(V) ;
        for(auto edge : edges){
            int i = edge[0] ;
            int v = edge[1] ;
            adj[i].push_back(v) ;
        }
        int par = -1 ;
        for(int i=0;i<V;i++){
            if(dfs(i,inPath,vis,adj)){
                return true ;
            }
        }
        return false ;
    }
};