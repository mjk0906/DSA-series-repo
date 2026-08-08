class Solution {
public:
    vector<vector<int>> createL(vector<vector<int>>& edges,int n){
        vector<vector<int>> l(n) ;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][1];
            int v = edges[i][0];
            l[u].push_back(v);
        }
        return l;
    }
    vector<int> bfs(vector<vector<int>>& edges,int n){
        vector<vector<int>> l = createL(edges,n);
        vector<int> ans ;
        vector<int> indeg(n,0);
        for(int u=0;u<n;u++){
            for(int v : l[u]){
                indeg[v]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(int v : l[curr]){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }
        return ans ;
    }
    vector<int> findOrder(int n,vector<vector<int>>& edges){
        vector<int> ans = bfs(edges,n);
        if(ans.size()==n){
            return ans;
        }else{
            return {};
        }
    }
};
//this is the solution of kahns algo used to solve leetcode210 course schedule problem 
