class Solution {
public:
    void travel(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&vis){
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0 || vis[i][j]==true){
            return ;
        }
        vis[i][j]=true ;

        travel(grid,i+1,j,vis) ;
        travel(grid,i-1,j,vis) ;
        travel(grid,i,j+1,vis) ;
        travel(grid,i,j-1,vis) ;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0 ;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        //traversal from borders
        for(int i=0;i<m;i++){
            travel(grid,i,0,vis);
            travel(grid,i,n-1,vis);
        }
        for(int j=0;j<n;j++){
            travel(grid,0,j,vis);
            travel(grid,m-1,j,vis);
        }

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans++;
                }
            }
        }
        return ans ;
    }
};

//this is traversal from borders 