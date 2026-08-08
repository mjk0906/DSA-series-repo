class Solution {
public:
    int manDist(vector<vector<int>>& points,int p1,int p2){
        return (abs(points[p1][0]-points[p2][0])+abs(points[p1][1]-points[p2][1]));
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<bool> inMST(points.size(),false);
        int n = points.size();
        priority_queue < pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq ;
        int cost = 0 ;
        pq.push({0,0});

        while(pq.size()>0){
            auto p = pq.top();
            int edgeWt = p.first ;
            int node = p.second ;
            pq.pop();

            if(inMST[node]) continue ;

            inMST[node] = true;
            cost+=edgeWt ;
            for(int i=0;i<n;i++){
                int dist = manDist(points,i,node) ;
                pq.push({dist,i});
            }
        }
        return cost;
    }
}; //solved using prims algo which is the most handling
//O(n^2log(N)) is the time complexity 