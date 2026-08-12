class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>>q ;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        int ans = 0;
        while(q.size()>0){

            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second ;
            q.pop(); //everytime idk why are you forgetting to write this statement

            ans = max(ans,time);  //update the time

            //top 
            if(i>=1 && grid[i-1][j]==1){
                q.push({{i-1,j},time+1});  
                grid[i-1][j]=2 ;
            }
            //bottom
            if(i+1<m && grid[i+1][j]==1){
                q.push({{i+1,j},time+1});
                grid[i+1][j]=2 ;
            }
            //left
            if(j>=1 && grid[i][j-1]==1){
                q.push({{i,j-1},time+1});
                grid[i][j-1]=2 ;
            }
            //right 
            if(j+1<n && grid[i][j+1]==1){
                q.push({{i,j+1},time+1});
                grid[i][j+1]=2 ;
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1 ;
                }
            }
        }
        return ans ;
    }
}; //this is the code without using the visited array