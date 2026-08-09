class Solution {
  public:
    void helper(vector<vector<int>>&adj,int src,vector<bool>&vis,vector<int>&ans){
        vis[src]=true ;
        ans.push_back(src);
        for(int v : adj[src]){
            if(!vis[v]){
                helper(adj,v,vis,ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> ans ;
        vector<bool>vis(adj.size(),false);
        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                helper(adj,i,vis,ans);
            }
        }
        return ans ;
    }
};