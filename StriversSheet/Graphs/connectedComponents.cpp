class Solution {
  public:
    
    void bfs(int src,vector<vector<int>>& adj,vector<bool>&vis) {
        // code here
        queue<int> q ;
        q.push(src);
        vis[src]=true ;
        while(q.size()>0){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                if(!vis[v]){
                    vis[v]=true ;
                    q.push(v);
                }
            }
        }
    }
    int countConnected(int&V,vector<vector<int>>&edges){
        vector<vector<int>> adj(V) ;
        vector<bool> vis(V,false);
        int ans = 0 ;
        for(auto edge : edges ){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int src = 0;src<V;src++){
            if(!vis[src]){
                bfs(src,adj,vis);
                ans ++ ;
            }
        }
        return ans ;
    }
};

//easy just bfs and count the unconnected sections