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
    void dfsTopo(int curr,vector<bool> &vis,vector<vector<int>>& edges,stack<int>& s){
        vis[curr]=true;
        for(int i=0;i<edges.size();i++){
            int v = edges[i][0];
            int u = edges[i][1];
            if(u==curr){
                if(!vis[v]){
                dfsTopo(v,vis,edges,s);
                }
            }
        }
        s.push(curr);
    }
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<bool> recPath(n,false);
        vector<int> ans ;
        stack<int> s ;

        for(int i=0 ;i<vis.size();i++){
            if(!vis[i]){
                if(isCycleDFS(i,vis,recPath,edges)){
                    return ans;
                }
            }
        }
        
        fill(vis.begin(), vis.end(), false);

        for(int i=0 ;i<vis.size();i++){
            if(!vis[i]){
                dfsTopo(i,vis,edges,s);
            }
        }
        while(s.size()>0){
            int curr = s.top();
            s.pop();
            ans.push_back(curr);
        }
        return ans ;
    }
};
//here we return the topological order of completion of courses