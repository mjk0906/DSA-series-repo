class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> graph(V) ;
        vector<bool> inMST(V,false) ;
        int mstWt = 0 ;
        for(auto edge : edges){
            int u = edge[0] ;
            int v = edge[1] ;
            int wt = edge[2] ;
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt}) ;
        }
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq ;
        pq.push({0,0});
        while(pq.size()>0){
            auto curr = pq.top() ;
            int wt = curr.first ;
            int currNode = curr.second ;
            pq.pop() ;
            if(inMST[currNode]){
                continue ;
            }
            inMST[currNode] = true ;
             mstWt+=wt ;
            for(auto v : graph[currNode]){
                int next = v.first ;
                if(!inMST[next]){
                    int nextWt = v.second ;
                    pq.push({nextWt,next}) ;
                }
            }
        }
        return mstWt ;
    }
};

//easy and simple, GFG problem