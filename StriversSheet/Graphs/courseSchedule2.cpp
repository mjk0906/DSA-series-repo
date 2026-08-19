class Solution {
public:
    vector<vector<int>> createAdjList(int n,vector<vector<int>>&edges){
        vector<vector<int>> adj(n) ;
        for(int i=0 ;i<edges.size();i++){
            int v = edges[i][0] ;
            int u = edges[i][1] ;
            adj[u].push_back(v);
        }
        return adj ;
    }
    //this is nothing but kahn's algo
    vector<int> bfsTopo(int n,vector<vector<int>>&edges){
        vector<int> inDeg(n,0);
        vector<vector<int>> adj = createAdjList(n,edges) ;
        vector<int> ans;

        for(int i=0;i<adj.size();i++){
            for(int j : adj[i]){
                inDeg[j]++ ;
            }
        }
        queue<int> q ;
        for(int i=0;i<n;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            ans.push_back(curr) ;
            for(int v : adj[curr]){
                inDeg[v]-- ;
                if(inDeg[v]==0){
                    q.push(v) ;
                }
            }
        }
        return ans ;
    }
    vector<int> findOrder(int n,vector<vector<int>>& edges){
        vector<int> ans = bfsTopo(n,edges) ;
        if(ans.size()==n){
            return ans ;
        }else{
            return {};
        }
    }
}; //each node gets pushed only once here, this is not a reccursive function to get stuck in loop therefore we check the size of ans, if the size is not equal to n then we cannot complete all the courses