class Solution {
public:
    bool isCycleDFS(int src,int n,vector<bool>&recPath,vector<bool>&vis,vector<vector<int>>&edges){
        recPath[src]=true;
        vis[src]=true ;

        for(int i=0;i<edges.size();i++){
            int v = edges[i][0] ;
            int u = edges[i][1] ;
            if(u==src){
                if(!vis[v]){
                    if(isCycleDFS(v,n,recPath,vis,edges)){
                        return true ;
                    }
                }else if(recPath[v]){
                    return true ;      //main line hi bhul gaya bc
                }
            }
        }
        recPath[src] = false ;
        return false ;
    }

    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false) ;
        vector<bool>recPath(n,false) ;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(isCycleDFS(i,n,recPath,vis,edges)){
                    return false ;
                }
            }
        }
        return true ;
    }
};