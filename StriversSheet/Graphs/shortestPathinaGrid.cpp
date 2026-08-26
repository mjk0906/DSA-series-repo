class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dist(rows,vector<int>(cols,INT_MAX)) ;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq ;
        pq.push({1,{0,0}});
        dist[0][0]=1 ;
        vector<int> dr = {-1,-1,-1,0,0,1,1,1} ;
        vector<int> dc = {0,1,-1,-1,1,1,-1,0} ;
        if(grid[0][0]==1 || grid[rows-1][cols-1]==1){
            return -1 ;
        }
        while(pq.size()>0){
            auto curr = pq.top();
            int r = curr.second.first ;
            int c = curr.second.second ;
            int currDist = curr.first ;
            pq.pop();
            if(currDist!=dist[r][c]){
                continue ;
            }
            if(r==rows-1 && c==cols-1){
                return dist[r][c];
            }
            for(int i=0;i<8;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];

                if(nr>=0 && nc>=0 && nr<=rows-1 && nc<=cols-1 && grid[nr][nc]==0){
                    int newDist = currDist+1 ;
                    if(dist[nr][nc]>newDist){
                        dist[nr][nc]=newDist ;
                        pq.push({dist[nr][nc],{nr,nc}}) ;
                    }
                }
            }
        }
        return -1 ;
    }
};
//hard and good (Dijkstras)