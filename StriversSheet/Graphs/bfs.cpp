class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int> ans ;
        int V = adj.size();
        vector<bool> vis(V,false);
        queue<int> q ;
        q.push(0);
        vis[0]=true ;
        while(q.size()>0){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(int v : adj[u]){
                if(!vis[v]){
                    vis[v]=true ;
                    q.push(v);
                }
            }
        }
        return ans ;
    }
};