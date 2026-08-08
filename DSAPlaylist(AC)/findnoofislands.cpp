// solution of leetcode problem no 200
class Solution {
public:
    void DFStraversal(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>& vis,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!='1' || vis[i][j]){
            return ;
        }
        vis[i][j]=true;
        DFStraversal(i,j-1,grid,vis,n,m); //left
        DFStraversal(i,j+1,grid,vis,n,m); //right
        DFStraversal(i-1,j,grid,vis,n,m); //top
        DFStraversal(i+1,j,grid,vis,n,m); //bottom
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        int islands = 0 ;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i = 0 ;i<n ;i++){
            for(int j=0 ;j<m ;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    DFStraversal(i,j,grid,vis,n,m) ;
                    islands++ ;
                }
            }
        }
        return islands;
    }
};// each time a traversal completes we mark all the parts of a component visited(hence 1 island is covered)
// TC is O(V+E)