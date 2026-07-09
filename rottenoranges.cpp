class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0 ;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>> q ;

        for(int i=0 ; i<n ;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=true ;
                }
            }
        }

        //bfs traversal for finding the time 
        while(q.size()>0){
            int i = q.front().first.first ;
            int j = q.front().first.second ;
            int time = q.front().second;
            q.pop();

            ans = max(time,ans);

            if(i>=1 && grid[i-1][j]==1 && !vis[i-1][j]){ //top
                q.push({{i-1,j},time+1}) ;
                vis[i-1][j]=true;
            }
            if(i+1<n && grid[i+1][j]==1 && !vis[i+1][j]){ //bottom
                q.push({{i+1,j},time+1}) ;
                vis[i+1][j]=true;
            } 
            if(j>=1 && grid[i][j-1]==1 && !vis[i][j-1]){ //left 
                q.push({{i,j-1},time+1}) ;
                vis[i][j-1]=true;
            }
            if(j+1<m && grid[i][j+1]==1 && !vis[i][j+1]){  //right
                q.push({{i,j+1},time+1}) ;
                vis[i][j+1]=true;
            }
        }
        //check for unrotten oranges
        for(int i=0; i<n ; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    return -1 ;
                }
            }
        }
        return ans ;
    }
};

//this problem can also be done without using the visited array, just make the rotten oranges 2 and solve the question

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0 ;
        queue<pair<pair<int,int>,int>> q ;

        for(int i=0 ; i<n ;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }

        //bfs traversal for finding the time 
        while(q.size()>0){
            int i = q.front().first.first ;
            int j = q.front().first.second ;
            int time = q.front().second;
            q.pop();

            ans = max(time,ans);

            if(i>=1 && grid[i-1][j]==1){ //top
                q.push({{i-1,j},time+1}) ;
                grid[i-1][j]=2;
            }
            if(i+1<n && grid[i+1][j]==1){ //bottom
                q.push({{i+1,j},time+1}) ;
                grid[i+1][j]=2;
            } 
            if(j>=1 && grid[i][j-1]==1){ //left 
                q.push({{i,j-1},time+1}) ;
                grid[i][j-1]=2;
            }
            if(j+1<m && grid[i][j+1]==1){  //right
                q.push({{i,j+1},time+1}) ;
                grid[i][j+1]=2;
            }
        }
        //check for unrotten oranges
        for(int i=0; i<n ; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    return -1 ;
                }
            }
        }
        return ans ;
    }
}; //this is the code without using the visited array
// like this above 