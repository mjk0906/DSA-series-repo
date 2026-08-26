class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> graph(n) ;
        for(auto edge : edges){
            int u = edge[0] ;
            int v = edge[1] ;
            int wt = edge[2] ;
            graph[u].push_back({v,wt}) ;
            graph[v].push_back({u,wt}) ;
        }
        int minCount = INT_MAX ;
        int ans = -1 ;
        for(int src=0;src<n;src++){
            priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq ;
            vector<int> dist(n,INT_MAX) ;
            pq.push({0,src});
            dist[src] = 0 ;
            while(pq.size()){
                auto [currDist,currNode] = pq.top() ;
                pq.pop() ;
                if(currDist > dist[currNode]){
                    continue ;
                }
                for(auto edge : graph[currNode]){
                    int v = edge.first ;
                    int wt = edge.second ;
                    int newDist = currDist+wt ;
                    if(dist[v]>newDist){
                        dist[v] = newDist ;
                        pq.push({newDist,v}) ;
                    }
                }
            }
            int count = 0 ;
            for(int i=0 ;i<n ;i++){
                if(i!=src && dist[i]<=distanceThreshold){
                    count++ ;
                }
            }
            if(count<minCount || (count==minCount && src>ans)){
                minCount = count ;
                ans = src ;
            }
        }
        return ans ;
    }
};
//LeetCode problem 
// good problem , needs deep understanding of logic , guessed the solution correctly but couldnot convert into code
//initially thought dfs but it is also dijkstras only 