class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> dist(rows,vector<int>(cols,INT_MAX));

        int src = heights[0][0];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq ;

        pq.push({0,{0,0}});
        dist[0][0]=0 ;

        vector<int> dr = {-1,1,0,0};
        vector<int> dc = {0,0,-1,1};
        while(!pq.empty()){
            auto effort = pq.top().first;
            int r = pq.top().second.first ;
            int c = pq.top().second.second ;
            pq.pop();

            if(effort!=dist[r][c]){ //already covered node 
                continue ;
            }
            if(r==rows-1 && c==cols-1){
                return dist[r][c] ;
            }
            for(int i=0;i<4;i++){

                int nr = r+dr[i];
                int nc = c+dc[i];

                if(nr>=0 && nc>=0 && nr<rows && nc<cols){
                    int currentheight = abs(heights[r][c]-heights[nr][nc]);

                    int neweffort = max(currentheight,effort);

                    if(neweffort<dist[nr][nc]){
                        dist[nr][nc]=neweffort ;
                        pq.push({neweffort,{nr,nc}});
                    }
                }
            }
        }
        return 0 ;
    }
};
//very important question for graph perfection 