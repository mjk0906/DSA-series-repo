class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> graph[n] ;
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            graph[u].push_back({v,wt});
        }
        queue<pair<int,pair<int,int>>> q ; //source to that node,stops to do so
        q.push({src,{0,-1}});
        vector<int> cost(n,INT_MAX);
        cost[src]=0 ;
        while(q.size()>0){
            auto curr = q.front();
            int u = curr.first;
            int currCost = curr.second.first ;
            int currStops = curr.second.second;
            q.pop();
            for(auto edge : graph[u]){
                int v = edge.first ;
                int wt = edge.second ;
                if(cost[v]>currCost+wt && currStops+1 <= k){
                    cost[v]=currCost+wt ;
                    q.push({v,{cost[v],currStops+1}});
                }
            }
        }
        if(cost[dst]==INT_MAX) return -1 ;
        return cost[dst] ;
    }
};

//very good problem 