class Solution {
public:

    int time ;
    vector<int> low,dt;
    void dfs(int u,int parU,vector<vector<int>>&adj,vector<bool>&vis,vector<vector<int>>&cc){
        vis[u]=true ;
        dt[u]=low[u]= ++time;

        for(int i=0 ;i<adj[u].size();i++){
            int v = adj[u][i];
            if(!vis[v]){
                dfs(v,u,adj,vis,cc);
                low[u]=min(low[u],low[v]);
                
                if(low[v]>dt[u]){
                    cc.push_back({u,v});
                }
            }else if(v!=parU){
                low[u]=min(low[u],dt[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        time = 0;
        low.resize(n);
        dt.resize(n);
        vector<vector<int>> bridges;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,adj,vis,bridges);
            }
        }
        return bridges;
    }
};

//hardest algorithm I have ever witnessed, learn is carefully and it is one of the most important algos for dsa