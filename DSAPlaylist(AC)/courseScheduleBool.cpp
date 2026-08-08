class Solution {
public:
    bool isCycleDFS(int src,vector<bool>& vis,vector<bool>& recPath,vector<vector<int>>& edges){
        vis[src]=true ;
        recPath[src]=true ;

        for(int i=0 ;i<edges.size();i++){
            int v = edges[i][0];
            int u = edges[i][1];
            
            if(u==src){
                if(!vis[v]){
                    if(isCycleDFS(v,vis,recPath,edges)){
                        return true;
                    }
                }else if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src]=false ;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<bool> recPath(n,false);
        for(int i=0 ;i<n;i++){
            if(!vis[i]){
                if(isCycleDFS(i,vis,recPath,edges)){
                    return false ;
                }
            }
        }
        return true ;
    }
};
//here we are just finding that we can complete the courses or not, so if the graph contains a cycle then topo order cannot be obtained, hence we cannot complete all the courses
//thats it no topo order return required, that is a different question      
//topological order can only be found for a directed acyclic graph structure 