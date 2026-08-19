class Solution{
public:
    void dfs(int curr,vector<bool>&vis,vector<vector<int>>&adj,stack<int>&s){
        vis[curr]=true ;
        for(int v : adj[curr]){
            if(!vis[v]){
                dfs(v,vis,adj,s) ;
            }
        }
        s.push(curr) ;
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        stack<int> s ;
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v) ;
        }
        vector<int> ans ;
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,s) ;
            }
        }
        while(s.size()>0){
            int curr = s.top();
            s.pop();
            ans.push_back(curr) ;
        }
        return ans ;
    }
};