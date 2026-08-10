class Solution {
  public:
    bool isCyclehelper(int& V,int src,vector<vector<int>>&adj,vector<bool>&vis){
        //code here
        queue<pair<int,int>> q ; //as node,parent form 
        vis[src]=true;
        q.push({src,-1});
        while(q.size()>0){
            int par = q.front().second;
            int curr = q.front().first;
            q.pop();
            for(int v : adj[curr]){
                if(!vis[v]){
                    vis[v]=true ;
                    q.push({v,curr});
                }else if(vis[v]==true && v!=par){
                    return true ;
                }
            }
        }
        return false ;
    }
    
    bool isCycle(int&V,vector<vector<int>>&edges){
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(V,false) ;
        for(int src=0;src<V;src++){
            if(!vis[src]){
                if(isCyclehelper(V,src,adj,vis)){
                    return true;
                }
            }
        }
        return false ;
    }
};