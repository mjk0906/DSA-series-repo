class Solution {
public:
    bool dfs(int u,int c,vector<int>&color,vector<vector<int>>&graph){

        color[u]=c ; //color[u] would be either 0 or 1 
        for(auto v : graph[u]){
            if(color[v]==-1){
                if(!dfs(v,1-color[u],color,graph)){
                    return false ;
                } ;
            }if(color[v]==c){
                return false ;
            }
        }
        return true ;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,0,color,graph)){
                    return false ;
                }
            }
        }
        return true ;
    }
};

//this is a very interesting code and with a solid approach