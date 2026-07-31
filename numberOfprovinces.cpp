class Solution {
public:
    void dfs(int i,vector<vector<int>>&adj,vector<bool>& vis){

        vis[i]=true;
        for(int j=0;j<adj.size();j++){
            if(!vis[j] && adj[i][j]==1){
                dfs(j,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0 ;
        vector<bool> vis(isConnected.size(),false);
        for(int i=0 ;i<isConnected.size();i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                ans++;
            }
        }
        return ans ;
    }
}; //simple dfs code TC is O(n^2) 
//do this by union find(DSU) approach also