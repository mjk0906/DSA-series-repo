class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m,vector<int>(n,-1));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    ans[i][j]=0 ;
                }
            }
        }
        while(q.size()>0){
            int dist = q.front().second;
            int i = q.front().first.first ;
            int j = q.front().first.second ;
            q.pop();

            if(i>=1 && ans[i-1][j]==-1){ //top
                ans[i-1][j]=dist+1 ;
                q.push({{i-1,j},dist+1});
            }
            if(i+1<n && ans[i+1][j]==-1){ //bottom
                ans[i+1][j]=dist+1 ;
                q.push({{i+1,j},dist+1});
            } 
            if(j>=1 && ans[i][j-1]==-1){//left 
                ans[i][j-1]=dist+1 ;
                q.push({{i,j-1},dist+1});
            }
            if(j+1<m && ans[i][j+1]==-1){  //right
                ans[i][j+1]=dist+1 ;
                q.push({{i,j+1},dist+1});
            } 
        }
        return ans ;
    }
};

//interesting approach, just changing the bfs traversal on 0s from 1s made the problem like butter